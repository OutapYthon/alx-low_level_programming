#include "main.h"

/**
 * read_textfile - reads an actual text file and prints the letters
 * @filename: filename.
 * @letters: numbers of actual letters printed.
 *
 * Return: numbers of letters printed. once it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fb;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	fb = open(filename, O_RDONLY);

	if (fb == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(fb, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(fb);

	free(buf);

	return (nwr);
}
