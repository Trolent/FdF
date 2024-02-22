/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:52:40 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 16:38:45 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_pixel *point, double angle, t_map *map)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;
	double	angle_rad;

	angle_rad = angle * (M_PI / 180);
	temp_x = point->x[ISO];
	temp_y = (point->y[ISO] * cos(angle_rad)) - (point->z[ISO]
			* sin(angle_rad));
	temp_z = (point->y[ISO] * sin(angle_rad)) + (point->z[ISO]
			* cos(angle_rad));
	point->x[ISO] = temp_x;
	point->y[ISO] = temp_y;
	point->z[ISO] = temp_z;
}

void	rotate_y(t_pixel *point, double angle, t_map *map)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;
	double	angle_rad;

	angle_rad = angle * (M_PI / 180);
	temp_x = (point->x[ISO] * cos(angle_rad)) + (point->z[ISO]
			* sin(angle_rad));
	temp_y = point->y[ISO];
	temp_z = (-point->x[ISO] * sin(angle_rad)) + (point->z[ISO]
			* cos(angle_rad));
	point->x[ISO] = temp_x;
	point->y[ISO] = temp_y;
	point->z[ISO] = temp_z;
}

void	rotate_z(t_pixel *point, double angle, t_map *map)
{
	double	temp_x;
	double	temp_y;
	double	temp_z;
	double	angle_rad;

	angle_rad = angle * (M_PI / 180);
	temp_x = (point->x[ISO] * cos(angle_rad)) - (point->y[ISO]
			* sin(angle_rad));
	temp_y = (point->x[ISO] * sin(angle_rad)) + (point->y[ISO]
			* cos(angle_rad));
	temp_z = point->z[ISO];
	point->x[ISO] = temp_x;
	point->y[ISO] = temp_y;
	point->z[ISO] = temp_z;
}

void	z_ratio(t_pixel *point, t_map *map)
{
	point->x[ISO] = point->x[ORG] * map->zoom;
	point->y[ISO] = point->y[ORG] * map->zoom;
	point->z[ISO] = point->z[ORG] * map->zoom * map->z_range;
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
			z_ratio(&map->coord[i][j], map);
			rotate_z(&map->coord[i][j], map->angle[Z], map);
			rotate_x(&map->coord[i][j], map->angle[X], map);
			rotate_y(&map->coord[i][j], map->angle[Y], map);
			map->coord[i][j].x[ISO] = map->coord[i][j].x[ISO] + map->mid[X];
			map->coord[i][j].y[ISO] = map->coord[i][j].y[ISO] + map->mid[Y];
			j++;
		}
		i++;
	}
	return (0);
}
