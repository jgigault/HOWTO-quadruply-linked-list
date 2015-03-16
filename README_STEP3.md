# HOWTO 01
## Step 3 - Link the points together

We have a loop that generates each point of the map, one at a time, but each one is immediatly replaced by the next one during the next iteration. So we need to save temporarily the preceding point in order to link them together. We will get, as a first step, a simple doubly linked list that will represent a single row of the map.

First, declare a second pointer to struct called *prev_left that will represent the nearest point on the left side.

```c
t_point                *pt;
t_point                *prev_left;

pt = NULL;
prev_left = NULL;      // Initialize it as NULL

THE_LOOP
{
	if (buf[0] == '\n')
	{
		// '\n' is not a point! It is a row delimiter
		// Let's do something here at step 3...
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
