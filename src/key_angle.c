/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:14:51 by trolland          #+#    #+#             */
/*   Updated: 2024/02/19 17:47:26 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	z_key(t_vars *vars)
{
	vars->map->angle[Z] += 1;
	define_iso(vars->map);
	return (1);
}

int	x_key(t_vars *vars)
{
	vars->map->angle[Z] -= 1;
	define_iso(vars->map);
	return (1);
}

int	a_key(t_vars *vars)
{
	vars->map->angle[Y] += 1;
	define_iso(vars->map);
	return (1);
}

int	s_key(t_vars *vars)
{
	vars->map->angle[Y] -= 1;
	define_iso(vars->map);
	return (1);
}

int q_key(t_vars *vars)
{
	vars->map->angle[X] += 1;
	define_iso(vars->map);
	return (1);
}

int w_key(t_vars *vars)
{
	vars->map->angle[X] -= 1;
	define_iso(vars->map);
	return (1);
}
