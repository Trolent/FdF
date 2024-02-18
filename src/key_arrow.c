/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:27 by trolland          #+#    #+#             */
/*   Updated: 2024/02/18 12:14:45 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_right(t_vars *vars)
{
	vars->map->mid[X] -= 1 * vars->map->zoom / 4 + 1;
	return (1);
}

int	key_left(t_vars *vars)
{
	vars->map->mid[X] += 1 * vars->map->zoom / 4 + 1;
	return (1);
}

int	key_down(t_vars *vars)
{
	vars->map->mid[Y] -= 1 * vars->map->zoom / 4 + 1;
	return (1);
}

int	key_up(t_vars *vars)
{
	vars->map->mid[Y] += 1 * vars->map->zoom / 4 + 1;
	return (1);
}
