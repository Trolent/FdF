/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:09:59 by trolland          #+#    #+#             */
/*   Updated: 2024/02/13 16:23:43 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_map *map, int rows)
{
	while (rows >= 0)
	{
		free(map->coord[rows]);
		rows--;
	}
	free(map->coord);
}

void	map_init(t_map *map)
{
	map->coord = NULL;
	map->zoom = 8;
	map->rows = 0;
	map->columns = 0;
	map->iso = 1;
	map->angle = 45;
	map->midx = 0;
	map->midy = 0;
	map->line = 1;
	map->z_color = 1;
	map->z_max = 0;
	map->z_min = 0;
}

//==================================================>>>>>> COMMENT BEFORE PUSH
void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			printf("z = %d ", map->coord[i][j].z);
			printf("x = %d ", map->coord[i][j].x);
			printf("y = %d ", map->coord[i][j].y);
			printf(",%u", map->coord[i][j].color);
			printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("t_max = %d\n", map->z_max);
	printf("t_min = %d\n", map->z_min);
}
