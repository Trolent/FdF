/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:53:47 by trolland          #+#    #+#             */
/*   Updated: 2024/05/30 12:07:07 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
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

void	my_mlx_pixel_put(t_data *data, t_pixel *pixel, t_map *map)
{
	char	*dst;
	double	x;
	double	y;
	int		clr;

	clr = color(map);
	y = pixel->y[ISO];
	x = pixel->x[ISO];
	if ((int)(round(x)) < 0 || (int)(round(y)) < 0 || \
	(int)(round(y)) >= WINDOW_HEIGHT || (int)(round(x)) >= WINDOW_WIDTH)
		return ;
	dst = data->addr + (int)(round(y) * data->line_length + round(x)
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)pixel->color[clr];
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
