/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:27:52 by trolland          #+#    #+#             */
/*   Updated: 2024/02/10 13:05:49 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error_maps.h"
#include "../includes/fdf.h"
#include "../libft/libft.h"

int	quit(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	quit_map(char *s, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	// mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	// free(vars->img);
	free_map(vars->map, vars->map->rows);
	return (quit(s));
}