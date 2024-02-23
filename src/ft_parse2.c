/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:04:58 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 17:17:37 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	special_atoi(const char *str, int *index)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	*index += i;
	return (res * neg);
}

int	strvalue(char c)
{
	int		i;
	char	*lower;
	char	*caps;

	i = 0;
	lower = "0123456789abcdef";
	caps = "0123456789ABCDEF";
	while (lower[i])
	{
		if (c == lower[i])
			return (i);
		i++;
	}
	i = 0;
	while (caps[i])
	{
		if (c == caps[i])
			return (i);
		i++;
	}
	return (-1);
}

int	special_atoi_hex(const char *str, int *index)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		i += 3;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		res = (res * 16) + strvalue(str[i]);
		i++;
	}
	*index += i;
	return (res);
}

int	check_columns(char **split, int rows)
{
	int	columns;
	int	i;

	i = 0;
	columns = count_words_sep(split[i], "0123456789,-xABCDEFabcdef");
	while (i < rows)
	{
		if (columns != count_words_sep(split[i], "0123456789,-xABCDEFabcdef"))
			return (0);
		i++;
	}
	return (columns);
}

void	asign_values(t_map *map, char **split)
{
	int	i;
	int	j;
	int	line;

	i = -1;
	while (++i < map->rows)
	{
		j = 0;
		line = 0;
		while (j < map->columns)
		{
			map->coord[i][j].z[ORG] = special_atoi(&split[i][line], &line);
			map->coord[i][j].x[ORG] = j - (map->columns / 2);
			map->coord[i][j].y[ORG] = i - (map->rows / 2);
			map->z_max = ft_max(map->z_max, (int)map->coord[i][j].z[ORG]);
			map->z_min = ft_min(map->z_min, (int)map->coord[i][j].z[ORG]);
			if (split[i][line] == ',')
				map->coord[i][j].color[ORGCLR] = \
					special_atoi_hex(&split[i][line], &line);
			else
				map->coord[i][j].color[ORGCLR] = WHITE;
			j++;
		}
	}
}
