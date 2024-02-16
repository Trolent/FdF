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
	int		view;
	int		clr;

	if (map->z_color == 1)
		clr = ALTCLR;
	else
		clr = ORGCLR;
	if (map->iso == 1)
		view = ISO;
	else
		view = TOP;
	if (zoom == 1)
	{
		x = pixel->x[view] * map->zoom + map->midx;
		y = pixel->y[view] * map->zoom + map->midy;
	}
	else
	{
		y = pixel->y[view];
		x = pixel->x[view];
	}
	if (x < 0 || y < 0 || y > WINDOW_HEIGHT || x > WINDOW_WIDTH)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = pixel->color[clr];
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
	int		pixel;
	int		len;
	int		view;
	int		clr;
	int		j;

	if (map->z_color == 1)
		clr = ALTCLR;
	else
		clr = ORGCLR;
	if (map->iso == 1)
		view = ISO;
	else
		view = TOP;
	x0 = coord0->x[view] * map->zoom + map->midx;
	y0 = coord0->y[view] * map->zoom + map->midy;
	x1 = coord1->x[view] * map->zoom + map->midx;
	y1 = coord1->y[view] * map->zoom + map->midy;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = dx - dy;
	pixel = sqrt(dx * dx + dy * dy);
	len = pixel;
	j = 0;
	while (x0 != x1 || y0 != y1)
	{
		temp.x[view] = x0;
		temp.y[view] = y0;
		temp.color[clr] = gradient(coord0->color[clr], coord1->color[clr], len,
				len - pixel);
		if (temp.x[view] > 0 && temp.x[view] < WINDOW_WIDTH
			&& temp.y[view] < WINDOW_HEIGHT && temp.y[view] > 0)
		{
			my_mlx_pixel_put(img, &temp, map, 0);
			j++;
		}
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

void	draw(t_data *img, t_map *map, int i, int j)
{
	my_mlx_pixel_put(img, &map->coord[i][j], map, 1);
	if (i + 1 < map->rows && map->line == 1)
		draw_line(&map->coord[i][j], &map->coord[i + 1][j], img, map);
	if (j + 1 < map->columns && map->line == 1)
		draw_line(&map->coord[i][j], &map->coord[i][j + 1], img, map);
}

void	print_graph_map(t_map *map, t_data *img)
{
	int	i;
	int	j;
	int	gap;
	int	view;

	if (map->iso == 1)
		view = ISO;
	else
		view = TOP;
	gap = map->zoom;
	i = -1;
	while (++i < map->rows)
	{
		j = 0;
		while (j < map->columns && (map->coord[i][j].y[view] * gap
				+ map->midy) < WINDOW_HEIGHT && (map->coord[map->rows
				- 1][map->columns - 1].y[view] * gap + map->midy) > 0
			&& (map->coord[i][j].x[view] * gap + map->midx) < WINDOW_WIDTH
			&& (map->coord[map->rows - 1][map->columns - 1].x[view] * gap
				+ map->midx) > 0)
		{
			draw(img, map, i, j);
			j++;
		}
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

int	define_alt_color(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->z_max == map->z_min || map->coord[i][j].z[TOP] == 0)
				map->coord[i][j].color[ALTCLR] = GREEN;
			else if (map->coord[i][j].z[TOP] > 0)
				map->coord[i][j].color[ALTCLR] = gradient(GREEN, RED, map->z_max
						- map->z_min, map->coord[i][j].z[TOP] - map->z_min);
			else if (map->coord[i][j].z[TOP] < 0)
				map->coord[i][j].color[ALTCLR] = gradient(BLUE, GREEN,
						map->z_max - map->z_min, map->coord[i][j].z[TOP]
						- map->z_min);
			j++;
		}
		i++;
	}
	return (0);
}

void	define_zoom(t_map *map)
{
	int	i;

	i = 1;
	while (1)
	{
		if ((map->rows - 1) * i < WINDOW_HEIGHT && (map->columns - 1)
			* i < WINDOW_WIDTH)
			i += i / 10 + 1;
		else
		{
			if (i > 1)
				i -= i / 10 + 1;
			break ;
		}
	}
	map->zoom = i;
	map->midx = (WINDOW_WIDTH / 2) - ((map->columns - 1) * map->zoom / 2);
	map->midy = (WINDOW_HEIGHT / 2) - ((map->rows - 1) * map->zoom / 2);
}

int	graphics(t_map *map)
{
	t_vars	vars;

	create_win_mlx(&vars, map);
	define_zoom(map);
	define_iso(map);
	define_alt_color(map);
	print_graph_map(vars.map, vars.img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	mlx_handle_input(&vars);
	mlx_loop(vars.mlx);
	close_mlx(&vars);
	return (0);
}
