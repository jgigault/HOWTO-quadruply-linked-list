/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_display_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 14:25:48 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/17 16:11:00 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "howto01_header.h"

void				howto01_display_map(t_point *pt)
{
	t_point			*row;
	t_point			*col;

	col = pt;
	while (col)
	{
		row = col;
		while (row)
		{
			write(STDOUT, &row->value, 1);
			row = row->right;
		}
		write(STDOUT, "\n", 1);
		col = col->bottom;
	}
}
