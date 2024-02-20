/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:19:50 by trolland          #+#    #+#             */
/*   Updated: 2024/02/20 15:25:17 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define SKIPLINE 20
#define TEXT_COLOR 0xead162
#define MENU_COLOR 0x6286ea
#define TAB 50

void	print_text(t_vars *vars, t_data *img, char *str, int y)
{
	mlx_string_put(vars->mlx, vars->win, TAB, y, TEXT_COLOR, str);
}

void	make_menu(t_vars *vars, t_data *img)
{
	int	line_sep;

	line_sep = 60;
	mlx_string_put(vars->mlx, vars->win, TAB - 10, 30, TEXT_COLOR,
		"FDF Controls");
	print_text(vars, img, "Zoom : Scroll mouse", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Move : Arrows", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "View from top : T", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "View ISO : I", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "View diagonal : D", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Change color : C", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Show lines / dots : L", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Exit : ESC or Click cross", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Rotate X / Y / Z : QW / AS / ZX", line_sep);
	line_sep += SKIPLINE;
	print_text(vars, img, "Change Z range : +/-", line_sep);
}
