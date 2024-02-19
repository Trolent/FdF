/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_letter1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:27 by trolland          #+#    #+#             */
/*   Updated: 2024/02/19 17:26:07 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	i_key(t_vars *vars)
{
	if (vars->map->angle[X] == 120 && vars->map->angle[Y] == 120
		&& vars->map->angle[Z] == 120)
		return (0);
	vars->map->angle[X] = 30;
	vars->map->angle[Y] = 330;
	vars->map->angle[Z] = 30;
	return (1);
}

int	t_key(t_vars *vars)
{
	if (vars->map->angle[X] == 0 && vars->map->angle[Y] == 0
		&& vars->map->angle[Z] == 0)
		return (0);
	vars->map->angle[X] = 0;
	vars->map->angle[Y] = 0;
	vars->map->angle[Z] = 0;
	return (1);
}
