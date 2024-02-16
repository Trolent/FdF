/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:12 by trolland          #+#    #+#             */
/*   Updated: 2024/02/16 18:15:18 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/keys.h"
#include "../includes/fdf.h"

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
		return (8);
	if (keycode == T_KEY)
		return (9);
	if (keycode == Z_KEY)
		return (10);
	if (keycode == X_KEY)
		return (11);
	if (keycode == A_KEY)
		return (12);
	if (keycode == D_KEY)
		return (13);
	// if (keycode == S_KEY)
	// 	return (14);
	// if (keycode == W_KEY)
	// 	return (15);
	else
		return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	(*f[14])(t_vars *vars);

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
	f[10] = &z_key;
	f[11] = &x_key;	
	f[12] = &a_key;
	f[13] = &d_key;
	
	printf("keycode = %d\n", keycode);
	if (f[key_map(keycode)](vars) == 1)
	{
		if(keycode == Z_KEY || keycode == X_KEY)
			printf("vars->map->angle[X] = %f\n", vars->map->angle[X]);
		if(keycode == A_KEY || keycode == D_KEY)
			printf("vars->map->angle[Y] = %f\n", vars->map->angle[Y]);
		render_next_frame(vars);
	}
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
	// vars->map->midx = x;
	// vars->map->midy = y;
	render_next_frame(vars);
	return (0);
}

int	mlx_handle_input(t_vars *vars)
{
	mlx_mouse_hook(vars->win, (int (*)())mouse_scroll, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 3, &cross_close, vars);
	return (1);
}
