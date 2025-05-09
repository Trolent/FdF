/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:19:48 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 12:13:03 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

static double	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

static double	get_b(int trgb)
{
	return (trgb & 0xFF);
}

static int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

int	gradient(int color_start, int color_end, int len, int pos)
{
	double	delta[3];
	int		new[3];
	int		newcolor;

	if (color_start == color_end)
		return (color_end);
	delta[0] = (get_r(color_end) - (get_r(color_start))) / len;
	delta[1] = (get_g(color_end) - (get_g(color_start))) / len;
	delta[2] = (get_b(color_end) - (get_b(color_start))) / len;
	new[0] = (int)((get_r(color_start)) + (pos * delta[0]));
	new[1] = (int)((get_g(color_start)) + (pos * delta[1]));
	new[2] = (int)((get_b(color_start)) + (pos * delta[2]));
	newcolor = create_rgb(new[0], new[1], new[2]);
	return (newcolor);
}
