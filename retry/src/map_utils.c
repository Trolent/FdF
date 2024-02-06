/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:09:59 by trolland          #+#    #+#             */
/*   Updated: 2024/02/02 15:42:22 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_map(t_map *map, int lines)
{
	while (lines >= 0)
	{
		free(map->coord[lines]);
		lines--;
	}
	free(map->coord);
}

void map_init(t_map *map)
{
	map->coord =NULL;
	map->zoom = 0;
	map->rows = 0;
	map->columns = 0;
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
			printf("%d", map->coord[i][j].x);
			printf(",%u", map->coord[i][j].color);
			printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}
