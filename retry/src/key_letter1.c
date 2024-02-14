/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_letter1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:27 by trolland          #+#    #+#             */
/*   Updated: 2024/02/14 12:21:01 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	i_key(t_vars *vars)
{
	if (vars->map->top == 1)
	{
		vars->map->iso = 1;
		vars->map->top = 0;
	}
	else
		return ;
	return ;
}

void	t_key(t_vars *vars)
{
	if (vars->map->iso == 1)
	{
		vars->map->top = 1;
		vars->map->iso = 0;
	}
	else
		return ;
	return ;
}
