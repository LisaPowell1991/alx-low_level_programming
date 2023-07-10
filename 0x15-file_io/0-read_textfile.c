#include "main.h"

/**
 * read_textfile - Reads a text file and prints it
 * to the POSIX standard output
 * @filename: Pointer to the file to read
 * @letters: Num of letters to read and print
 *
 * Return: The actual num of letters read and printed,
 * or 0 if file cannot be opened or read,
 * or if the write fails or doesn't write the
 * expected amount of bytes
 * or if the filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t num_bytes_read, num_bytes_written;
	char *buffer;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (!buffer)
	{
		close(fd);
		return (0);
	}

	num_bytes_read = read(fd, buffer, letters);
	num_bytes_written = write(STDOUT_FILENO, buffer, num_bytes_read);

	close(fd);
	free(buffer);

	return (num_bytes_written);
}
