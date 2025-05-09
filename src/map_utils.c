/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:35:46 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 11:27:00 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/error_maps.h"

void	free_map(t_map *map, int size)
{
	while (size >= 0)
	{
		free(map->coord[size]);
		size--;
	}
	free(map->coord);
}

void	map_init(t_map *map)
{
	*map = (t_map){.zoom = 1, .line = 1, .angle = {45, 0, 45}, .z_range = 1};
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
