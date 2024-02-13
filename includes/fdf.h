/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:59:55 by trolland          #+#    #+#             */
/*   Updated: 2024/02/13 13:49:13 by trolland         ###   ########.fr       */
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

# if defined(__linux__)
#  include "../mlx_Linux/mlx.h"
#  define ESC_KEY 0xff1b
#  define LEFT_KEY 0xff51
#  define RIGHT_KEY 0xff53
#  define UP_KEY 0xff52
#  define DOWN_KEY 0xff54
#  define L_KEY 0x6c
#  define C_KEY 0x63
# elif defined(__APPLE__)
#  include "../libmlx/mlx.h"
#  define ESC_KEY (53)
#  define LEFT_KEY (124)
#  define RIGHT_KEY 123
#  define UP_KEY 125
#  define DOWN_KEY 126
#  define L_KEY 37
# endif

// DEFINE GRAPHICS
// WINDOW
# define WINDOW_WIDTH 1920 / 3 * 2
# define WINDOW_HEIGHT 1080 / 3 * 2
// COLORS
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

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
}			t_pixel;

typedef struct s_map
{
	t_pixel	**coord;
	int		rows;
	int		columns;
	int		midx;
	int		midy;
	int		line;
	int		zoom;
	int		iso;
	int		angle;
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
int			quit(char *s);
int			quit_map(char *s, t_vars *vars);
void		free_map(t_map *map, int lines);
char		*free_join(char *s1, char *s2);
void		free_map(t_map *map, int lines);
void		map_init(t_map *map);
int			graphics(t_map *map);
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
