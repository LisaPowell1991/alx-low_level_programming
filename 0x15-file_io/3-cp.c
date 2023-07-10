#include "main.h"

/**
 * main - Copies the content of a file to another
 * @argc: Number of arguments
 * @argv: Array of arguments.
 *
 * Return: 0 if successful
 */

int main(int argc, char *argv[])
{
	int input_fd, output_fd, num_bytes_read, num_bytes_written;
	char buffer[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	input_fd = open(argv[1], O_RDONLY);

	if (input_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	output_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (output_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(input_fd);
		exit(99);
	}

	while ((num_bytes_read = read(input_fd, buffer, BUFSIZ)) > 0)
	{
		num_bytes_written = write(output_fd, buffer, num_bytes_read);

		if (num_bytes_written != num_bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(input_fd);
			close(output_fd);
			exit(99);
		}
	}

	if (num_bytes_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(input_fd) < 0 || close(output_fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(100);
	}
	return (0);
}
