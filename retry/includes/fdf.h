/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:59:55 by trolland          #+#    #+#             */
/*   Updated: 2024/02/02 18:29:17 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "error_maps.h"
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

// DEFINE GRAPHICS
// WINDOW
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
//COLORS
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_pixel
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_pixel;

typedef struct s_map
{
	t_pixel			**coord;
	int				rows;
	int				columns;
	int				zoom;
}					t_map;

int					parse(t_map *map, char *file);
int					quit(char *s);
void				free_map(t_map *map, int lines);
char				*free_join(char *s1, char *s2);
void				free_map(t_map *map, int lines);
void				map_init(t_map *map);

int					graphics(t_map *map);

void	print_map(t_map *map); // =========> must be commented before submiting

#endif