# HOWTO 01
## Step 1 - Read the file

Let's start this HOWTO by simply reading the file that contains the 2D matrix. The name of the file is defined by the first argument when calling our program:

	./count_island example1.txt

A 2D matrix is a sequence of points delimited in rows and columns. Each byte of the file represents one point of the matrix, except the '\n' that delimits the rows:

	.........\n
	...XXX...\n
	...XXX...\n
	.........EOF

After opening the file and making sure that there is no error, we choose to read the file one byte at a time, with a buffer size of 1, in order to parse its content in live.

```c
#define BUFF_SIZE 1

int         main(int argc, char **argv)
{
	int     fd;
	ssize_t size;
	char    buf[BUFF_SIZE];

	// Check if any filename is set
	if (argc != 2)
		return (0);

	// Open the file with read-only mode
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);

	// Read one byte at a time with a buffer size of 1
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (size == -1)
			return (0);

		// Verify if the byte is valid
		if (buf[0] != '.' && buf[0] != 'X' && buf[0] != '\n')
		{
			close(fd);
			return (0);
		}

		// Here, parse the file in live...
	}

	// Close the file
	close(fd);
}
```