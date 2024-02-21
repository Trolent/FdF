/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_angle_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:14:51 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 11:20:20 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

const int	a_key(t_vars *vars)
{
	int	i;
	int	j;

	vars->map->angle[Y] += 1;
	i = 0;
	while (i < vars->map->rows)
	{
		j = 0;
		while (j < vars->map->columns)
		{
			z_ratio(&vars->map->coord[i][j], vars->map);
			rotate_x(&vars->map->coord[i][j], vars->map->angle[X], vars->map);
			rotate_y(&vars->map->coord[i][j], vars->map->angle[Y], vars->map);
			rotate_z(&vars->map->coord[i][j], vars->map->angle[Z], vars->map);
			vars->map->coord[i][j].x[ISO] = vars->map->coord[i][j].x[ISO]
				+ vars->map->mid[X];
			vars->map->coord[i][j].y[ISO] = vars->map->coord[i][j].y[ISO]
				+ vars->map->mid[Y];
			j++;
		}
		i++;
	}
	return (1);
}

const int	s_key(t_vars *vars)
{
	int	i;
	int	j;

	vars->map->angle[Y] -= 1;
	i = 0;
	while (i < vars->map->rows)
	{
		j = 0;
		while (j < vars->map->columns)
		{
			z_ratio(&vars->map->coord[i][j], vars->map);
			rotate_x(&vars->map->coord[i][j], vars->map->angle[X], vars->map);
			rotate_y(&vars->map->coord[i][j], vars->map->angle[Y], vars->map);
			rotate_z(&vars->map->coord[i][j], vars->map->angle[Z], vars->map);
			vars->map->coord[i][j].x[ISO] = vars->map->coord[i][j].x[ISO]
				+ vars->map->mid[X];
			vars->map->coord[i][j].y[ISO] = vars->map->coord[i][j].y[ISO]
				+ vars->map->mid[Y];
			j++;
		}
		i++;
	}
	return (1);
}
