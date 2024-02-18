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
	float	rad;

	rad = angle * M_PI / 180;
	point->y[ISO] = point->y[TOP] * cos(rad) - point->z[TOP] * sin(rad);
	point->z[ISO] = point->y[TOP] * sin(rad) + point->z[TOP] * cos(rad);
}

void	rotate_y(t_pixel *point, double angle)
{
	float	rad;

	rad = angle * M_PI / 180;
	point->x[ISO] = point->x[TOP] * cos(rad) + point->z[TOP] * sin(rad);
	point->z[ISO] = -point->y[TOP] * sin(rad) + point->z[TOP] * cos(rad);
}

void	rotate_z(t_pixel *point, double angle)
{
	float	rad;

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
	int	temp_x;
	int	temp_y;
	int	temp_z;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			temp_z = map->coord[i][j].z[ORG] * map->zoom;
			temp_x = ((j - i) * map->zoom) * cos(map->angle[X] * M_PI / 180);
			temp_y = ((i + j) * map->zoom) * cos(map->angle[Y] * M_PI / 180)
				- (temp_z / 20);
			map->coord[i][j].x[ISO] = temp_x + map->mid[X];
			map->coord[i][j].y[ISO] = temp_y + map->mid[Y];
			j++;
		}
		i++;
	}
	return (0);
}
