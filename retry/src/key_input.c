/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:12 by trolland          #+#    #+#             */
/*   Updated: 2024/02/13 18:27:37 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/arrows.h"
#include "../includes/fdf.h"


void	i_key(t_vars *vars)
{
	if (vars->map->iso == 0)
		vars->map->iso = 1;
	else
		vars->map->iso = 0;
}

int	key_map(int keycode)
{
	if (keycode == ESC_KEY)
		return (1);
	if (keycode == RIGHT_KEY)
		return (2);
	if (keycode == LEFT_KEY)
		return (3);
	if (keycode == DOWN_KEY)
		return (4);
	if (keycode == UP_KEY)
		return (5);
	if (keycode == L_KEY)
		return (6);
	if (keycode == C_KEY)
		return (7);
	if (keycode == I_KEY)
		return(8);
	else
		return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	void	(*f[9])(t_vars *vars);

	f[0] = &wrong_key;
	f[1] = &key_esc;
	f[2] = &key_right;
	f[3] = &key_left;
	f[4] = &key_down;
	f[5] = &key_up;
	f[6] = &l_key;
	f[7] = &c_key;
	f[8] = &i_key;
	f[key_map(keycode)](vars);
	render_next_frame(vars);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_vars *vars)
{
	int	i;

	i = vars->map->zoom / 10 + 1;
	if (button == 4 && vars->map->zoom < 100000)
		vars->map->zoom += i;
	if (button == 5 && vars->map->zoom > 1)
		vars->map->zoom -= i;
	render_next_frame(vars);
	return (0);
}

int	mlx_handle_input(t_vars *vars)
{
	mlx_mouse_hook(vars->win, (int (*)())mouse_scroll, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	return (1);
}
