/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:24:07 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 15:52:03 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	define_z_range(t_map *map)
{
	if (map->z_max == map->z_min)
		map->z_range = 0.1;
	else
		map->z_range = (map->z_max / (map->z_max - map->z_min)) / 100;
	if (map->z_range < 0.1)
		map->z_range = 0.1;
}

void	define_alt_color(t_map *map, t_pixel *point)
{
	if (map->z_max == map->z_min)
		point->color[ALTCLR] = WHITE;
	else if (point->z[ORG] == 0)
		point->color[ALTCLR] = GREEN;
	else if (point->z[ORG] > 0)
		point->color[ALTCLR] = gradient(GREEN, RED, map->z_max, point->z[ORG]);
	else if (point->z[ORG] < 0)
		point->color[ALTCLR] = gradient(GREEN, BLUE, -map->z_min,
				-point->z[ORG]);
}

int	define_z_relations(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	define_z_range(map);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			define_alt_color(map, &map->coord[i][j]);
			map->coord[i][j].z[ISO] = map->coord[i][j].z[ORG] / map->z_range;
			j++;
		}
		i++;
	}
	return (0);
}

void	define_zoom(t_map *map)
{
	float	i;

	i = 1;
	while (1)
	{
		if ((map->rows - 1) * i < WINDOW_HEIGHT && (map->columns - 1)
			* i < WINDOW_WIDTH)
			i += 0.2;
		else
		{
			if (i > 1)
				i -= 0.2;
			break ;
		}
	}
	map->zoom = i;
	map->mid[X] = (WINDOW_WIDTH / 2);
	map->mid[Y] = (WINDOW_HEIGHT / 2);
}
