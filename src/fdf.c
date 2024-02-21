/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:14 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 11:06:00 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h> // must dell before push

int	main(int argc, char **argv)
{
	t_vars	vars;

	errno = 0;
	if (argc != 2)
		quit(ERR_ARG);
	map_init(vars.map);
	if (parse(vars.map, argv[1]) == 0)
		quit(ERR_GEN);
	graphics(&vars);
	free_map(vars.map, vars.map->rows);
	return (0);
}
