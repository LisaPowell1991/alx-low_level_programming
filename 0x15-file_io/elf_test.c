#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void close_elf(int fd);
Elf64_Ehdr* read_elf_header(const char* filename);
void print_elf_header(const Elf64_Ehdr* header, const char* filename);
void check_elf(const unsigned char* e_ident);
void print_field(const char* field_name, int value);

void close_elf(int fd)
{
    if (close(fd) == -1)
    {
        fprintf(stderr, "Error: Can't close file descriptor %d\n", fd);
        exit(1);
    }
}

Elf64_Ehdr* read_elf_header(const char* filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Can't read file %s\n", filename);
        exit(1);
    }

    struct stat st;
    if (fstat(fd, &st) == -1)
    {
        fprintf(stderr, "Error: Can't get file size\n");
        close_elf(fd);
        exit(1);
    }

    Elf64_Ehdr* header = malloc(st.st_size);
    if (header == NULL)
    {
        fprintf(stderr, "Error: Can't allocate memory\n");
        close_elf(fd);
        exit(1);
    }

    ssize_t bytes_read = read(fd, header, st.st_size);
    if (bytes_read == -1)
    {
        fprintf(stderr, "Error: `%s`: No such file\n", filename);
        free(header);
        close_elf(fd);
        exit(1);
    }

    close_elf(fd);
    return header;
}

void print_elf_header(const Elf64_Ehdr* header, const char* filename)
{
    printf("ELF Header: %s\n", filename);
    check_elf(header->e_ident);
    print_field("Magic", *(unsigned int*)header->e_ident);
    print_field("Class", header->e_ident[EI_CLASS]);
    print_field("Data", header->e_ident[EI_DATA]);
    print_field("Version", header->e_ident[EI_VERSION]);
    print_field("OS/ABI", header->e_ident[EI_OSABI]);
    print_field("ABI Version", header->e_ident[EI_ABIVERSION]);
    print_field("Type", header->e_type);
    print_field("Entry point address", header->e_entry);
}

void check_elf(const unsigned char* e_ident)
{
    if (e_ident[0] != 0x7f || e_ident[1] != 'E' || e_ident[2] != 'L' || e_ident[3] != 'F')
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(1);
    }
}

void print_field(const char* field_name, int value)
{
    printf("  %-19s %d\n", field_name, value);
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s elf_file\n", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        Elf64_Ehdr* header = read_elf_header(argv[i]);
        print_elf_header(header, argv[i]);
        free(header);
    }

    return 0;
}

