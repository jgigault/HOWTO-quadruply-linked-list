# HOWTO 01
## Step 1 - Read the file

Let's start this HOWTO by simply reading the file that contains the 2D matrix. The name of the file is defined with the first argument when calling our program.

	./count_island example1.txt

A 2D matrix is a sequence of points delimited in rows and columns. Each byte of the file represents one point of the matrix, except the '\n' that delimits the rows.

	.........\n
	...XXX...\n
	...XXX...\n
	.........EOF

After opening the file and make sure that there is no error, we