/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:12 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 15:52:31 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"

const int	plus_key(t_vars *vars)
{
	vars->map->z_range += 0.01;
	return (1);
}

const int	minus_key(t_vars *vars)
{
	vars->map->z_range -= 0.01;
	return (1);
}
