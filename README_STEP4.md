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










We have a loop that generates each point of the map, one at a time, but each one is immediatly replaced by the next one during the next iteration. So we need to save temporarily a reference to the preceding point in order to link it with the current one. We will get, as a first step, a simple doubly linked list that will represent a single row of the 2D matrix.

Declare a second pointer to struct called *prev_left that will represent the point we have initialized during the previous iteration:

```c
t_point                *pt;
t_point                *prev_left;

pt = NULL;
prev_left = NULL;      // [1] Initialize it as NULL

THE_LOOP
{
	if (buf[0] == '\n')
	{
		// [5] At the end of a line, we re-initialize it as NULL (see below)
		prev_left = NULL;
	}
	else
	{
		pt = howto01_init_point(buf[0]);

		// [2] Set the left side of the current point as a pointer to the previous point
		pt->left = prev_left;

		// [3] If the previous point does exist, set its right side as a pointer to the current point
		if (prev_left)
			prev_left->right = pt;

		// [3] Finally, set the current point as the previous, in order to use it during the next iteration
		prev_left = pt;
	}
}
```

At first iteration, the pointer *prev_left is NULL [1] so that the left side of the first point *pt [2] remains as NULL and does represent the left borderline of the map. Before entering the next iteration [4], *prev_left saves a reference to the current point so that *pt and *prev_left can be linked together [2 & 3]. And so on until reaching the end of line. When a '\n' is encountered, we know that we have to initialize a new row of the map, and *prev_left should once again represent the left borderline of the map, so we set it as NULL [5].

For each row of the map, we obtain a doubly linked list, but each list is immediatly replaced by the next one during the next sequence of iterations (between two encountered '\n'). Then we need to save temporarily a reference to the preceding row of the map in order to link each point of the twice lists together by both *top and *bottom sides.

Declare a third pointer to struct called *prev_top that will represent, for each current point *pt, the nearest point from the top direction:

```c
t_point                *pt;
t_point                *prev_left;
t_point                *prev_top;

pt = NULL;
prev_left = NULL;
prev_top = NULL;       // [1] Initialize it as NULL

THE_LOOP
{
	if (buf[0] == '\n')
	{
		prev_left = NULL;

		// [5] Rewind the current doubly linked list *pt
		if (pt)
			while (pt->left)
				pt = pt->left;

		// [6] Then save a reference to *pt so that *prev_top reprensents the first point of the preceding row
		prev_top = pt;
	}
	else
	{
		pt = howto01_init_point(buf[0]);
		pt->left = prev_left;
		if (prev_left)
			prev_left->right = pt;
		prev_left = pt;

		// [2] Set the top side of the current point
		pt->top = prev_top;

		// [3] If the previous point does exist, set its bottom side as a pointer to the current point
		if (prev_top)
			prev_top->bottom = pt;

		// [4] Set *prev_top as a reference to the next point of the preceding row
		if (prev_top)
			prev_top = prev_top->right;
	}
}
```

During the first sequence of iteration until the first '\n' is encountered, *prev_top is NULL [1] so that the top side of the current *pt [2] remains as NULL and does represent the top borderline of the map. Before entering the next sequence of iterations, *prev_top saves a reference to the first point of the current row by rewinding the doubly linked list *pt [5] and saving its reference [6]. Then, *pt and *prev_top can be linked together [2 & 3]. Finally, *prev_top must get a reference to the next point of the preceding row [4] so that *pt (current row) and *prev_top (preceding row) effectively match together with both *top and *bottom sides.

That's all! We have a beautiful quadruply linked list :-)

After the loop has terminated, *pt is a reference to one point of the last row of the map. If there is no '\n' at the end of file, *pt is the bottom right corner of the map, otherwise *pt is the bottom left corner because the last byte of the file ('\n') made us rewind the current row [5]. In order to safely retrieve the beggining of the quadruply linked list (the top left corner), add a doubly rewind loop with both *left and *top directions:


```c
THE_LOOP
{
	...
}

if (pt)
{
	// Rewind to the left borderline
	while (pt->left)
		pt = pt->left;

	// Rewind to the top borderline
	while (pt->top)
		pt = pt->top;
}
```