/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:19:50 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 12:13:13 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define SKIPLINE 20
#define TEXT_COLOR 0xead162
#define MENU_COLOR 0x6286ea
#define TAB 50

void	print_text(t_vars *vars, t_data *img, char *str, int *line_sep)
{
	mlx_string_put(vars->mlx, vars->win, TAB, *line_sep, TEXT_COLOR, str);
	*line_sep += SKIPLINE;
}

char *z_range_str(double z_range)
{
	char *str;

	str = ft_strjoin("Z range : ", ft_itoa(z_range * 10));
	return (str);
}

void	make_menu(t_vars *vars, t_data *img)
{
	int	line_sep;

	line_sep = 60;
	mlx_string_put(vars->mlx, vars->win, TAB - 10, 30, TEXT_COLOR,
		"FDF Controls");
	print_text(vars, img, z_range_str(vars->map->z_range), &line_sep);
	print_text(vars, img, "Zoom : Scroll mouse", &line_sep);
	print_text(vars, img, "Move : Arrows", &line_sep);
	print_text(vars, img, "View from top : T", &line_sep);
	print_text(vars, img, "View ISO : I", &line_sep);
	print_text(vars, img, "View diagonal : D", &line_sep);
	print_text(vars, img, "Change color : C", &line_sep);
	print_text(vars, img, "Show lines / dots : L", &line_sep);
	print_text(vars, img, "Exit : ESC or Click cross", &line_sep);
	print_text(vars, img, "Rotate X / Y / Z : QW / AS / ZX", &line_sep);
	print_text(vars, img, "Change Z range : +/-", &line_sep);
}
