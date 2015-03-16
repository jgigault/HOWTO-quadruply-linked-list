/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_create_islands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 14:32:01 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/16 14:39:33 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "howto01_header.h"

static void			howto01_recursive(t_point *pt, int index)
{
	pt->value = index + 48;
	if (pt->top && pt->top->value == 'X')
		howto01_recursive(pt->top, index);
	if (pt->right && pt->right->value == 'X')
		howto01_recursive(pt->right, index);
	if (pt->bottom && pt->bottom->value == 'X')
		howto01_recursive(pt->bottom, index);
	if (pt->left && pt->left->value == 'X')
		howto01_recursive(pt->left, index);
}

int					howto01_create_islands(t_point **pt)
{
	t_point			*row;
	t_point			*col;
	int				index;

	index = 0;
	col = *pt;
	while (col)
	{
		row = col;
		while (row)
		{
			if (row->value == 'X')
			{
				howto01_recursive(row, index);
				index++;
			}
			row = row->right;
		}
		col = col->bottom;
	}
	return (index);
}
