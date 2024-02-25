/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:12 by trolland          #+#    #+#             */
/*   Updated: 2024/02/24 19:16:46 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"

int	key_map(int keycode)
{
	int			i;
	const int	key[22] = {ESC_KEY, RIGHT_KEY, LEFT_KEY, DOWN_KEY, UP_KEY,
			L_KEY, C_KEY, D_KEY, I_KEY, T_KEY, Z_KEY, X_KEY, A_KEY, S_KEY,
			Q_KEY, W_KEY, PLUS_KEY, MINUS_KEY, R_KEY, Y_KEY, U_KEY, G_KEY};

	i = -1;
	while (++i < 22)
		if (keycode == key[i])
			return (i + 1);
	return (0);
}
int	key_hook2(int index, t_vars *vars)
{
	int (*f[13])(t_vars *vars);

	f[0] = &t_key;
	f[1] = &z_key;
	f[2] = &x_key;
	f[3] = &a_key;
	f[4] = &s_key;
	f[5] = &q_key;
	f[6] = &w_key;
	f[7] = &plus_key;
	f[8] = &minus_key;
	f[9] = &r_key;
	f[10] = &y_key;
	f[11] = &u_key;
	f[12] = &g_key;
	if (index < 13)
		return (f[index](vars));
	return (0);
}
	

int	key_hook(int keycode, t_vars *vars)
{
	int (*f[15])(t_vars *vars);
	int index;

	f[0] = &wrong_key;
	f[1] = &key_esc;
	f[2] = &key_right;
	f[3] = &key_left;
	f[4] = &key_down;
	f[5] = &key_up;
	f[6] = &l_key;
	f[7] = &c_key;
	f[8] = &d_key;
	f[9] = &i_key;
	index = key_map(keycode);
	if (index > 0)
	{
		if (index < 10 && f[index](vars))
			render_next_frame(vars);
		else if (index > 9 && key_hook2(index - 10, vars))
			render_next_frame(vars);
	}
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 4 && vars->map->zoom < 50000)
		vars->map->zoom = vars->map->zoom * 2;
	else if (button == 5 && vars->map->zoom >= 0)
		vars->map->zoom = vars->map->zoom / 2;
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

// mlx_hook(vars->win, 2, 1L << 0, &key_hook, vars);