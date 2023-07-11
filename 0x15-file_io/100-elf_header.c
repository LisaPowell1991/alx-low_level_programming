#include "main.h"

/**
 * display_error - Displays an error message
 * and exits with status code 98
 * @message: The error message to display
 *
 * Return: void
 */
void display_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * read_elf_header - Reads the ELF header from a file descriptor
 * @fd: The file descriptor
 * @header: Pointer to the Elf64_Ehdr structure to store the header
 */

void read_elf_header(int fd, Elf64_Ehdr *header)
{
	if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		display_error("Failed to read the ELF header");
}

/**
 * print_magic - Prints the magic bytes of the ELF header
 * @header: Pointer to the Elf64_Ehdr structure
 */

void print_magic(const Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:                            ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
}

/**
 * print_class - Prints the class of the ELF header
 * @header: Pointer to the Elf64_Ehdr structure
 */

void print_class(const Elf64_Ehdr *header)
{
	 printf("  Class:  %s\n",
			 (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
}

/**
 * print_data - Prints the data encoding of the ELF header
 * @header: Pointer to the Elf64_Ehdr structure
 */

void print_data(const Elf64_Ehdr *header)
{
	printf("  Version:                              %d (current)\n",
			header->e_ident[EI_VERSION]);
}

/**
 * print_os_abi - Prints the OS/ABI of the ELF header
 * @header: Pointer to the Elf64_Ehdr structure
 */

void print_os_abi(const Elf64_Ehdr *header)
{
	printf("  OS/ABI:                              ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
				break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
				break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
				break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
				break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
				break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
				break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
				break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
				break;
		case ELFOSABI_ARM:
			printf("UNIX - ARM architecture\n");
				break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
				break;
		default:
			printf("<unknown>\n");
				break;
	}
}

/**
 * print_abi_version - Prints the ABI version of the ELF header
 * @header: Pointer to the Elf64_Ehdr structure
 */

void print_abi_version(const Elf64_Ehdr *header)
{
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of the ELF header
 * @header: Pointer to the Elf64_Ehdr structure
 */

void print_type(const Elf64_Ehdr *header)
{
	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("Unknown\n");
				break;
		case ET_REL:
			printf("Relocatable file\n");
				break;
		case ET_EXEC:
			printf("Executable file\n");
				break;
		case ET_DYN:
			printf("Shared object file\n");
				break;
		case ET_CORE:
			printf("Core file\n");
				break;
		default:
			printf("<unknown>\n");
				break;
	}
}
/**
 * print_entry_point - Prints the entry point address of the ELF header
 * @header: Pointer to the Elf64_Ehdr structure
 */

void print_entry_point(const Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	print_magic(header);
	print_class(header);
	print_data(header);
	print_abi_version(header);
	print_os_abi(header);
	print_abi_version(header);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, non-zero on failure
 */

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		display_error("Failed to open the file");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		display_error("Failed to seek to the beginning of the file");

	read_elf_header(fd, &header);

	if (lseek(fd, 0, SEEK_SET) == -1)
		display_error("Failed to seek to te beginning og the file");

	print_entry_point(&header);

	close(fd);

	return (0);
}
