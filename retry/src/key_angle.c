/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:14:51 by trolland          #+#    #+#             */
/*   Updated: 2024/02/18 21:49:43 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	z_key(t_vars *vars)
{
	vars->map->angle[X] += 1;
	define_iso(vars->map);
	return (1);
}

int	x_key(t_vars *vars)
{
	vars->map->angle[X] -= 1;
	define_iso(vars->map);
	return (1);
}

int	a_key(t_vars *vars)
{
	vars->map->angle[Y] += 1;
	define_iso(vars->map);
	return (1);
}

int	d_key(t_vars *vars)
{
	vars->map->angle[Y] -= 1;
	define_iso(vars->map);
	return (1);
}
