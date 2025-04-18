/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_views.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:27 by trolland          #+#    #+#             */
/*   Updated: 2024/02/24 19:18:40 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	i_key(t_vars *vars)
{
	if (vars->map->angle[X] == 120 && vars->map->angle[Y] == 120
		&& vars->map->angle[Z] == 120)
		return (0);
	vars->map->angle[X] = 45;
	vars->map->angle[Y] = 0;
	vars->map->angle[Z] = 45;
	return (1);
}

int	t_key(t_vars *vars)
{
	if (vars->map->angle[X] == 0 && vars->map->angle[Y] == 0
		&& vars->map->angle[Z] == 0)
		return (0);
	vars->map->angle[X] = 0;
	vars->map->angle[Y] = 0;
	vars->map->angle[Z] = 0;
	return (1);
}

int	y_key(t_vars *vars)
{
	if (vars->map->angle[X] == 0 && vars->map->angle[Y] == 90
		&& vars->map->angle[Z] == 0)
		return (0);
	vars->map->angle[X] = 0;
	vars->map->angle[Y] = 90;
	vars->map->angle[Z] = 0;
	return (1);
}

int	g_key(t_vars *vars)
{
	if (vars->map->angle[X] == 90 && vars->map->angle[Y] == 0
		&& vars->map->angle[Z] == 0)
		return (0);
	vars->map->angle[X] = 90;
	vars->map->angle[Y] = 0;
	vars->map->angle[Z] = 0;
	return (1);
}

int	r_key(t_vars *vars)
{
	if (vars->map->mid[X] == WINDOW_WIDTH / 2
		&& vars->map->mid[Y] == WINDOW_HEIGHT / 2)
		return (0);
	vars->map->mid[X] = WINDOW_WIDTH / 2;
	vars->map->mid[Y] = WINDOW_HEIGHT / 2;
	return (1);
}
