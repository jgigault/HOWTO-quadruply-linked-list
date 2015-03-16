/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_init_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 14:10:08 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/16 14:21:31 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "howto01_header.h"

t_point				*howto01_init_point(char value)
{
	t_point			*pt;

	pt = (t_point *)malloc(sizeof(t_point));
	if (pt == NULL)
		return (NULL);
	pt->value = value;
	pt->top = NULL;
	pt->right = NULL;
	pt->bottom = NULL;
	pt->left = NULL;
	return (pt);
}
