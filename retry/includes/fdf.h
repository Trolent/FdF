/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:59:55 by trolland          #+#    #+#             */
/*   Updated: 2024/02/14 12:52:07 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "error_maps.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

# if defined(__linux__)
#  include "../mlx_Linux/mlx.h"
#  define WINDOW_WIDTH 1920
#  define WINDOW_HEIGHT 1080
# elif defined(__APPLE__)
#  include "../libmlx/mlx.h"
#  define WINDOW_WIDTH 1920 / 3 * 2
#  define WINDOW_HEIGHT 1080 / 3 * 2
# endif

// COLORS
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define X 0
# define Y 1
# define Z 2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_pixel
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		iso_x;
	int		iso_y;
	int		alt_color;
}			t_pixel;

typedef struct s_map
{
	t_pixel	**coord;
	int		rows;
	int		columns;
	bool	top;
	int		midx;
	int		midy;
	int		zoom;
	int		line;
	bool	iso;
	float	angle[3];
	int		z_color;
	int		z_min;
	int		z_max;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	*img;
}			t_vars;

int			parse(t_map *map, char *file);
void		free_map(t_map *map, int lines);
char		*free_join(char *s1, char *s2);
void		free_map(t_map *map, int lines);
void		map_init(t_map *map);

// WINDOW / MLX MANAGEMENT //
int			quit(char *s);
int			quit_map(char *s, t_vars *vars);
int			graphics(t_map *map);
int			create_win_mlx(t_vars *vars, t_map *map);
int			mlx_handle_input(t_vars *vars);
int			render_next_frame(t_vars *vars);

// COLOR MANAGEMENT //
double		get_r(int trgb);
double		get_g(int trgb);
double		get_b(int trgb);
int			create_rgb(int r, int g, int b);
int			gradient(int color_start, int color_end, int len, int pos);

void	print_map(t_map *map); // =========> must be commented before submiting

#endif

/* *x = (*x - *y) * cos(angle);
*y = (*x + *y) * sin(angle) - z;

M_PI / 4 = angle 45 degres */
