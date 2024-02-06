/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:16:38 by trolland          #+#    #+#             */
/*   Updated: 2024/02/06 18:14:34 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int rad(double radians)
{
    return (radians * (180.0 / M_PI));
}
void	print_graph_map(t_map *map, t_data *img)
{
	int	i;
	int	j;
	int gap;
	int x;
	int y;
	
	gap = map->zoom;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns && (map->coord[i][j].y * gap) < WINDOW_WIDTH && (map->coord[i][j].x * gap) < WINDOW_HEIGHT)
		{
			// x =rad(((double)map->coord[i][j].x - (double)map->coord[i][j].z)/sqrt(2));
			// printf(" cos = %d\n",x );
			// y =rad(((double)map->coord[i][j].x+2*(double)map->coord[i][j].y+(double)map->coord[i][j].z)/sqrt(6));
			// printf(" sin = %d\n",y );
			x = (map->coord[i][j].x) * gap;
			y = (map->coord[i][j].y) *gap;
			my_mlx_pixel_put(img, y, x, map->coord[i][j].color);
			j++;
		}
		i++;
	}
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
		quit("end program");
	if (keycode == 0x007a)
		if (vars->map->zoom < 10)
			vars->map->zoom += 1;
	if (keycode == 0x0078)
		if (vars->map->zoom > 0)
			vars->map->zoom -= 1;
	return (0);
}

int mouse_hook(int mousecode, t_vars *vars)
{
	if (mousecode == 4)
		if (vars->map->zoom < 10)
			vars->map->zoom += 1;
	if (mousecode == 5)
		if (vars->map->zoom > 0)
			vars->map->zoom -= 1;
	return(0);
}

int render_next_frame(t_vars *vars)
{
	t_data new;
	new.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	new.addr = mlx_get_data_addr(new->img, new->bits_per_pixel, new->line_length, new->endian);;
	
	free(vars->img);
	vars->img = &new;

	// vars->img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length,
			// &vars->img->endian);
	print_graph_map(vars->map, vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return(0);
}

int	graphics(t_map *map)
{
	t_vars	vars;

	vars.map = map;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		quit(ERROR_MLX);
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (!vars.win)
		return (free(vars.mlx), quit(ERROR_MLX));
	vars.img->img = mlx_new_image(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.img->addr = mlx_get_data_addr(vars.img->img, &vars.img->bits_per_pixel, &vars.img->line_length,
			&vars.img->endian);
	print_graph_map(vars.map, vars.img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img->img, 0, 0);
	// sleep(5);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	// free(img.img);
	// mlx_destroy_window(mlx, mlx_win);
	// mlx_destroy_display(mlx);
	// free(mlx);
	return(0);
}
