/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:12 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 01:13:17 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"

// int	key_map(int keycode, int i)
// {
// 	int	key[18];

// 	key[0] = ESC_KEY;
// 	key[1] = RIGHT_KEY;
// 	key[2] = LEFT_KEY;
// 	key[3] = DOWN_KEY;
// 	key[4] = UP_KEY;
// 	key[5] = L_KEY;
// 	key[6] = C_KEY;
// 	key[7] = D_KEY;
// 	key[8] = I_KEY;
// 	key[9] = T_KEY;
// 	key[10] = Z_KEY;
// 	key[11] = X_KEY;
// 	key[12] = A_KEY;
// 	key[13] = S_KEY;
// 	key[14] = Q_KEY;
// 	key[15] = W_KEY;
// 	key[16] = PLUS_KEY;
// 	key[17] = MINUS_KEY;
// 	while (++i < 18)
// 		if (keycode == key[i])
// 			return (i + 1);
// 	return (0);
// }

int	key_map(int keycode)
{
	int			i;
	const int	key[18] = {ESC_KEY, RIGHT_KEY, LEFT_KEY, DOWN_KEY, UP_KEY,
		L_KEY, C_KEY, D_KEY, I_KEY, T_KEY, Z_KEY, X_KEY, A_KEY, S_KEY,
		Q_KEY, W_KEY, PLUS_KEY, MINUS_KEY};

	i = 0;
	while (++i < 18)
		if (keycode == key[i])
			return (i + 1);
	return (0);
}

const int	plus_key(t_vars *vars)
{
	vars->map->z_range = vars->map->z_range;
	return (1);
}

const int	minus_key(t_vars *vars)
{
	vars->map->z_range = vars->map->z_range;
	return (1);
}

// int	key_hook(int keycode, t_vars *vars)
// {
// 	int	(*f[19])(t_vars *vars);

// 	f[0] = &wrong_key;
// 	f[1] = &key_esc;
// 	f[2] = &key_right;
// 	f[3] = &key_left;
// 	f[4] = &key_down;
// 	f[5] = &key_up;
// 	f[6] = &l_key;
// 	f[7] = &c_key;
// 	f[8] = &d_key;
// 	f[9] = &i_key;
// 	f[10] = &t_key;
// 	f[11] = &z_key;
// 	f[12] = &x_key;
// 	f[13] = &a_key;
// 	f[14] = &s_key;
// 	f[15] = &q_key;
// 	f[16] = &w_key;
// 	f[17] = &plus_key;
// 	f[18] = &minus_key;
// 	if (f[key_map(keycode, -1)](vars) == 1)
// 		render_next_frame(vars);
// 	return (0);
// }

int	key_hook(int keycode, t_vars *vars)
{
	const int	(*f[19])(t_vars *vars) = {&wrong_key, &key_esc, &key_right,
		&key_left, &key_down, &key_up, &l_key, &c_key, &d_key, &i_key, &t_key,
		&z_key, &x_key, &a_key, &s_key, &q_key, &w_key, &plus_key, &minus_key};

	if (f[key_map(keycode)](vars) == 1)
		render_next_frame(vars);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_vars *vars)
{
	if (button == 4 && vars->map->zoom < 100000)
		vars->map->zoom = vars->map->zoom * 1.5f;
	if (button == 5 && vars->map->zoom > 1)
		vars->map->zoom = vars->map->zoom / 1.5f;
	define_iso(vars->map);
	render_next_frame(vars);
	return (0);
}

int	mlx_handle_input(t_vars *vars)
{
	mlx_key_hook(vars->win, &key_hook, vars);
	mlx_mouse_hook(vars->win, (int (*)())mouse_scroll, vars);
	mlx_hook(vars->win, 17, 1L << 3, &cross_close, vars);
	return (1);
}
