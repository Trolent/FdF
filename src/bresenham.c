/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:09:36 by trolland          #+#    #+#             */
/*   Updated: 2024/05/30 11:59:47 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "bresenham.h"

static void	bresenham_init(t_bresenham *bres, t_pixel *coord0, t_pixel *coord1)
{
	bres->x0 = (coord0->x[ISO]);
	bres->y0 = (coord0->y[ISO]);
	bres->x1 = (coord1->x[ISO]);
	bres->y1 = (coord1->y[ISO]);
	bres->dx = abs(bres->x1 - bres->x0);
	bres->dy = abs(bres->y1 - bres->y0);
	if (bres->x0 < bres->x1)
		bres->inc_x = 1;
	else
		bres->inc_x = -1;
	if (bres->y0 < bres->y1)
		bres->inc_y = 1;
	else
		bres->inc_y = -1;
	bres->i = 1;
	bres->len = ft_max(bres->dx, bres->dy);
	bres->err = bres->dx - bres->dy;
}

static void	bresenham_init2(t_bresenham *bres)
{
	bres->temp->x[ISO] = bres->x0;
	bres->temp->y[ISO] = bres->y0;
	bres->err2 = 2 * bres->err;
}

static void	bresenham_print(t_bresenham *bres, t_draw *draw, t_data *img,
		t_vars *vars)
{
	int	clr;

	clr = color(vars->map);
	while (bres->i <= bres->len)
	{
		bresenham_init2(bres);
		bres->temp->color[clr] = gradient(draw->coord0->color[clr],
				draw->coord1->color[clr], bres->len, bres->i);
		if (bres->temp->x[ISO] >= 0 && bres->temp->x[ISO] < WINDOW_WIDTH
			&& bres->temp->y[ISO] < WINDOW_HEIGHT && bres->temp->y[ISO] >= 0)
			my_mlx_pixel_put(img, bres->temp, vars->map);
		if (bres->err2 > -bres->dy)
		{
			bres->err -= bres->dy;
			bres->x0 += bres->inc_x;
		}
		if (bres->err2 < bres->dx)
		{
			bres->err += bres->dx;
			bres->y0 += bres->inc_y;
		}
		bres->i++;
	}
}

void	bresenham(t_pixel *coord0, t_pixel *coord1, t_vars *vars, t_data *img)
{
	t_bresenham	bres;
	t_pixel		temp;
	t_draw		draw;

	draw.coord0 = coord0;
	draw.coord1 = coord1;
	bres.temp = &temp;
	bresenham_init(&bres, coord0, coord1);
	bresenham_print(&bres, &draw, img, vars);
}
