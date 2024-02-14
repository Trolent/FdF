/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:12 by trolland          #+#    #+#             */
/*   Updated: 2024/02/14 12:18:36 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/arrows.h"
#include "../includes/fdf.h"

int	key_map(int keycode)
{
	if (keycode == ESC_KEY)
	{
		printf("esc\n");
		return (1);
	}
	if (keycode == RIGHT_KEY)
	{
		printf("right\n");
		return (2);
	}
	if (keycode == LEFT_KEY)
	{
		printf("left\n");
		return (3);
	}
	if (keycode == DOWN_KEY)
	{
		printf("down\n");
		return (4);
	}
	if (keycode == UP_KEY)
	{
		printf("up\n");
		return (5);
	}
	if (keycode == L_KEY)
	{
		printf("L\n");
		return (6);
	}
	if (keycode == C_KEY)
	{
		printf("C\n");
		return (7);
	}
	if (keycode == I_KEY)
	{
		printf("I\n");
		return (8);
	}
	if (keycode == T_KEY)
	{
		printf("T\n");
		return (9);
	}
	else
		return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	void	(*f[10])(t_vars * vars);

	f[0] = &wrong_key;
	f[1] = &key_esc;
	f[2] = &key_right;
	f[3] = &key_left;
	f[4] = &key_down;
	f[5] = &key_up;
	f[6] = &l_key;
	f[7] = &c_key;
	f[8] = &i_key;
	f[9] = &t_key;
	printf("keycode = %d\n", keycode);
	f[key_map(keycode)](vars);
	// printf("out\n");
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
