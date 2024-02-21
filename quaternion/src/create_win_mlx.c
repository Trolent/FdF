/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:34:16 by trolland          #+#    #+#             */
/*   Updated: 2024/02/20 21:04:15 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	create_win_mlx(t_vars *vars, t_map *map)
{
	vars->map = map;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		quit(ERROR_MLX);  // ======> Change it to do the free map
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!vars->win)
		return (free(vars->mlx), quit(ERROR_MLX));
	vars->img = malloc(sizeof(t_data));
	if (!vars->img)
		return (quit("Error: Unable to allocate memory for img"));
	vars->img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!vars->img->img)
		return (free(vars->img), quit(ERROR_MLX));
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
	return (1);
}
