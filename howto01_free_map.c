/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_free_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 13:38:07 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/16 14:28:24 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "howto01_header.h"

void				howto01_free_map(t_point **pt)
{
	t_point			*row;
	t_point			*col;

	col = *pt;
	while (col)
	{
		row = col;
		while (row)
		{
			free(row);
			row = row->right;
		}
		col = col->bottom;
	}
	*pt = NULL;
}
