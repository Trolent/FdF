/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:09:36 by trolland          #+#    #+#             */
/*   Updated: 2024/02/16 23:44:57 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

typedef struct s_bresenham
{
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

void bresenham_init(t_bresenham *bres, t_pixel *coord0, t_pixel *coord1, t_map *map)
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

void bresenham_dx_dy(t_bresenham *bres, t_pixel *coord1, t_pixel *coord0, t_vars *vars)
{
    int clr;

    clr = color(vars->map);
    bre->cumul = bre->dx / 2;
    while (bre->i <= bre->dx)
    {
        bre->x0 += bre->inc_x;
        bre->cumul += bre->dy;
        if (bre->cumul >= bre->dx)
        {
            bre->cumul -= bre->dx;
            bre->y0 += bre->inc_y;
        }
        if (coord0->color[clr] != coord1->color[clr])
			temp->color[clr] = gradient(coord0, coord1, bre->i, bre->dx);
        else
            temp->color[clr] = 0xFFFFFF;
        my_mlx_pixel_put(vars->img, temp, vars->map, 1);
        bre->i += 1;
    }
}

void bresenham(t_pixel *coord0, t_pixel *coord1, t_data *vars)
{
    t_bresenham bres;
    t_pixel temp;
    int view;
    
    bresenham_init(&bres, coord0, coord1, vars->map);
    my_mlx_pixel_put(vars->img, &temp, vars->map, 1);
    if (bre.dx > bre.dy)
    
}
