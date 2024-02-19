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

void	rotate_x(t_pixel *point, double angle, t_map *map)
{
	float	rad;

	rad = angle * M_PI / 180;
	point->y[ISO] = point->y[ISO] * cos(rad) - point->z[ISO] * sin(rad);
	point->z[ISO] = point->y[ISO] * sin(rad) + point->z[ISO] * cos(rad);
	point->x[ISO] = point->x[ISO];
}

void	rotate_y(t_pixel *point, double angle, t_map *map)
{
	float	rad;

	rad = angle * M_PI / 180;
	point->x[ISO] = point->x[ISO]* cos(rad) + point->z[ISO] * sin(rad);
	point->z[ISO] = -point->y[ISO]* sin(rad) + point->z[ISO] * cos(rad);
	point->y[ISO] = point->y[ISO];
}

void	rotate_z(t_pixel *point, double angle, t_map *map)
{
	float	rad;

	rad = angle * M_PI / 180;
	point->x[ISO] = ((point->x[ORG] * map->zoom) * cos(rad)) - ((point->y[ORG] * map->zoom) 
			* sin(rad));
	point->y[ISO] = ((point->x[ORG] * map->zoom) * sin(rad)) + ((point->y[ORG] * map->zoom) 
			* cos(rad));
	point->z[ISO] = point->z[ORG] * map->zoom ;
}

int	define_iso(t_map *map)
{
	int	i;
	int	j;
	int	temp_x;
	int	temp_y;
	int	temp_z;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			rotate_z(&map->coord[i][j], map->angle[Z], map);
			rotate_y(&map->coord[i][j], map->angle[Y], map);
			rotate_x(&map->coord[i][j], map->angle[X], map);

			map->coord[i][j].x[ISO] = map->coord[i][j].x[ISO] + map->mid[X];
			map->coord[i][j].y[ISO] = map->coord[i][j].y[ISO] + map->mid[Y];
			printf ("x = %d , y = %d\n", i, j);
			printf("map->mid[X] = %d, map->mid[Y] = %d\n", map->mid[X], map->mid[Y]);
			printf("x = %d, y = %d, z = %d\n", map->coord[i][j].x[ISO], map->coord[i][j].y[ISO], map->coord[i][j].z[ISO]);
			j++;
		}
		i++;
	}
	return (0);
}
