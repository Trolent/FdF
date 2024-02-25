/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_lines_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:41 by trolland          #+#    #+#             */
/*   Updated: 2024/02/24 19:18:08 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_esc(t_vars *vars)
{
	(void)vars;
	// mlx_loop_end(vars->mlx);
	return (0);
}

int	wrong_key(t_vars *vars)
{
	(void)vars;
	return (1);
}

int	l_key(t_vars *vars)
{
	if (vars->map->line == 0)
		vars->map->line = 1;
	else
		vars->map->line = 0;
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

int	d_key(t_vars *vars)
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
