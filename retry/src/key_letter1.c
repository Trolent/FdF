/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_letter1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:22:27 by trolland          #+#    #+#             */
/*   Updated: 2024/02/14 11:31:03 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	i_key(t_vars *vars)
{
	if (vars->map->iso == 0)
	{
		vars->map->iso = 1;
		vars->map->top = 0;
	}
}

void	t_key(t_vars *vars)
{
	if (vars->map->top == 0)
	{
		vars->map->top = 1;
		vars->map->iso = 0;
	}
}