/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howto01_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgigault <jgigault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 13:25:05 by jgigault          #+#    #+#             */
/*   Updated: 2015/03/17 16:10:11 by jgigault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOWTO01_HEADER_H
# define HOWTO01_HEADER_H

# define STDOUT 1
# define BUFF_SIZE 1
# define LIMIT_COL 1024

# include <fcntl.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct				s_point
{
	char					value;
	struct s_point			*top;
	struct s_point			*right;
	struct s_point			*bottom;
	struct s_point			*left;
}							t_point;

t_point						*howto01_init_point(char value);
void						howto01_free_map(t_point **pt);
int							howto01_display_error(t_point **map);
void						howto01_rewind_left(t_point **pt);
void						howto01_rewind_top(t_point **pt);
void						howto01_display_map(t_point *pt);
int							howto01_create_islands(t_point *pt);

#endif
