/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:14 by trolland          #+#    #+#             */
/*   Updated: 2024/02/13 17:12:30 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h> // must dell before push

void	define_zoom(t_map *map)
{
	int	i;

	i = 1;
	while (1)
	{
		if ((map->rows - 1) * i < WINDOW_HEIGHT && (map->columns - 1) * i < WINDOW_WIDTH)
			i += i / 10 + 1;
		else 
		{
			if (i > 1)
				i -= i/10 +1;
			break;
		}
	}
	map->zoom = i;
	map->midx = (WINDOW_HEIGHT / 2) - ((map->rows - 1) * map->zoom / 2);
	map->midy = (WINDOW_WIDTH / 2) - ((map->columns - 1) * map->zoom / 2);
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
	define_zoom(&map);
	// print_map(&map);
	graphics(&map);
	free_map(&map, map.rows);
	return (0);
}
