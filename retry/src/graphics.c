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

void	my_mlx_pixel_put(t_data *data, t_pixel *pixel, t_map *map, int zoom, int j)
{
	char	*dst;
	int		x;
	int		y;

	if (zoom == 1)
	{
		if (map->top == 1)
		{
			x = pixel->x * map->zoom + map->midx;
			y = pixel->y * map->zoom + map->midy;
		}
		else if (map->iso == 1)
		{
			x = pixel->iso_x * map->zoom + map->midx;
			y = pixel->iso_y * map->zoom + map->midy;
		}
	}
	else
	{
		if (map->iso == 1)
		{
			y = pixel->iso_y;
			x = pixel->iso_x;
		}
		else if (map->top == 1)
		{
			y = pixel->y;
			x = pixel->x;
		}
	}
	if (x < 0 || y < 0 || x > WINDOW_HEIGHT || y > WINDOW_WIDTH)
		return ;
	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = pixel->color;
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

	x0 = coord0->x * map->zoom + map->midx;
	y0 = coord0->y * map->zoom + map->midy;
	x1 = coord1->x * map->zoom + map->midx;
	y1 = coord1->y * map->zoom + map->midy;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = dx - dy;
	pixel = sqrt(dx * dx + dy * dy);
	len = pixel;

	int j = 0;
	while (x0 != x1 || y0 != y1)
	{
		temp.x = x0;
		temp.y = y0;
		if (map->z_color == 1)
			temp.color = gradient(coord0->alt_color, coord1->alt_color, len, len
					- pixel);
		else
		{
			temp.color = gradient(coord0->color, coord1->color, len, len
					- pixel);
		}
		if (temp.x > 0 && temp.x < WINDOW_HEIGHT && temp.y < WINDOW_WIDTH
			&& temp.y > 0)
		{
			my_mlx_pixel_put(img, &temp, map, 0, j);
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
	my_mlx_pixel_put(img, &map->coord[i][j], map, 1, 0);
	if (i + 1 < map->rows && map->line == 1)
		draw_line(&map->coord[i][j], &map->coord[i + 1][j], img, map);
	if (j + 1 < map->columns && map->line == 1)
		draw_line(&map->coord[i][j], &map->coord[i][j + 1], img, map);
}

void	print_top_view(t_map *map, t_data *img)
{
	int	i;
	int	j;
	int	gap;

	gap = map->zoom;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns && (map->coord[i][j].y * gap
				+ map->midy) < WINDOW_WIDTH && (map->coord[map->rows
				- 1][map->columns - 1].y * gap + map->midy) > 0
			&& (map->coord[i][j].x * gap + map->midx) < WINDOW_HEIGHT
			&& (map->coord[map->rows - 1][map->columns - 1].x * gap
				+ map->midx) > 0)
		{
			draw(img, map, i, j);
			j++;
		}
		i++;
	}
}

void	print_iso_view(t_map *map, t_data *img)
{
	int	i;
	int	j;
	int	gap;

	gap = map->zoom;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns && (map->coord[i][j].iso_y * gap
				+ map->midy) < WINDOW_WIDTH && (map->coord[map->rows
				- 1][map->columns - 1].iso_y * gap + map->midy) > 0
			&& (map->coord[i][j].iso_x * gap + map->midx) < WINDOW_HEIGHT
			&& (map->coord[map->rows - 1][map->columns - 1].iso_x * gap
				+ map->midx) > 0)
		{
			draw(img, map, i, j);
			j++;
		}
		i++;
	}
}

void	print_graph_map(t_map *map, t_data *img)
{
	if (map->top == 1 && map->iso == 0)
		print_top_view(map, img);
	else if (map->iso == 1 && map->top == 0)
		print_iso_view(map, img);
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

int	define_iso(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			map->coord[i][j].iso_x = (map->coord[i][j].x - map->coord[i][j].y)
				* cos(map->angle[X]) - map->coord[i][j].z * sin(map->angle[Z]
					+ 1);
			map->coord[i][j].iso_y = (map->coord[i][j].x + map->coord[i][j].y)
				* cos(map->angle[Y]);
			j++;
		}
		i++;
	}
	return (0);
}
#define PASTEL_BLUE 0x6fa8dc
#define PASTEL_GREEN 0x49ab82
#define PASTEL_RED 0xe05e5d

float clamp(float val, float min, float max)
{
	if (val < min)
		return (min);
	if (val > max)
		return (max);
	return (val);
}

float smoothstep(float edge0, float edge1, float x) {
    // Scale, bias and saturate x to 0..1 range
    x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
    // Evaluate polynomial
    return x * x * (3 - 2 * x);
}

int	smooth_gradient(int color_start, int color_end, int len, int pos)
{
	double	delta[3];
	int		new[3];
	int		newcolor;
	
	if(color_start == color_end)
		return(color_end);
	new[0] = get_r(color_start) + smoothstep(0, fabs(get_r(color_end) - (get_r(color_start))), pos / len);
	new[1] = get_g(color_start) + smoothstep(0, fabs(get_g(color_end) - (get_g(color_start))), pos / len);
	new[2] = get_b(color_start) + smoothstep(0, fabs(get_b(color_end) - (get_b(color_start))), pos / len);
	newcolor = create_rgb(new[0], new[1], new[2]);
	return (newcolor);
}
// 
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
			if (map->z_max == map->z_min || map->coord[i][j].z == 0)
				map->coord[i][j].alt_color = PASTEL_GREEN;
			else if (map->coord[i][j].z > 0)
				map->coord[i][j].alt_color = gradient(PASTEL_GREEN, PASTEL_RED,
				  		map->z_max, map->coord[i][j].z);
			else if (map->coord[i][j].z < 0 )
				map->coord[i][j].alt_color = gradient(PASTEL_BLUE, PASTEL_GREEN,
				  		map->z_max, map->coord[i][j].z);
			j++;
		}
		i++;
	}
	return (0);
}

int	graphics(t_map *map)
{
	t_vars	vars;

	create_win_mlx(&vars, map);
	define_iso(map);
	define_alt_color(map);
	print_graph_map(vars.map, vars.img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	mlx_handle_input(&vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	// mlx_destroy_display(vars.mlx);
	return (0);
}
