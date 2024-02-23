/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:53:47 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 17:16:58 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw(t_vars *vars, int i, int j, t_data *img)
{
	my_mlx_pixel_put(img, &vars->map->coord[i][j], vars->map);
	if (i + 1 < vars->map->rows && vars->map->line == 1)
		bresenham(&vars->map->coord[i][j], &vars->map->coord[i + 1][j], vars,
			img);
	if (j + 1 < vars->map->columns && vars->map->line == 1)
		bresenham(&vars->map->coord[i][j], &vars->map->coord[i][j + 1], vars,
			img);
	if (j + 1 < vars->map->columns && i + 1 < vars->map->rows
		&& vars->map->line == 1 && vars->map->diag == 1)
		bresenham(&vars->map->coord[i][j], &vars->map->coord[i + 1][j + 1],
			vars, img);
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
				draw(vars, i, j, img);
			j++;
		}
		i++;
	}
}

void	generate_map(t_vars *vars, t_map *map, t_data *img)
{
	make_background(img);
	define_iso(map);
	print_graph_map(vars, vars->map, img);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	make_menu(vars);
}

int	render_next_frame(t_vars *vars)
{
	t_data	*new_img;

	new_img = malloc(sizeof(t_data));
	if (!new_img)
		return (mlx_loop_end(vars->mlx), 0);
	new_img->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!new_img->img)
		return (free(new_img), mlx_loop_end(vars->mlx), 0);
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel,
			&new_img->line_length, &new_img->endian);
	if (!new_img->addr)
		return (free(new_img), mlx_loop_end(vars->mlx), 0);
	generate_map(vars, vars->map, new_img);
	if (vars->img)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
		free(vars->img);
	}
	vars->img = new_img;
	return (0);
}

int	graphics(t_vars *vars)
{
	create_win_mlx(vars, vars->map);
	define_zoom(vars->map);
	define_z_relations(vars->map);
	generate_map(vars, vars->map, vars->img);
	mlx_handle_input(vars);
	mlx_loop(vars->mlx);
	close_mlx(vars);
	return (0);
}
