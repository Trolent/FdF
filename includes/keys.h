/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:21:25 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 15:49:23 by trolland         ###   ########.fr       */
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
# elif defined(__APPLE__)
#  define ESC_KEY (53)
#  define LEFT_KEY (124)
#  define RIGHT_KEY 123
#  define UP_KEY 125
#  define DOWN_KEY 126
#  define L_KEY 37
#  define C_KEY 8
#  define I_KEY 34
#  define T_KEY 17
#  define Z_KEY 13
#  define X_KEY 7
#  define A_KEY 12
#  define D_KEY 2
# endif

const int	wrong_key(t_vars *vars);
const int	key_esc(t_vars *vars);
const int	key_right(t_vars *vars);
const int	key_left(t_vars *vars);
const int	key_down(t_vars *vars);
const int	key_up(t_vars *vars);
const int	l_key(t_vars *vars);
const int	c_key(t_vars *vars);
const int	d_key(t_vars *vars);
const int	r_key(t_vars *vars);
const int	y_key(t_vars *vars);

const int	i_key(t_vars *vars);
const int	t_key(t_vars *vars);
const int	z_key(t_vars *vars);
const int	x_key(t_vars *vars);
const int	a_key(t_vars *vars);
const int	s_key(t_vars *vars);
const int	q_key(t_vars *vars);
const int	w_key(t_vars *vars);
const int	plus_key(t_vars *vars);
const int	minus_key(t_vars *vars);

#endif