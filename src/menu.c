/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:19:50 by trolland          #+#    #+#             */
/*   Updated: 2024/02/22 19:05:50 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define SKIPLINE 20
#define TEXT_COLOR 0xead162
#define TAB 50

void	print_text(t_vars *vars, char *str, int *line_sep)
{
	mlx_string_put(vars->mlx, vars->win, TAB, *line_sep, TEXT_COLOR, str);
	*line_sep += SKIPLINE;
}

void	counter(t_vars *vars, char *str, double data, int *line_sep)
{
	char	*z_str;

	z_str = ft_itoa(data);
	if (!z_str)
		return ;
	str = ft_strjoin(str, z_str);
	if (!str)
		return (free(z_str));
	print_text(vars, str, line_sep);
	free(z_str);
	free(str);
	return ;
}

char	*get_angle(double angle)
{
	char	*str;
	char	*z_str;
	char	*str2;

	z_str = ft_itoa(angle);
	if (!z_str)
		return (NULL);
	str = ft_strjoin("[", z_str);
	if (!str)
		return (free(z_str), NULL);
	free(z_str);
	str2 = ft_strjoin(str, "]");
	if (!str2)
		return (free(str), NULL);
	free(str);
	return (str2);
}

void	print_xyz(t_vars *vars, int *line_sep)
{
	char	*str;
	char	*z_str;
	char	*temp;
	int		i;

	i = 0;
	str = ft_strdup("Angles : ");
	if (!str)
		return ;
	while (i < 3)
	{
		z_str = get_angle(vars->map->angle[i]);
		if (!z_str)
			return (free(str));
		temp = ft_strjoin(str, z_str);
		free(str);
		str = temp;
		if (!str)
			return (free(z_str));
		free(z_str);
		i++;
	}
	print_text(vars, str, line_sep);
	free(str);
	return ;
}

void	make_menu(t_vars *vars)
{
	int	line_sep;

	line_sep = 60;
	mlx_string_put(vars->mlx, vars->win, TAB - 10, 30, TEXT_COLOR,
		"FDF Controls");
	counter(vars, "Z ratio : ", vars->map->z_range * 100, &line_sep);
	counter(vars, "Zoom info : ", vars->map->zoom * 100, &line_sep);
	print_text(vars, "Angles : [X][Y][Z] ", &line_sep);
	print_xyz(vars, &line_sep);
	print_text(vars, "--------------------", &line_sep);
	print_text(vars, "Zoom : Scroll mouse", &line_sep);
	print_text(vars, "Move : Arrows", &line_sep);
	print_text(vars, "Rotate X / Y / Z : QW / AS / ZX", &line_sep);
	print_text(vars, "Change Z range : +/-", &line_sep);
	print_text(vars, "Show lines / dots : L", &line_sep);
	print_text(vars, "Show diagonals : D", &line_sep);
	print_text(vars, "Change color : C", &line_sep);
	print_text(vars, "--------------------", &line_sep);
	print_text(vars, "View from front : T", &line_sep);
	print_text(vars, "View ISO : I", &line_sep);
	print_text(vars, "View lateral  X : Y", &line_sep);
	print_text(vars, "View lateral  Y : G", &line_sep);
	print_text(vars, "Reset original Z range : U", &line_sep);
	print_text(vars, "Recenter position : R", &line_sep);
	print_text(vars, "Exit : ESC or Click cross", &line_sep);
}
