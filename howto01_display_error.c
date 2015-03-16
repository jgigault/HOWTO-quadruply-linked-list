/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_display_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 13:35:01 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/16 14:02:15 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "howto01_header.h"

int					howto01_display_error(t_point **map)
{
	howto01_rewind_left(map);
	howto01_rewind_top(map);
	howto01_free_map(map);
	write(STDOUT, "\n", 1);
	return (1);
}
