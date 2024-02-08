/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:09:59 by trolland          #+#    #+#             */
/*   Updated: 2024/02/06 17:49:23 by trolland         ###   ########.fr       */
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

void map_init(t_map *map)
{
	map->coord = NULL;
	map->zoom = 8;
	map->rows = 0;
	map->columns = 0;
	map->iso = 1;
	map->angle = 45;
}

void	print_map(t_map *map)  ///// ====> must comment before submiting
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
			// printf(",%u", map->coord[i][j].color);
			printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}
