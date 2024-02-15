/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:35:24 by trolland          #+#    #+#             */
/*   Updated: 2024/02/15 22:12:40 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_pixel *point, double angle)
{
	point->y[ISO] = ft_round(point->y[TOP] * cos(angle) - point->z[TOP]
			* sin(angle));
	point->z[ISO] = ft_round(point->y[TOP] * sin(angle) + point->z[TOP]
			* cos(angle));
}

void	rotate_y(t_pixel *point, double angle)
{
	point->x[ISO] = ft_round(point->x[TOP] * cos(angle) + point->z[TOP]
			* sin(angle));
	point->z[ISO] = ft_round(-point->y[TOP] * sin(angle) + point->z[TOP]
			* cos(angle));
}

void	rotate_z(t_pixel *point, double angle)
{
	point->x[ISO] = ft_round(point->x[TOP] * cos(angle) - point->y[TOP]
			* sin(angle));
	point->y[ISO] = ft_round(point->x[TOP] * sin(angle) + point->y[TOP]
			* cos(angle));
}

int	define_iso(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			rotate_x(&map->coord[i][j], map->angle[X]);
			rotate_y(&map->coord[i][j], map->angle[Y]);
			rotate_z(&map->coord[i][j], map->angle[Z]);
			j++;
		}
		i++;
	}
	return (0);
}
