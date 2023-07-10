#include "main.h"

/**
 * displayUsageError - Displays an error message
 * Return: void
 */

void displayUsageError(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * displayReadError - Displays an error message 
 * for file read failure
 * @filename: Name of the file that couldn't be read
 * Return: void
 */

void displayReadError(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * displayWriteError - Displays an error message 
 * for file write failure
 * @filename: Name of the file that couldn't be written
 * Return: void
 */

void displayWriteError(const char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
}

/**
 * displayCloseError - Displays an error message 
 * for file close failure
 * Return: void
 */

void displayCloseError(void)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd\n");
	exit(100);
}

/**
 * copy_file - Copies the content of one file to another.
 * @source_file: The name of the source file.
 * @destination_file: The name of the destination file.
 * Return: void
 */

void copy_file(const char *source_file, const char *destination_file)
{
	int input_fd, output_fd;
	ssize_t num_bytes_read, num_bytes_written;
	char buffer[BUFFER_SIZE];

	input_fd = open(source_file, O_RDONLY);
	if (input_fd < 0)
		displayReadError(source);

	output_fd = open(destination_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (output_fd < 0)
	{
		close(input_fd);
		displayWriteError(destination);
	}

	while ((num_bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0)
	{
		num_bytes_written = write(output_fd, buffer, num_bytes_read);
		if (num_bytes_written != num_bytes_read)
		{
			close(input_fd);
			close(output_fd);
			displayWriteError(destination);
		}
	}

	if (num_bytes_read < 0)
	{
		close(input_fd);
		displayReadError(source);
	}

	if (close(input_fd) < 0 || close(output_fd) < 0)
		displayCloseError();
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, other values on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		displayUsageError();

	copyFile(argv[1], argv[2]);

	return (0);
}
