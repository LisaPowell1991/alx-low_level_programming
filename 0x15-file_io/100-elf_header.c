#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints an error message to stderr
 * and exits with status code 98
 * @message: The error message to be displayed
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * read_elf_header - Reads the ELF header from the specified file
 * @filename: The name of the file to read the ELF header from
 * @header: A pointer to the Elf64_Ehdr struct to store the header
 */
void read_elf_header(const char *filename, Elf64_Ehdr *header)
{
	ssize_t bytes_read;
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		print_error("Failed to open the file.");

	bytes_read = read(fd, header, sizeof(Elf64_Ehdr));

	if (bytes_read != sizeof(Elf64_Ehdr))
		print_error("Failed to read ELF header.");

	close(fd);
}
/**
 * validate_elf_header - Validates if the given
 * header corresponds to an ELF file
 * @header: A pointer to the Elf64_Ehdr struct
 * representing the ELF header
 */
void validate_elf_header(const Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0
			|| header->e_ident[EI_MAG1] != ELFMAG1 ||
			header->e_ident[EI_MAG2] != ELFMAG2 ||
			header->e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file.");
}
/**
 * print_elf_header - Prints the information contained in the ELF header
 * @header: A pointer to the Elf64_Ehdr struct representing the ELF header
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\nClass:   %s\n",
			header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data:    %s\n",
			header->e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d (current)\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI:  %s\n",
			header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Others");
	printf("ABI Version: %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("Type:    0x%04x\n",
			header->e_type);
	printf("Entry point address: 0x%lx\n",
			header->e_entry);
}
/**
 * process_elf_header - Processes the ELF header of the specified file
 * @filename: The name of the file to process the ELF header from
 */
void process_elf_header(const char *filename)
{
	Elf64_Ehdr header;

	read_elf_header(filename, &header);
	validate_elf_header(&header);
	print_elf_header(&header);
}
/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	const char *filename;

	if (argc != 2)
		print_error("Invalid number of arguments.");
	filename = argv[1];
	process_elf_header(filename);

	return (0);
}
