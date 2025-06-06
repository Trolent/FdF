/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:14 by trolland          #+#    #+#             */
/*   Updated: 2024/05/29 11:30:40 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map;

	vars.map = &map;
	if (argc != 2)
		quit(ERR_ARG);
	map_init(vars.map);
	if (parse(vars.map, argv[1]) == 0)
		quit(ERR_GEN);
	graphics(&vars);
	free_map(vars.map, vars.map->rows);
	return (0);
}
