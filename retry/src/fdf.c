/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:14 by trolland          #+#    #+#             */
/*   Updated: 2024/02/18 21:40:14 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h> // must dell before push

int	main(int argc, char **argv)
{
	t_map	map;

	errno = 0;
	if (argc != 2)
		quit(ERR_ARG);
	else
	{
		map_init(&map);
		if (parse(&map, argv[1]) == 0)
			quit(ERR_GEN);
	}
	graphics(&map);
	free_map(&map, map.rows);
	return (0);
}