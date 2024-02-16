/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:21:25 by trolland          #+#    #+#             */
/*   Updated: 2024/02/16 18:14:39 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARROWS_H
# define ARROWS_H

# include "fdf.h"

# if defined(__linux__)
#  define ESC_KEY 0xff1b
#  define LEFT_KEY 0xff51
#  define RIGHT_KEY 0xff53
#  define UP_KEY 0xff52
#  define DOWN_KEY 0xff54
#  define L_KEY 0x6c
#  define C_KEY 0x63
#  define I_KEY 0x69
#  define T_KEY 0x74
#  define Z_KEY 0x7a
#  define X_KEY 0x78
#  define A_KEY 0x61
#  define D_KEY 0x64
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
# endif

int	key_right(t_vars *vars);
int	key_left(t_vars *vars);
int	key_down(t_vars *vars);
int	key_up(t_vars *vars);
int	key_esc(t_vars *vars);
int	l_key(t_vars *vars);
int	c_key(t_vars *vars);
int	i_key(t_vars *vars);
int	t_key(t_vars *vars);
int	wrong_key(t_vars *vars);
int	z_key(t_vars *vars);
int	x_key(t_vars *vars);
int	a_key(t_vars *vars);
int	d_key(t_vars *vars);

#endif