/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:09:36 by trolland          #+#    #+#             */
/*   Updated: 2024/02/18 21:15:22 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
    bres->i = 1;
    bres->len = ft_max(bres->dx, bres->dy);
    bres->err = bres->dx - bres->dy;
}

void bresenham_print(t_bresenham *bres, t_draw *draw, t_data *img, t_vars *vars)
{
    int clr;
    int view;
    
    view = perspec(vars->map);
    clr = color(vars->map);
    while (bres->i <= bres->len)
    {
        bres->temp->x[view] = bres->x0;
        bres->temp->y[view] = bres->y0;
        bres->temp->color[clr] = gradient(draw->coord0->color[clr], draw->coord1->color[clr], bres->len, bres->i);
        if(bres->temp->x[view] > 0 && bres->temp->x[view] < WINDOW_WIDTH && bres->temp->y[view] < WINDOW_HEIGHT && bres->temp->y[view] > 0)
            my_mlx_pixel_put(img, bres->temp, vars->map);
        bres->err2 = 2 * bres->err;
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

void bresenham(t_pixel *coord0, t_pixel *coord1, t_vars *vars, t_data *img)
{
    t_bresenham bres;
    t_pixel temp;
    t_draw draw;
    int view;
    int clr;
    
    clr = color(vars->map);
    view = perspec(vars->map);
    draw.coord0 = coord0;
    draw.coord1 = coord1;
    bres.temp = &temp;
    bresenham_init(&bres, coord0, coord1, vars->map);
    bresenham_print(&bres, &draw, img, vars);
}
