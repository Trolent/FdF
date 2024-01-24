/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:14 by trolland          #+#    #+#             */
/*   Updated: 2024/01/24 23:52:30 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void print_map(t_alt ***map)
{
	int i = 0;
	int j = 0;

	while(i< 9)
	{
		j = 0;
		while (j < 9)
		{
			printf("%d ", (*map)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_alt **map;

	errno = 0;
	if (argc != 2)
		ft_quit(ERR_ARG);
	else
	{
		ft_parse(&map, argv[1]);
		// print_map(&map);
	}
	return(0);
}