/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:27 by trolland          #+#    #+#             */
/*   Updated: 2024/02/13 15:22:35 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_right(t_vars *vars)
{
		vars->map->midy -= 1 * vars->map->zoom / 4 + 1;
}

void	key_left(t_vars *vars)
{
		vars->map->midy += 1 * vars->map->zoom / 4 + 1;
}

void	key_down(t_vars *vars)
{
		vars->map->midx -= 1 * vars->map->zoom / 4 + 1;
}

void	key_up(t_vars *vars)
{
		vars->map->midx += 1 * vars->map->zoom / 4 + 1;
}
