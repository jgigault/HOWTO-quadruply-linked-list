# HOWTO 01
## Step 3 - Link the points together

We have a loop that generates each point of the map, one at a time, but each one is immediatly replaced by the next one during the next iteration. So we need to save temporarily a reference to the preceding point in order to link it with the current one. We will get, as a first step, a simple doubly linked list that will represent a single row of the 2D matrix.

Declare a second pointer to struct called *prev_left that will represent the point we have set during the previous iteration:

```c
t_point                *pt;
t_point                *prev_left;

pt = NULL;
prev_left = NULL;      // Initialize it as NULL

THE_LOOP
{
	if (buf[0] == '\n')
	{
		// At the end of a line, we re-initialize it as NULL (see below)
		prev_left = NULL;
	}
	else
	{
		pt = howto01_init_point(buf[0]);

		// Set the left side of the current point as a pointer to the previous point
		pt->left = prev_left;

		// If the previous point does exist, set its right side as a pointer to the current point
		if (prev_left)
			prev_left->right = pt;

		// Finally, set the current point as the previous, in order to use it during the next iteration
		prev_left = pt;
	}
}
```

At first iteration, the pointer *prev_left is NULL so that the left side of the first point *pt remains as NULL and represent the left borderline of the map. Before entering the next iteration, *prev_left saves a reference to the current point so that we can link it with the next one at the next iteration. And so on until the end a the line is reached. When a '\n' is encountered, we know that we have to initialize a new row of the map, and *prev_left should once again represent the left borderline of the map, so we set it as NULL.

We obtain a doubly linked list for each row of the map, but each list is immediatly replaced by the next one during the next sequence of iteration (between two encountered '\n'). Then we need to save temporarily a reference to the preceding row of the map in order to link each point of the twice lists together (top and bottom sides).

