/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:27 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 15:52:24 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

const int	key_right(t_vars *vars)
{
	vars->map->mid[X] -= (int)(1 * vars->map->zoom / 4 + 1);
	return (1);
}

const int	key_left(t_vars *vars)
{
	vars->map->mid[X] += (int)(1 * vars->map->zoom / 4 + 1);
	return (1);
}

const int	key_down(t_vars *vars)
{
	vars->map->mid[Y] -= (int)(1 * vars->map->zoom / 4 + 1);
	return (1);
}

const int	key_up(t_vars *vars)
{
	vars->map->mid[Y] += (int)(1 * vars->map->zoom / 4 + 1);
	return (1);
}
