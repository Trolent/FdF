/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:22:16 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 12:25:57 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "fdf.h"

/*struct for the bresenham algorithm*/
typedef struct s_bresenham
{
	t_pixel	*temp;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		inc_x;
	int		inc_y;
	int		len;
	int		i;
	int		err;
	int		err2;
}			t_bresenham;

/*struct use only to draw the line*/
typedef struct s_draw
{
	t_pixel	*coord0;
	t_pixel	*coord1;
}			t_draw;

#endif