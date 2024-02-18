/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_letter0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:41 by trolland          #+#    #+#             */
/*   Updated: 2024/02/18 19:56:49 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_esc(t_vars *vars)
{
	quit_map("stop", vars);
	// mlx_loop_end(vars->mlx);
	return (0);
}

int	l_key(t_vars *vars)
{
	if (vars->map->line == 0)
		vars->map->line = 1;
	else
		vars->map->line = 0;
	return (1);
}

int m_key(t_vars *vars)
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

int	c_key(t_vars *vars)
{
	if (vars->map->z_color == 0)
		vars->map->z_color = 1;
	else
		vars->map->z_color = 0;
	return (1);
}

int	wrong_key(t_vars *vars)
{
	return (1);
}
