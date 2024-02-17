/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:12 by trolland          #+#    #+#             */
/*   Updated: 2024/02/17 14:53:16 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/keys.h"
#include "../includes/fdf.h"

int	key_map(int keycode)
{
	if (keycode == ESC_KEY)
		return (printf("pressed ESC_KEY\n"),1);
	if (keycode == RIGHT_KEY)
		return (printf("pressed RIGHT_KEY\n"),2);
	if (keycode == LEFT_KEY)
		return (printf("pressed LEFT_KEY\n"), 3);
	if (keycode == DOWN_KEY)
		return (printf("pressed DOWN_KEY\n"), 4);
	if (keycode == UP_KEY)
		return (printf("pressed UP_KEY\n"), 5);
	if (keycode == L_KEY)
		return (printf("pressed L_KEY\n"), 6);
	if (keycode == C_KEY)
		return (printf("pressed C_KEY\n"), 7);
	if (keycode == I_KEY)
		return (printf("pressed I_KEY\n"), 8);
	if (keycode == T_KEY)
		return (printf("pressed T_KEY\n"), 9);
	if (keycode == Z_KEY)
		return (printf("pressed Z_KEY\n"), 10);
	if (keycode == X_KEY)
		return (printf("pressed X_KEY\n"), 11);
	if (keycode == A_KEY)
		return (printf("pressed A_KEY\n"), 12);
	if (keycode == D_KEY)
		return (printf("pressed D_KEY\n"), 13);
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
