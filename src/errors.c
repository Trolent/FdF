/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:27:52 by trolland          #+#    #+#             */
/*   Updated: 2024/05/30 12:15:23 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error_maps.h"
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdio.h>

int	quit(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	quit_map(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	free_map(vars->map, vars->map->rows);
	return (quit(ERR_MAP_DATA));
}

int	free_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	free_map(vars->map, vars->map->rows);
	exit(0);
}
