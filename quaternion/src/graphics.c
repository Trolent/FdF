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

void	my_mlx_pixel_put(t_data *data, t_pixel *pixel, t_map *map)
{
	char	*dst;
	float	x;
	float	y;
	int		clr;

	clr = color(map);
	y = (int)pixel->y[ISO];
	x = (int)pixel->x[ISO];
	if (x < 0 || y < 0 || y > WINDOW_HEIGHT || x > WINDOW_WIDTH)
		return ;
	dst = data->addr + (int)(y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = pixel->color[clr];
}

void	draw(t_vars *vars, t_map *map, int i, int j, t_data *img)
{
	my_mlx_pixel_put(img, &map->coord[i][j], map);
	if (i + 1 < map->rows && map->line == 1)
		bresenham(&map->coord[i][j], &map->coord[i + 1][j], vars, img);
	if (j + 1 < map->columns && map->line == 1)
		bresenham(&map->coord[i][j], &map->coord[i][j + 1], vars, img);
	if (j + 1 < map->columns && i + 1 < map->rows && map->line == 1
		&& map->diag == 1)
		bresenham(&map->coord[i][j], &map->coord[i + 1][j + 1], vars, img);
}

int	verify_fit(t_map *map, int i, int j)
{
	if (map->coord[i][j].x[ISO] < WINDOW_WIDTH
		&& map->coord[i][j].y[ISO] < WINDOW_HEIGHT
		&& map->coord[i][j].x[ISO] > 0 && map->coord[i][j].y[ISO] > 0)
		return (1);
	if (i + 1 < map->rows)
		if (map->coord[i + 1][j].x[ISO] < WINDOW_WIDTH && map->coord[i
			+ 1][j].y[ISO] < WINDOW_HEIGHT && map->coord[i + 1][j].x[ISO] > 0
			&& map->coord[i + 1][j].y[ISO] > 0)
			return (1);
	if (j + 1 < map->columns)
		if (map->coord[i][j + 1].x[ISO] < WINDOW_WIDTH && map->coord[i][j
			+ 1].y[ISO] < WINDOW_HEIGHT && map->coord[i][j + 1].x[ISO] > 0
			&& map->coord[i][j + 1].y[ISO] > 0)
			return (1);
	return (0);
}

void	print_graph_map(t_vars *vars, t_map *map, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (verify_fit(map, i, j))
				draw(vars, map, i, j, img);
			j++;
		}
		i++;
	}
}

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	make_background(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			put_pixel(img, j, i, BACKGROUND);
			j++;
		}
		i++;
	}
}

void	generate_map(t_vars *vars, t_map *map,t_data *img)
{
	make_background(img);
	print_graph_map(vars, vars->map, img);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	make_menu(vars, img);
	
}

int	render_next_frame(t_vars *vars)
{
	t_data	*new_img;

	new_img = malloc(sizeof(t_data));
	if (!new_img)
		quit(ERROR_MLX);
		// return (mlx_loop_end(vars->mlx), 0);
	new_img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!new_img->img)
		return (free(new_img)/* , mlx_loop_end(vars->mlx) */, 0);
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel,
			&new_img->line_length, &new_img->endian);
	if (!new_img->addr)
		return (free(new_img), /* mlx_loop_end(vars->mlx), */ 0);
	generate_map(vars, vars->map, new_img);
	if (vars->img)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
		free(vars->img);
	}
	vars->img = new_img;
	return (0);
}

void define_z_range(t_map *map)
{
	map->z_range = map->z_max / map->rows;
	if (map->z_range < 1)
		map->z_range = 1;
}

void define_alt_color(t_map *map, t_pixel *point)
{
	if (map->z_max == map->z_min)
		point->color[ALTCLR] = WHITE;
	else if (point->z[ORG] == 0)
		point->color[ALTCLR] = GREEN;
	else if (point->z[ORG] > 0)
		point->color[ALTCLR] = gradient(GREEN, RED,
				map->z_max, point->z[ORG]);
	else if (point->z[ORG] < 0)
		point->color[ALTCLR] = gradient(GREEN, BLUE,
				-map->z_min, -point->z[ORG]);

}

int	define_z_relations(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	define_z_range(map);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			define_alt_color(map, &map->coord[i][j]);
			map->coord[i][j].z[ISO] = map->coord[i][j].z[ORG] / map->z_range;
			j++;
		}
		i++;
	}
	return (0);
}

void	define_zoom(t_map *map)
{
	float	i;

	i = 1;
	while (1)
	{
		if ((map->rows - 1) * i < WINDOW_HEIGHT && (map->columns - 1)
			* i < WINDOW_WIDTH)
			i += 0.2;
		else
		{
			if (i > 1)
				i -= 0.2;
			break ;
		}
	}
	map->zoom = i;
	map->mid[X] = (WINDOW_WIDTH / 2);
	map->mid[Y] = (WINDOW_HEIGHT / 2);
}

int	graphics(t_vars *vars)
{
	create_win_mlx(vars, vars->map);
	define_zoom(vars->map);
	define_iso(vars->map);
	define_z_relations(vars->map);
	generate_map(vars, vars->map, vars->img);
	mlx_handle_input(vars);
	mlx_loop(vars->mlx);
	close_mlx(vars);
	return (0);
}
