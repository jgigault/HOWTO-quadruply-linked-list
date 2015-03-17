# HOWTO 01
## Step 4 - Fill islands

Each island must be filled with an index between 0 and 9. The index is incremented in the following order: First from the left to the right, and then from the top to the bottom:

	[img]

Let's start by declaring a function create_islands() that will browse the map in the proper order. Primary, set a loop that browses each point of the first row:

```c
void				create_islands(t_point *pt)
{
	t_point         *current_pt;

	// Get a reference to the first point of the map and start the loop
	current_pt = pt;
	while (current_pt)
	{
		// Get a reference to the next point
		current_pt = current_pt->right;
	}
}
```

Secondary, include this loop in another loop that browses each row of the map:

```c
void				create_islands(t_point *pt)
{
	t_point         *current_row;
	t_point         *current_pt;

	// Get a reference to the first point of the map and start the loop
	current_row = pt;
	while (current_row)
	{
		// Change this line and get, for each row, a reference to the first point and start the loop
		current_pt = current_row;
		while (current_pt)
		{
			current_pt = current_pt->right;
		}

		// Get a reference to the next row
		current_row = current_row->bottom;
	}
}
```

Every point of the map is now reached by *current_pt. Let's check if we encounter the character 'X'. When it appears, call a function fill_island() that will replace all 'X' of the current island with the new index, and then incremente the index and continue the loop:

```c
void				create_islands(t_point *pt)
{
	t_point         *current_row;
	t_point         *current_pt;
	char            index;

	index = 0;      // Initialize the index

	current_row = pt;
	while (current_row)
	{
		current_pt = current_row;
		while (current_pt)
		{
			// Check if 'X' is encountered
			if (current_pt->value == 'X')
			{
				// Replace all 'X' of the current island by the current index
				fill_island(current_pt, index);

				// Incremente the index
				index++;
			}
			current_pt = current_pt->right;
		}
		current_row = current_row->bottom;
	}
}
```

Finally, let's declare the function called fill_island() that takes two arguments: A pointer to the first point that was reached on the island and an index. This function will be called recursively for each *top, *right, *bottom and *left directions of *current_pt:

```c
function				fill_island(t_point *current_pt, char index)
{
	// Replace 'X' with the ASCII value of the index
	current_pt->value = index + 48;

	// Check the four directions and don't call recursively when:
	// 1. A pointer is NULL, that means we've reached the borderline of the map
	// 2. Value is not 'X', that means we've already replaced the value or this is water!

	if (current_pt->top != NULL && current_pt->top->value == 'X')
		fill_island(current_pt->top, index);
	if (current_pt->right != NULL && current_pt->right->value == 'X')
		fill_island(current_pt->right, index);
	if (current_pt->bottom != NULL && current_pt->bottom->value == 'X')
		fill_island(current_pt->bottom, index);
	if (current_pt->left != NULL && current_pt->left->value == 'X')
		fill_island(current_pt->left, index);
}
```

***

### Next step: Display map

-> [Step 5 - Display map](https://github.com/jgigault/HOWTO-quadruply-linked-list/blob/master/README_STEP5.md)