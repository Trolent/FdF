/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:19:50 by trolland          #+#    #+#             */
/*   Updated: 2024/02/19 17:10:21 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define SKIPLINE 20
#define MENU_WIDTH 250
#define MENU_HEIGHT 250
#define TEXT_COLOR 0xead162
#define MENU_COLOR 0x6286ea
#define TAB 50

void	menu_background(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < MENU_HEIGHT)
	{
		j = 0;
		while (j < MENU_WIDTH)
		{
			put_pixel(img, j, i, MENU_COLOR);
			j++;
		}
		i++;
	}
}

void	print_text(t_vars *vars, t_data *img, char *str, int y)
{
	int	len;

	len = ft_strlen(str);
	mlx_string_put(vars->mlx, vars->win, TAB, y, TEXT_COLOR, str);
}

void	make_menu(t_vars *vars, t_data *img)
{
	int	line_sep;

	menu_background(img);
	line_sep = 20;
	mlx_string_put(vars->mlx, vars->win, 50, TAB - 20, TEXT_COLOR,
		"FDF Controls");
	line_sep += SKIPLINE;
	line_sep += SKIPLINE;
	print_text(vars, img, "Zoom: Scroll mouse", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Move: Arrows", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "View from top: T", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "View ISO: I", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "View diagonal: D", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Change color: C", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Show lines / dots: L", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Exit: ESC or Click cross", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Rotate X Y Z: X A Z", line_sep);
}
