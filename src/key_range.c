/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:12 by trolland          #+#    #+#             */
/*   Updated: 2024/02/24 19:17:08 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"

int	plus_key(t_vars *vars)
{
	vars->map->z_range += 0.01f;
	return (1);
}

int	minus_key(t_vars *vars)
{
	vars->map->z_range -= 0.01f;
	return (1);
}

int	u_key(t_vars *vars)
{
	vars->map->z_range = 1;
	return (1);
}
