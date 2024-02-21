/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_letter0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:41 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 11:25:42 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

const int	key_esc(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	// quit("tchus");
	return (0);
}

const int	l_key(t_vars *vars)
{
	if (vars->map->line == 0)
		vars->map->line = 1;
	else
		vars->map->line = 0;
	return (1);
}

const int	d_key(t_vars *vars)
{
	if (vars->map->diag == 0)
	{
		vars->map->diag = 1;
		vars->map->line = 1;
	}
	else
		vars->map->diag = 0;
	return (1);
}

const int	c_key(t_vars *vars)
{
	if (vars->map->z_color == 0)
		vars->map->z_color = 1;
	else
		vars->map->z_color = 0;
	return (1);
}

const int	wrong_key(t_vars *vars)
{
	return (1);
}
