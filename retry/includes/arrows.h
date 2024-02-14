/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:21:25 by trolland          #+#    #+#             */
/*   Updated: 2024/02/14 10:45:09 by trolland         ###   ########.fr       */
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
# elif defined(__APPLE__)
#  define ESC_KEY (53)
#  define LEFT_KEY (124)
#  define RIGHT_KEY 123
#  define UP_KEY 125
#  define DOWN_KEY 126
#  define L_KEY 37
#  define C_KEY 34
#  define I_KEY 8
#  define T_KEY 17
# endif

void	key_right(t_vars *vars);
void	key_left(t_vars *vars);
void	key_down(t_vars *vars);
void	key_up(t_vars *vars);
void	key_esc(t_vars *vars);
void	l_key(t_vars *vars);
void	c_key(t_vars *vars);
void    wrong_key(t_vars *vars);

#endif