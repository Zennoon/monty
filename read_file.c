#include "monty.h"

/**
 * check_fd - Checks if the file descriptor given by open is valid,
 * exits if not
 * @fd: The file descriptor to check
 * @filename: The name of file that open attempted
 *
 * Return: void
 */
void check_fd(int fd, char *filename)
{
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * read_file_content - reads files content in to a buffer
 * @filename: name of file
 *
 * Return: buffer containing file content
 */
char *read_file_content(char *filename)
{
	int fd = open(filename, O_RDONLY);
	struct stat filestat;
	char *buffer;
	size_t total_bytes_read = 0;

	check_fd(fd, filename);
	if (fstat(fd, &filestat) == -1)
	{
		close(fd);
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(filestat.st_size + 1);
	if (buffer == NULL)
	{
		close(fd);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while ((long int) total_bytes_read < filestat.st_size)
	{
		size_t new_read_bytes = read(fd, buffer + total_bytes_read,
				filestat.st_size - total_bytes_read);

		if ((int) new_read_bytes == -1)
		{
			free(buffer);
			close(fd);
			dprintf(2, "Error: Can't open file %s\n", filename);
			return (NULL);
		}
		total_bytes_read += new_read_bytes;
	}
	buffer[total_bytes_read] = '\0';
	close(fd);
	return (buffer);
}

/**
 * parse_lines - parses buffer and returns array of lines
 * @buffer: buffer to parse
 * @line_count: variable to store line count
 *
 * Return: array of lines
 */
char **parse_lines(char *buffer, size_t *line_count)
{
	char **parsed_lines = _strtok(buffer, "\n\0");
	int i = 0;

	while (parsed_lines[i])
	{
		(*line_count)++;
		i++;
	}
	free(buffer);
	return (parsed_lines);
}
/**
 * execute_from_file - executes command from file line by line
 * @av: argument vector
 * @ev: env
 *
 * Return: execution statis
 */
/**int read_file(char **av, char **ev)
{
	size_t line_count = 0;
	char *buffer;
	char **lines;
	int i, status = 0;

	buffer = read_file_content(av[1]);
	if (!buffer)
	{
		return (0);
	}
	lines = parse_lines(buffer, &line_count);
	return (0);
}
**/
