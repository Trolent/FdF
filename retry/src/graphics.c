/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:16:38 by trolland          #+#    #+#             */
/*   Updated: 2024/02/02 18:35:46 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	graphics(t_map *map)
{
    void	*mlx;
	void	*mlx_win;
	t_data	img;
    t_vars	vars;

	mlx = mlx_init();
    if (mlx == NULL)
        quit(ERROR_MLX);
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
    if (mlx_win == NULL)
        return(free(mlx), quit(ERROR_MLX));
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 9, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 9, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // mlx_loop_hook(mlx, &img, img);
    // mlx_key_hook(vars.win, mlx_key_hook, &vars);
	sleep(5);
    
    mlx_destroy_window(mlx, mlx_win);
    mlx_destroy_display(mlx);
    free(mlx);
}
