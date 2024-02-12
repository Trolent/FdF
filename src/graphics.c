/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:16:38 by trolland          #+#    #+#             */
/*   Updated: 2024/02/07 17:59:44rolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// #include <mlx.h>

void	my_mlx_pixel_put(t_data *data, t_pixel *pixel, t_map *map, int zoom)
{
	char	*dst;
	int		x;
	int		y;

	if (zoom == 1)
	{
		x = pixel->x * map->zoom + map->midx;
		y = pixel->y * map->zoom + map->midy;
	}
	else
	{
		y = pixel->y;
		x = pixel->x;
	}
	if (x < 0 || y < 0 || x > WINDOW_HEIGHT || y > WINDOW_WIDTH)
		return;
	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = pixel->color;
}

int ft_round(float num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= 0.5)
		rounded++;
	return (rounded);
}

int gradient(int color_start, int color_end, int len, int pos)
{
	float	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((color_end >> 16) - \
					(color_start >> 16)) / (double)len;
	increment[1] = (double)(((color_end >> 8) & 0xFF) - \
					((color_start >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((color_end & 0xFF) - (color_start & 0xFF)) \
					/ (double)len;
	new[0] = (color_start >> 16) + ft_round(pos * increment[0]);
	new[1] = ((color_start >> 8) & 0xFF) + ft_round(pos * increment[1]);
	new[2] = (color_start & 0xFF) + ft_round(pos * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

void	draw_line(t_pixel *coord0, t_pixel *coord1, t_data *img, t_map *map)
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	t_pixel	temp;
	int		e2;

	x0 = coord0->x * map->zoom + map->midx;
	y0 = coord0->y * map->zoom + map->midy;
	x1 = coord1->x * map->zoom + map->midx;
	y1 = coord1->y * map->zoom + map->midy;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = dx - dy;

	int pixel = sqrt(dx * dx + dy * dy);
	int len = pixel;

	while (x0 != x1 || y0 != y1)
	{
		temp.x = x0;
		temp.y = y0;
		temp.color = gradient(coord0->color, coord1->color, len, len -pixel);
		if (temp.x > 0 && temp.x < WINDOW_HEIGHT && temp.y < WINDOW_WIDTH
			&& temp.y > 0)
			my_mlx_pixel_put(img, &temp, map, 0);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
		pixel--;
	}
}

void	print_graph_map(t_map *map, t_data *img)
{
	int	i;
	int	j;
	int	gap;
	int	x;
	int	y;

	gap = map->zoom;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns && (map->coord[i][j].y * gap + map->midy) < WINDOW_WIDTH
			&& (map->coord[map->rows - 1][map->columns - 1].y * gap + map->midy) > 0
			&& (map->coord[i][j].x * gap + map->midx) < WINDOW_HEIGHT
			&& (map->coord[map->rows - 1][map->columns - 1].x * gap + map->midx) > 0)
		{
			my_mlx_pixel_put(img, &map->coord[i][j], map, 1);
			if (i + 1 < map->rows)
				draw_line(&map->coord[i][j], &map->coord[i + 1][j], img, map);
			if (j + 1 < map->columns)
				draw_line(&map->coord[i][j], &map->coord[i][j + 1], img, map);
			j++;
		}
		i++;
	}
}

int	render_next_frame(t_vars *vars)
{
	t_data	*new_img;

	new_img = malloc(sizeof(t_data));
	if (!new_img)
		quit("Error: Unable to allocate memory for new_img");
	new_img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!new_img->img)
	{
		free(new_img);
		quit("Error: Unable to create new image with mlx_new_image");
	}
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel,
			&new_img->line_length, &new_img->endian);
	if (!new_img->addr)
	{
		free(new_img);
		mlx_destroy_image(vars->mlx, new_img->img);
		quit_map("Error: Unable to get data address for new_img", vars);
	}
	print_graph_map(vars->map, new_img);
	mlx_put_image_to_window(vars->mlx, vars->win, new_img->img, 0, 0);
	if (vars->img)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
		free(vars->img);
	}
	vars->img = new_img;
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);
	if (keycode == ESC_KEY)
		quit_map("stop", vars);
	// mlx_loop_end(vars->mlx);
	if (keycode == LEFT_KEY && vars->map->midy >= vars->map->zoom
		- vars->map->zoom * vars->map->columns)
		vars->map->midy -= 1 * vars->map->zoom / 4 + 1;
	if (keycode == RIGHT_KEY && vars->map->midy < WINDOW_WIDTH
		- vars->map->zoom)
		vars->map->midy += 1 * vars->map->zoom / 4 + 1;
	if (keycode == UP_KEY && vars->map->midx >= vars->map->zoom
		- vars->map->zoom * vars->map->rows)
		vars->map->midx -= 1 * vars->map->zoom / 4 + 1;
	if (keycode == DOWN_KEY && vars->map->midx < WINDOW_HEIGHT
		- vars->map->zoom)
		vars->map->midx += 1 * vars->map->zoom / 4 + 1;
	render_next_frame(vars);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_vars *vars)
{
	int	i;

	i = vars->map->zoom / 10 + 1;
	if (button == 4 && vars->map->zoom < 100000)
		vars->map->zoom += i;
	if (button == 5 && vars->map->zoom > 1)
		vars->map->zoom -= i;
	render_next_frame(vars);
	return (0);
}

int	mlx_handle_input(t_vars *vars)
{
	mlx_mouse_hook(vars->win, (int (*)())mouse_scroll, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	return (1);
}

int	graphics(t_map *map)
{
	t_vars	vars;

	vars.map = map;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		quit(ERROR_MLX);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "hello");
	if (!vars.win)
		return (free(vars.mlx), quit(ERROR_MLX));
	vars.img = malloc(sizeof(t_data));
	if (!vars.img)
		quit("Error: Unable to allocate memory for img");
	vars.img->img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.img->addr = mlx_get_data_addr(vars.img->img, &vars.img->bits_per_pixel,
			&vars.img->line_length, &vars.img->endian);
	print_graph_map(vars.map, vars.img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	mlx_handle_input(&vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	// mlx_destroy_display(vars.mlx);
	return (0);
}
