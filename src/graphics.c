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
#include <mlx.h>

void	my_mlx_pixel_put(t_data *data, t_pixel *pixel, t_map *map, int zoom)
{
	char	*dst;
	int		x;
	int		y;
	if (zoom == 1)
	{
		x = pixel->x * map->zoom;
		y = pixel->y * map->zoom;
	}
	else
	{
		y = pixel->y;
		x = pixel->x;
	}
	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = pixel->color;
}


void draw_line(t_pixel *coord0, t_pixel *coord1, t_data *img, t_map *map) {
    int x0 = coord0->x * map->zoom;
    int y0 = coord0->y * map->zoom;
    int x1 = coord1->x * map->zoom;
    int y1 = coord1->y * map->zoom;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
	printf("sx = %d\n", sx);
	printf("sy = %d\n", sy);
	t_pixel temp;

    while (x0 != x1 || y0 != y1) {
		temp.x = x0;
		temp.y = y0;
		temp.color = RED;
		if (temp.x < WINDOW_HEIGHT && temp.y < WINDOW_WIDTH)
        	my_mlx_pixel_put(img, &temp, map, 0);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 +=sy;
        }
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
		while (j < map->columns && (map->coord[i][j].y * gap) < WINDOW_WIDTH
			&& (map->coord[i][j].x * gap) < WINDOW_HEIGHT)
		{
			// x =rad(((double)map->coord[i][j].x
			// - (double)map->coord[i][j].z)/sqrt(2));
			// printf(" cos = %d\n",x );
			// y =rad(((double)map->coord[i][j].x+2*(double)map->coord[i][j].y+(double)map->coord[i][j].z)/sqrt(6));
			// printf(" sin = %d\n",y );
			my_mlx_pixel_put(img, &map->coord[i][j], map, 1);
			if (i + 1 < map->rows)
				draw_line(&map->coord[i][j], &map->coord[i+1][j], img, map);
			if (j + 1 < map->columns)
				draw_line(&map->coord[i][j], &map->coord[i][j+ 1], img, map);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 0xff1b)
		quit_map("end program", vars);
	if (keycode == 0x007a && vars->map->zoom < 10)
		vars->map->zoom += 1;
	if (keycode == 0x0078 && vars->map->zoom > 0)
		vars->map->zoom -= 1;
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		vars->map->zoom += 1;
	if (button == 5 && vars->map->zoom > 1)
		vars->map->zoom -= 1;
	return (0);
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

int	mlx_handle_input(t_vars *vars)
{
	mlx_mouse_hook(vars->win, (int (*)())mouse_scroll, vars);
	mlx_key_hook(vars->win, &key_hook, vars);
	return(1);
}

int	graphics(t_map *map /* , char *str */)
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
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
