/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:35:46 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 17:35:50 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error_maps.h"

void	free_map(t_map *map, int rows)
{
	while (rows >= 0)
	{
		free(map->coord[rows]);
		rows--;
	}
	free(map->coord);
}
#define PI 3.14159265

void	map_init(t_map *map)
{
	map->rows = 0;
	map->columns = 0;
	map->mid[X] = 0;
	map->mid[Y] = 0;
	map->zoom = 1;
	map->line = 1;
	map->diag = 0;
	map->top = 0;
	map->iso = 1;
	map->angle[X] = 45;
	map->angle[Y] = 0;
	map->angle[Z] = 45;
	map->z_color = 0;
	map->z_max = 0;
	map->z_min = 0;
	map->z_range = 1;
}

int	color(t_map *map)
{
	int	clr;

	if (map->z_color == 1)
		clr = ALTCLR;
	else
		clr = ORGCLR;
	return (clr);
}
