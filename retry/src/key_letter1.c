/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_letter1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:27 by trolland          #+#    #+#             */
/*   Updated: 2024/02/18 20:23:20 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	i_key(t_vars *vars)
{
	if (vars->map->iso == 1)
		return (0);
	vars->map->iso = 1;
	vars->map->top = 0;
	return (1);
}

int	t_key(t_vars *vars)
{
	if (vars->map->top == 1)
		return (0);
	vars->map->top = 1;
	vars->map->iso = 0;
	return (1);
}
