/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:59:55 by trolland          #+#    #+#             */
/*   Updated: 2024/05/30 12:18:25 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "error_maps.h"
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

# if defined(__linux__)
#  include "../minilibx-linux/mlx.h"
#  define WINDOW_WIDTH 1920 / 3 * 2
#  define WINDOW_HEIGHT 1080 / 3 * 2
#  define NORMAL_EXIT(vars) mlx_loop_end(vars->mlx)
#  define ERROR_EXIT(vars) mlx_loop_end(vars->mlx)
#  define DESTROY(vars) mlx_destroy_display(vars->mlx)
# elif defined(__APPLE__)
#  include "../minilibx_macos/mlx.h"
#  define WINDOW_WIDTH 1400
#  define WINDOW_HEIGHT 900
#  define NORMAL_EXIT(vars) free_exit(vars)
#  define ERROR_EXIT(vars) quit_map(vars)
#  define DESTROY(vars) "\\"
# endif

// COLORS
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BACKGROUND 0x202020

// COORDINATES
# define X 0
# define Y 1
# define Z 2

// D
# define ORG 0
# define ISO 1

// ALT OR MAP COLORS
# define ORGCLR 0
# define ALTCLR 1

/*struct for the mlx image*/
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

/*struct for every coordinate.
- x[0], y[0], z[0] are the original coordinates;
- x[1], y[1], z[1] are the iso coordinates;
- color[0] is the original color;
- color[1] is the altitude color.*/
typedef struct s_pixel
{
	double	x[2];
	double	y[2];
	double	z[2];
	int		color[2];
}			t_pixel;

/*struct containing the map and its visual properties*/
typedef struct s_map
{
	t_pixel	**coord;
	int		rows;
	int		columns;
	int		mid[2];
	float	zoom;
	bool	line;
	bool	diag;
	int		angle[3];
	int		z_color;
	int		z_min;
	int		z_max;
	double	z_range;
}			t_map;

/*struct containing the mlx elements and the map*/
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	*img;
}			t_vars;

/* ************************************************************************** */
/* ***************************** PARSING UTILS ****************************** */
/* ************************************************************************** */

/*parses the file and creates the map into a struct tab pixel*/
int			parse(t_map *map, char *file);
/*free the map*/
void		free_map(t_map *map, int size);
/*join two strings s1 and s2 and free s1*/
char		*free_join(char *s1, char *s2);
/*initialize the map struct for zoom, line, angle and z_range*/
void		map_init(t_map *map);
/*atoi with index incrementation*/
int			special_atoi(const char *str, int *index);
/*atoi with index incrementation for hexadecimal values*/
int			special_atoi_hex(const char *str, int *index);
/*check if the number of columns is the same for each row*/
int			check_columns(char **split, int rows);
/*assign values to the map struct for each coordinate*/
void		asign_values(t_map *map, char **split);

/* ************************************************************************** */
/* ****************************** WINDOW UTILS ****************************** */
/* ************************************************************************** */

/*quit the program with an error message*/
int			quit(char *s);
/*quit the program with an error message, free the map and destroy the window*/
int			quit_map(t_vars *vars);
/*initialize the mlx elements, graphipcs and the loop*/
int			graphics(t_vars *map);
/*add the menu to the window*/
void		make_menu(t_vars *vars);
/*create the mlx window, and the image. Start the graphics*/
int			create_win_mlx(t_vars *vars, t_map *map);
/*handle the key and mouse input from the user*/
int			mlx_handle_input(t_vars *vars);
/*render the next frame*/
int			render_next_frame(t_vars *vars);
/*ends the loop and let mlx end*/
int			key_esc_or_cross_close(t_vars *vars);
/*free all the mlx elements*/
void		close_mlx(t_vars *vars);
/*On mac os, close and free the program noramlly*/
int	free_exit(t_vars *vars);

/* ************************************************************************** */
/* ****************************** ROTATION UTILS **************************** */
/* ************************************************************************** */

/*apply the iso rotation to the map coordinates*/
int			define_iso(t_map *map);
/*define the altitude ratio for the z axis*/
void		z_ratio(t_pixel *point, t_map *map);
void		rotate_x(t_pixel *point, double angle);
/*rotate the map coordinates on the y axis*/
void		rotate_y(t_pixel *point, double angle);
/*rotate the map coordinates on the z axis*/
void		rotate_z(t_pixel *point, double angle);

/* ************************************************************************** */
/* *************************** COORDINATES UTILS **************************** */
/* ************************************************************************** */

/*define the z range for the map according to the altitudes*/
void		define_z_range(t_map *map);
/*define the alternate color for the map coordinates*/
void		define_alt_color(t_map *map, t_pixel *point);
/*apply define_z_range and define_alt_color to the map coordinates*/
int			define_z_relations(t_map *map);
/*define the zoom for the map according to the window size*/
void		define_zoom(t_map *map);

/* ************************************************************************** */
/* ****************************** DRAWING UTILS ***************************** */
/* ************************************************************************** */

/*make the background of the image*/
void		make_background(t_data *img);
/*prints a pixel on the image*/
void		my_mlx_pixel_put(t_data *data, t_pixel *pixel, t_map *map);
/*verify if the pixel is in the window to draw it or not*/
int			verify_fit(t_map *map, int i, int j);
/*draw the line between two coordinates*/
void		bresenham(t_pixel *coord0, t_pixel *coord1, t_vars *vars,
				t_data *img);
/*create a gradient between two colors according to the position and the len*/
int			gradient(int color_start, int color_end, int len, int pos);
/*return either the original color or the altitude color*/
int			color(t_map *map);

#endif
