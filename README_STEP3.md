# HOWTO 01
## Step 3 - Link the points together

We have a loop that generates each point of the map, one at a time, but each one is immediatly replaced by the next one during the next iteration. So we need to save temporarily a reference to the preceding point in order to link it with the current one. We will get, as a first step, a simple doubly linked list that will represent a single row of the 2D matrix.

Declare a second pointer to struct called *prev_left that will represent the point we have initialized during the previous iteration:

```c
t_point                *pt;
t_point                *prev_left;

pt = NULL;
prev_left = NULL;      // ((A)) Initialize it as NULL

THE_LOOP
{
	if (buf[0] == '\n')
	{
		// ((C)) At the end of a line, we re-initialize it as NULL (see below)
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

		// ((B)) Finally, set the current point as the previous, in order to use it during the next iteration
		prev_left = pt;
	}
}
```

At first iteration, the pointer *prev_left is NULL ((A)) so that the left side of the first point *pt remains as NULL and does represent the left borderline of the map. Before entering the next iteration ((B)), *prev_left saves a reference to the current point so that we will be able to link together with the next point *pt. And so on until reaching the end of line. When a '\n' is encountered, we know that we have to initialize a new row of the map, and *prev_left should once again represent the left borderline of the map, so we set it as NULL ((C)).

For each row of the map, we obtain a doubly linked list, but each list is immediatly replaced by the next one during the next sequence of iterations (between two encountered '\n'). Then we need to save temporarily a reference to the preceding row of the map in order to link each point of the twice lists together by both *top and *bottom sides.

Declare a third pointer to struct called *prev_top that will represent, for each current point *pt, the nearest point from the top direction:

```c
t_point                *pt;
t_point                *prev_left;
t_point                *prev_top;

pt = NULL;
prev_left = NULL;
prev_top = NULL;       // Initialize it as NULL

THE_LOOP
{
	if (buf[0] == '\n')
	{
		prev_left = NULL;

		// Each row is read from left to right, so we want *prev_top to be a pointer to the leftmost point
		// First, rewind the current doubly linked list (because *pt is presently the rightmost point of the current row)
		if (pt)
			while (pt->left)
				pt = pt->left;

		// Then save this reference so that *prev_top will reprensent the first point of the preceding row
		prev_top = pt;
	}
	else
	{
		pt = howto01_init_point(buf[0]);
		pt->left = prev_left;
		if (prev_left)
			prev_left->right = pt;
		prev_left = pt;

		// Set the top side of the current point as a pointer to the nearest point from the top
		pt->top = prev_top;

		// If the previous point does exist, set its bottom side as a pointer to the current point
		if (prev_top)
			prev_top->bottom = pt;

		// Finally, set the pointer *prev_top as a reference to the next point of the preceding row
		// During the next iteration, this point will effectively be the nearest point from the top
		if (prev_top)
			prev_top = prev_top->right;
	}
}
```
