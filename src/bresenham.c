/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:09:36 by trolland          #+#    #+#             */
/*   Updated: 2024/02/17 15:50:28 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

typedef struct s_bresenham
{
    t_pixel *temp;
    int x0;
    int y0;
    int x1;
    int y1;
    int dx;
    int dy;
    int inc_x;
    int inc_y;
    int cumul;
    int i;
} t_bresenham;

typedef struct s_draw
{
    t_pixel *coord0;
    t_pixel *coord1;
} t_draw;

void bresenham_init(t_bresenham *bres, t_pixel *coord0, t_pixel* coord1, t_map *map)
{
    int view;

    view = perspec(map);
    bres->x0 = coord0->x[view];
    bres->y0 = coord0->y[view];
    bres->x1 = coord1->x[view];
    bres->y1 = coord1->y[view];
    bres->dx = abs(bres->x1 - bres->x0);
    bres->dy = abs(bres->y1 - bres->y0);
    if(bres->x0 < bres->x1)
        bres->inc_x = 1;
    else
        bres->inc_x = -1;
    if(bres->y0 < bres->y1)
        bres->inc_y = 1;
    else
        bres->inc_y = -1;
    
}

void bresenham_dx_dy(t_bresenham *bres, t_draw *draw, t_data *img, t_vars *vars)
{
    int clr;

    clr = color(vars->map);
    bres->cumul = bres->dx / 2;
    while (bres->i <= bres->dx)
    {
        bres->x0 += bres->inc_x;
        bres->cumul += bres->dy;
        if (bres->cumul >= bres->dx)
        {
            bres->cumul -= bres->dx;
            bres->y0 += bres->inc_y;
        }
        if (draw->coord0->color[clr] != draw->coord1->color[clr])
			bres->temp->color[clr] = gradient(draw->coord0->color[clr], draw->coord1->color[clr], bres->i, bres->dx);
        else
            bres->temp->color[clr] = 0xFFFFFF;
        my_mlx_pixel_put(img, bres->temp, vars->map, 1);
        bres->i += 1;
    }
}

void bresenham_dy_dx(t_bresenham *bres, t_draw *draw, t_data *img, t_vars *vars)
{
    int clr;

    clr = color(vars->map);
    bres->cumul = bres->dy / 2;
    while (bres->i <= bres->dy)
    {
        bres->y0 += bres->inc_y;
        bres->cumul += bres->dx;
        if (bres->cumul >= bres->dy)
        {
            bres->cumul -= bres->dy;
            bres->x0 += bres->inc_x;
        }
        if (draw->coord0->color[clr] != draw->coord1->color[clr])
            bres->temp->color[clr] = gradient(draw->coord0->color[clr], draw->coord1->color[clr], bres->i, bres->dy);
        else
            bres->temp->color[clr] = 0xFFFFFF;
        my_mlx_pixel_put(img, bres->temp, vars->map, 1);
        bres->i += 1;
    }
}

void bresenham(t_pixel *coord0, t_pixel *coord1, t_vars *vars, t_data *img)
{
    t_bresenham bres;
    t_pixel temp;
    t_draw draw;
    draw.coord0 = coord0;
    draw.coord1 = coord1;
    int view;
    
    bres.temp = &temp;
    bresenham_init(&bres, coord0, coord0, vars->map);
    my_mlx_pixel_put(img, &temp, vars->map, 1);
    if (bres.dx > bres.dy)
        bresenham_dx_dy(&bres, &draw, img, vars);
    else
        bresenham_dy_dx(&bres, &draw, img, vars);
    
}
