#include "main.h"

#define BUFFER_SIZE 1024

/**
 * displayUsageError - Displays an error message for incorrect command usage
 */
void displayUsageError(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * copyFile - Copies the content of one file to another
 * @source: Name of the source file
 * @destination: Name of the destination file
 */
void copyFile(const char *source, const char *destination)
{
	int input_fd, output_fd;
	ssize_t num_bytes_read, num_bytes_written;
	char buffer[BUFSIZ];

	input_fd = open(source, O_RDONLY);
	if (input_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		exit(98);
	}
	output_fd = open(destination, O_WRONLY | O_TRUNC | O_CREAT, 0664);

	if (output_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
		exit(99);
	}
	while ((num_bytes_read = read(input_fd, buffer, BUFSIZ)) > 0)
	{
		num_bytes_written = write(output_fd, buffer, num_bytes_read);
		if (num_bytes_written != num_bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
			close(input_fd);
			close(output_fd);
			exit(99);
		}
	}
	if (num_bytes_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		close(input_fd);
		close(output_fd);
		exit(98);
	}
	if (close(input_fd) < -1 || close(output_fd) < -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(100);
		free(buffer);
	}
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
