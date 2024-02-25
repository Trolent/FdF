/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:35:18 by trolland          #+#    #+#             */
/*   Updated: 2024/02/24 19:18:50 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	close_mlx(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img->img);
	free(vars->img);
	// mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int	cross_close(t_vars *vars)
{
	(void)vars;
	// mlx_loop_end(vars->mlx);
	return (0);
}
