# HOWTO 01
## Step 2 - Initialize the structure

A linked list is a data structure consisting of a sequence of structure type elements. Each struct element contains one or more pointers to one or more other elements of the list. In a quadruply linked list intended to represent a 2D matrix, each struct element contains 4 pointers representing the 4 sides of a virtual square (top, right, bottom, left) and squares that are linked together define the matrice. In order to define the borderlines of the 2D matrix, pointers that are next to a limit are set to NULL:

	[image]

Let's start by declaring the structure called s_point with 5 members: One char corresponding with the land type of the point (water '.' or land 'X') and 4 pointers to each direction (*top, *right, *bottom and *left):

```c
typedef struct         s_point
{
	char               value;
	struct s_point     *top;
	struct s_point     *right;
	struct s_point     *bottom;
	struct s_point     *left;
}                      t_point;
```

Now declare a function that allocates memory and initializes each point of the map. The function takes one argument corresponding with the land type:

```c
t_point                *init_point(char value)
{
	t_point            *pt;

	// Allocate memory for a struct point
	pt = (t_point *)malloc(sizeof(t_point));
	if (pt == NULL)
		return (NULL);

	// Set the land type with the received value
	pt->value = value;

	// Set initial value of the 4 pointers
	pt->top = NULL;
	pt->right = NULL;
	pt->bottom = NULL;
	pt->left = NULL;

	// Finally, return the initialized struct point
	return (pt);
}
```

The function init_point() initially set the 4 pointers as NULL, then you can say: "The first time I call the function, I get a struct point that represents a valid map of 1x1 block". It is always safer to set every members of a struct type element!

Now, consider the loop that reads the file (step 1) and let's initialize each point of the map:

```c
t_point                *pt;

// Initially set the pointer to struct as NULL (Be safe!)
pt = NULL;

THE_LOOP
{
	// The loop from step #1 reads the file one byte at a time and puts it into buf[0]

	if (buf[0] == '\n')
	{
		// '\n' is not a point! It is a row delimiter
		// Let's do something here at step 3...
	}
	else
	{
		// Initialize each point of the map '.' and 'X'
		pt = init_point(buf[0]);

		// The points are currently not linked together and the pointer *pt is replaced on each turn
		// Let's do something here at step 3...
	}
}
```

Next step consists in linking all of the struct points *pt together...