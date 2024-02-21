/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:59:55 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 11:38:52 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "error_maps.h"
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# if defined(__linux__)
#  include "../minilibx-linux/mlx.h"
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
# define BLACK 0x000000
# define BACKGROUND 0x151515

# define X 0
# define Y 1
# define Z 2

# define ORG 0
# define ISO 1

# define ORGCLR 0
# define ALTCLR 1

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_pixel
{
	double		x[2];
	double		y[2];
	double		z[2];
	int			color[2];
}				t_pixel;

typedef struct s_bresenham
{
	t_pixel		*temp;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			inc_x;
	int			inc_y;
	int			len;
	int			i;
	int			err;
	int			err2;
}				t_bresenham;

typedef struct s_draw
{
	t_pixel		*coord0;
	t_pixel		*coord1;
}				t_draw;

typedef struct s_map
{
	t_pixel		**coord;
	int			rows;
	int			columns;
	bool		top;
	int			mid[2];
	float		zoom;
	bool		line;
	bool		diag;
	bool		iso;
	double		angle[3];
	int			translate[3];
	int			z_color;
	int			z_min;
	int			z_max;
	double			z_range;
}				t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_data		*img;
}				t_vars;

// PARSING UTILS //
int				parse(t_map *map, char *file);
void			free_map(t_map *map, int lines);
char			*free_join(char *s1, char *s2);
void			free_map(t_map *map, int lines);
void			map_init(t_map *map);
int				special_atoi(const char *str, int *index);
int				strvalue(char c);
unsigned int	special_atoi_hex(const char *str, int *index);
int				check_columns(char **split, int rows);
void			asign_values(t_map *map, char **split);

// WINDOW / MLX MANAGEMENT //
int				quit(char *s);
int				quit_map(char *s, t_vars *vars);
int				graphics(t_vars *map);
int				create_win_mlx(t_vars *vars, t_map *map);
int				mlx_handle_input(t_vars *vars);
int				render_next_frame(t_vars *vars);
int				cross_close(t_vars *vars);
void			close_mlx(t_vars *vars);
void			make_menu(t_vars *vars, t_data *img);

// ROTATION MANAGEMENT //
int				define_iso(t_map *map);
void	z_ratio(t_pixel *point, t_map *map);
void	rotate_x(t_pixel *point, double angle, t_map *map);
void	rotate_y(t_pixel *point, double angle, t_map *map);
void	rotate_z(t_pixel *point, double angle, t_map *map);

// COLOR MANAGEMENT //
double			get_r(int trgb);
double			get_g(int trgb);
double			get_b(int trgb);
int				create_rgb(int r, int g, int b);
int				gradient(int color_start, int color_end, int len, int pos);
void			bresenham(t_pixel *coord0, t_pixel *coord1, t_vars *vars,
					t_data *img);
void			my_mlx_pixel_put(t_data *data, t_pixel *pixel, t_map *map);

// utils //
int				color(t_map *map);

#endif

/* *x = (*x - *y) * cos(angle);
*y = (*x + *y) * sin(angle) - z;

M_PI / 4 = angle 45 degres */
