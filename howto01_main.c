/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_get_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 13:28:42 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/16 15:33:55 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "howto01_header.h"

int						main(int argc, char **argv)
{
	char				buf[BUFF_SIZE];
	t_point				*prev_top;
	t_point				*prev_left;
	t_point				*pt;
	int					fd;
	ssize_t				size;
	size_t				count_col;
	size_t				count_col_first_row;

	pt = NULL;
	prev_top = NULL;
	prev_left = NULL;
	count_col = 0;
	count_col_first_row = 0;

	if (argc != 2)
		return (howto01_display_error(&pt));

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (howto01_display_error(&pt));

	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{

		if (size == -1)
			return (howto01_display_error(&pt));

		if (buf[0] != '.' && buf[0] != 'X' && buf[0] != '\n')
		{
			close(fd);
			return (howto01_display_error(&pt));
		}

		if (buf[0] == '\n')
		{

			if (prev_top == NULL)
				count_col_first_row = count_col;
			else if (count_col != count_col_first_row || count_col > LIMIT_COL)
				return (howto01_display_error(&pt));

			howto01_rewind_left(&pt);
			prev_top = pt;
			prev_left = NULL;

			count_col = 0;
		}
		else
		{
			pt = howto01_init_point(buf[0]);
			if (pt == NULL)
				return (howto01_display_error(&pt));

			pt->left = prev_left;
			if (prev_left)
				prev_left->right = pt;

			pt->top = prev_top;
			if (prev_top)
				prev_top->bottom = pt;

			prev_left = pt;
			if (prev_top)
				prev_top = prev_top->right;

			count_col++;
		}
	}

	if (pt == NULL)
		return (howto01_display_error(&pt));

	howto01_rewind_left(&pt);
	howto01_rewind_top(&pt);

	howto01_create_islands(&pt);

	howto01_display_map(&pt);

	howto01_free_map(&pt);
	return (0);
}
