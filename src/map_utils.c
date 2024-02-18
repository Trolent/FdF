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
#define PI 3.14159265

void	map_init(t_map *map)
{
	map->coord = NULL;
	map->rows = 0;
	map->columns = 0;
	map->top = 1;
	map->mid[X] = 0;
	map->mid[Y] = 0;
	map->zoom = 1;
	map->line = 1;
	map->iso = 0;
	map->angle[X] = 120;
	map->angle[Y] = 45;
	map->angle[Z] = 120;
	map->z_color = 0;
	map->z_max = 0;
	map->z_min = 0;
}

int	perspec(t_map *map)
{
	int	view;

	if (map->iso == 1)
		view = ISO;
	else
		view = TOP;
	return (view);
}

int color(t_map *map)
{
	int clr;

	if (map->z_color == 1)
		clr = ALTCLR;
	else
		clr = ORGCLR;
	return (clr);
}

//==================================================>>>>>> COMMENT BEFORE PUSH
void	print_map(t_map *map)
{
	int	i;
	int	j;
	int	view;
	int	clr;

	if (map->iso == 1)
		view = ISO;
	else
		view = TOP;
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
			printf("%d ", map->coord[i][j].z[view]);
			



			// printf("z = %d ", map->coord[i][j].z[view]);
			// printf("x = %d ", map->coord[i][j].x[view]);
			// printf("y = %d ", map->coord[i][j].y[view]);
			// printf("alt color = %d\n", map->coord[i][j].color[clr]);
			j++;
		}
		printf("\n");
		i++;
	}
	// printf("t_max = %d\n", map->z_max);
	// printf("t_min = %d\n", map->z_min);
}

