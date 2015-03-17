/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_create_islands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 14:32:01 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/17 17:08:35 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "howto01_header.h"

static void			howto01_fill_island(t_point *pt, int index)
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

int					howto01_create_islands(t_point *pt)
{
	t_point			*current_pt;
	t_point			*current_row;
	int				index;

	index = 0;
	current_row = pt;
	while (current_row)
	{
		current_pt = current_row;
		while (current_pt)
		{
			if (current_pt->value == 'X')
			{
				howto01_fill_island(current_pt, index);
				index++;
			}
			current_pt = current_pt->right;
		}
		current_row = current_row->bottom;
	}
	return (index);
}
