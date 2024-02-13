/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:14 by trolland          #+#    #+#             */
/*   Updated: 2024/02/13 13:46:14 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h> // must dell before push

int	map_size(t_map *map)
{
	int	i;

	i = 1;
	while (map->rows * i < WINDOW_HEIGHT && map->columns * i < WINDOW_WIDTH)
		map->zoom = ++i;
	map->midx = (WINDOW_HEIGHT / 2) - (map->rows * map->zoom / 2);
	map->midy = (WINDOW_WIDTH / 2) - (map->rows * map->zoom / 2);
	
}

int	main(int argc, char **argv)
{
	t_map	map;

	errno = 0;
	if (argc != 2)
		quit(ERR_ARG);
	else
	{
		map_init(&map);
		if (parse(&map, argv[1]) == 0)
			quit(ERR_GEN);
	}
	map_size(&map);
	// print_map(&map);
	graphics(&map);
	free_map(&map, map.rows);
	return (0);
}
