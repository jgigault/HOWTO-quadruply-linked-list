# HOWTO 01
## Step 5 - Display map

Let's declare a function display_map() that browses the map in the same order than create_islands() does, and print each value on standard output:

```c
void				display_map(t_point *pt)
{
	t_point         *current_row;
	t_point         *current_pt;

	current_row = pt;
	while (current_row)
	{
		current_pt = current_row;
		while (current_pt)
		{
			// Write each value on standard output
			write(1, &current_row->value, 1);

			current_pt = current_pt->right;
		}
		
		// Write a '\n' at the end of each row
		write(1, "\n", 1);

		current_row = current_row->bottom;
	}
}
```

We done it!

To get a successful project, you must add some checkpoints that will stop the program if an error occurs (more than 1024 points by row, different number of points by row, empties map, invalid characters, more than 10 islands...).