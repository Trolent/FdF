/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:09:59 by trolland          #+#    #+#             */
/*   Updated: 2024/02/14 11: by trolland         ###   ########.fr       */
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
	map->rows = 0;
	map->columns = 0;
	map->top = 1;
	map->midx = 0;
	map->midy = 0;
	map->zoom = 8;
	map->line = 1;
	map->iso = 0;
	map->angle[X]= 0;
	map->angle[Y]= 0;
	map->angle[Z]= 0;
	map->z_color = 0;
	map->z_max = 0;
	map->z_min = 0;
}

//==================================================>>>>>> COMMENT BEFORE PUSH
void	print_map(t_map *map)
{
	int	i;
	int	j;
	int view;

	if (map->iso == 1)
		view = ISO;
	else
		view = TOP;
	int clr;

	if (map->z_color == 1)
		clr = ALTCLR;
	else
		clr = ORGCLR;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			printf("z = %d ", map->coord[i][j].z[view]);
			printf("x = %d ", map->coord[i][j].x[view]);
			printf("y = %d ", map->coord[i][j].y[view]);
			printf("alt color = %d\n", map->coord[i][j].color[clr]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("t_max = %d\n", map->z_max);
	printf("t_min = %d\n", map->z_min);
}
