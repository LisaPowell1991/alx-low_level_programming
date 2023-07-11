#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <elf.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

/*3-cp.c*/
void displayUsageError(void);
void copyFile(const char *source, const char *destination);

/*100-elf_header.c*/
void display_error(const char *message);
void read_elf_header(int fd, Elf64_Ehdr *header);
void print_magic(const Elf64_Ehdr *header);
void print_class(const Elf64_Ehdr *header);
void print_data(const Elf64_Ehdr *header);
void print_version(const Elf64_Ehdr *header);
void print_os_abi(const Elf64_Ehdr *header);
void print_abi_version(const Elf64_Ehdr *header);
void print_type(const Elf64_Ehdr *header);
void print_entry_point(const Elf64_Ehdr *header);
void print_elf_header(const Elf64_Ehdr *header);

#endif /* MAIN_H */
