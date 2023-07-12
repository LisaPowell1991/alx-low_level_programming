#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_header_info(unsigned char *e_ident, const char *label, const char **values, int size);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit with status code EXIT_FAILURE.
 */
void check_elf(unsigned char *e_ident)
{
	if (!(e_ident[EI_MAG0] == ELFMAG0 && e_ident[EI_MAG1] == ELFMAG1 &&
	      e_ident[EI_MAG2] == ELFMAG2 && e_ident[EI_MAG3] == ELFMAG3))
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_header_info - Prints the header information of an ELF header.
 * @e_ident: A pointer to an array containing the ELF identification header.
 * @label: The label to display for the header information.
 * @values: An array of strings containing the possible values for the header information.
 * @size: The size of the values array.
 */
void print_header_info(unsigned char *e_ident, const char *label, const char **values, int size)
{
	int value_index = e_ident[size];

	printf("  %s: ", label);

	if (value_index < size)
		printf("%s\n", values[value_index]);
	else
		printf("<unknown: %x>\n", value_index);
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF identification header.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit with status code EXIT_FAILURE.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", elf);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Displays the information contained in the ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 1 on failure.
 *
 * Description: If the file is not an ELF file or the function fails - exit with status code EXIT_FAILURE.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;
	const char *class_values;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		fprintf(stderr, "Error: `%s`: No such file\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);

	class_values[] = {"none", "ELF32", "ELF64"};
	print_header_info(header->e_ident, "Class", class_values, ELFCLASSNUM);

	const char *data_values[] = {"none", "2's complement, little endian", "2's complement, big endian"};
	print_header_info(header->e_ident, "Data", data_values, ELFDATANUM);

	printf("  Version:                           %d", header->e_ident[EI_VERSION]);
	switch (header->e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}

	const char *osabi_values[] = {"UNIX - System V", "UNIX - HP-UX", "UNIX - NetBSD",
								 "UNIX - Linux", "UNIX - Solaris", "UNIX - IRIX",
								 "UNIX - FreeBSD", "UNIX - TRU64", "ARM", "Standalone App"};
	print_header_info(header->e_ident, "OS/ABI", osabi_values, ELFOSABI_ARM);

	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

	const char *type_values[] = {"NONE (None)", "REL (Relocatable file)", "EXEC (Executable file)",
								 "DYN (Shared object file)", "CORE (Core file)"};
	print_header_info(header->e_type, "Type", type_values, ET_NUM);

	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return 0;
}
