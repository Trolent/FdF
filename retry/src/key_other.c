/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:41 by trolland          #+#    #+#             */
/*   Updated: 2024/02/13 16:21:49 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_esc(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
}

void	l_key(t_vars *vars)
{
	if (vars->map->line == 0)
		vars->map->line = 1;
	else
		vars->map->line = 0;
}

void	c_key(t_vars *vars)
{
	if (vars->map->z_color == 0)
		vars->map->z_color = 1;
	else
		vars->map->z_color = 0;
}

void	wrong_key(t_vars *vars)
{
	return ;
}
