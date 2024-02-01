/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:59:55 by trolland          #+#    #+#             */
/*   Updated: 2024/02/01 18:20:29 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "error_maps.h"
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pixel
{
	int			x;
	int			y;
	int			z;
	long long	color;
}				t_pixel;

typedef struct s_map
{
	t_pixel		**coord;
	int			zoom;
}				t_map;

int				parse(t_map *map, char *file);
int				quit(char *s);

#endif