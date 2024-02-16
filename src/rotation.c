/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:35:24 by trolland          #+#    #+#             */
/*   Updated: 2024/02/16 10: by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_pixel *point, double angle)
{
	float rad;

	rad = angle * M_PI / 180;
	point->y[ISO] = point->y[TOP] * cos(rad) - point->z[TOP]
			* sin(rad);
	point->z[ISO] = point->y[TOP] * sin(rad) + point->z[TOP]
			* cos(rad);
}

void	rotate_y(t_pixel *point, double angle)
{
	float rad;

	rad = angle * M_PI / 180;
	point->x[ISO] = point->x[TOP] * cos(rad) + point->z[TOP]
			* sin(rad);
	point->z[ISO] = -point->y[TOP] * sin(rad) + point->z[TOP]
			* cos(rad);
}

void	rotate_z(t_pixel *point, double angle)
{
	float rad;

	rad = angle * M_PI / 180;
	point->x[ISO] = ft_round(point->x[TOP] * cos(rad) - point->y[TOP]
			* sin(rad));
	point->y[ISO] = ft_round(point->x[TOP] * sin(rad) + point->y[TOP]
			* cos(rad));
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
	printf("map->coord[5][5].y[ISO] = %d\n", map->coord[5][5].y[ISO]);
	return (0);
}
