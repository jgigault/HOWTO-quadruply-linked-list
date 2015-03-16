/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_rewind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 14:02:40 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/16 14:08:35 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "howto01_header.h"

void				howto01_rewind_left(t_point **pt)
{
	if (*pt)
		while ((*pt)->left)
			*pt = (*pt)->left;
}

void				howto01_rewind_top(t_point **pt)
{
	if (*pt)
		while ((*pt)->top)
			*pt = (*pt)->top;
}
