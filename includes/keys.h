/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:21:25 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 11:55:24 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "fdf.h"

# if defined(__linux__)
#  define ESC_KEY 0xff1b
#  define RIGHT_KEY 0xff53
#  define LEFT_KEY 0xff51
#  define DOWN_KEY 0xff54
#  define UP_KEY 0xff52
#  define L_KEY 0x6c
#  define C_KEY 0x63
#  define D_KEY 0x64
#  define I_KEY 0x69
#  define T_KEY 0x74
#  define Z_KEY 0x7a
#  define X_KEY 0x78
#  define A_KEY 0x61
#  define S_KEY 0x73
#  define Q_KEY 0x71
#  define W_KEY 0x77
#  define PLUS_KEY 0xffab
#  define MINUS_KEY 0xffad
#  define R_KEY 0x72
#  define Y_KEY 0x79
#  define U_KEY 0x75
#  define G_KEY 0x67
# elif defined(__APPLE__)
#  define ESC_KEY 53
#  define RIGHT_KEY 124
#  define LEFT_KEY 123
#  define DOWN_KEY 125
#  define UP_KEY 126
#  define L_KEY 37
#  define C_KEY 8
#  define D_KEY 2
#  define I_KEY 34
#  define T_KEY 17
#  define Z_KEY 6
#  define X_KEY 7
#  define A_KEY 0
#  define S_KEY 1
#  define Q_KEY 12
#  define W_KEY 13
#  define PLUS_KEY 24
#  define MINUS_KEY 27
#  define R_KEY 15
#  define Y_KEY 16
#  define U_KEY 32
#  define G_KEY 5
# endif

int	wrong_key(t_vars *vars);
int	key_esc_or_cross_close(t_vars *vars);
int	key_right(t_vars *vars);
int	key_left(t_vars *vars);
int	key_down(t_vars *vars);
int	key_up(t_vars *vars);
int	l_key(t_vars *vars);
int	c_key(t_vars *vars);
int	d_key(t_vars *vars);
int	r_key(t_vars *vars);
int	y_key(t_vars *vars);
int	i_key(t_vars *vars);
int	t_key(t_vars *vars);
int	g_key(t_vars *vars);
int	z_key(t_vars *vars);
int	x_key(t_vars *vars);
int	a_key(t_vars *vars);
int	s_key(t_vars *vars);
int	q_key(t_vars *vars);
int	w_key(t_vars *vars);
int	plus_key(t_vars *vars);
int	minus_key(t_vars *vars);
int	u_key(t_vars *vars);

#endif