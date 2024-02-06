/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:04:58 by trolland          #+#    #+#             */
/*   Updated: 2024/02/02 15:57:55 by trolland         ###   ########.fr       */
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

int strvalue(char c)
{
	int i;
	char *lower;
	char *caps;

	i =0;
	lower = "0123456789abcdef";
	caps = "0123456789ABCDEF";
	while(lower[i])
	{
		if (c == lower[i])
			return(i);
		i++;
	}
	i = 0;
	while(caps[i])
	{
		if (c == caps[i])
			return(i);
		i++;
	}
	return(-1);
}

unsigned int	special_atoi_hex(const char *str, int *index)
{
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	if (str[i] == ',' && str[i+1] == '0' && str[i+2] == 'x')
		i+=3;
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
	printf("%d\n", columns);
	return (columns);
}

void	asign_values(t_map *map, char **split)
{
	int	i;
	int	j;
	int	in_line;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		in_line = 0;
		while (j < map->columns)
		{
			map->coord[i][j].x = special_atoi(&split[i][in_line], &in_line);
			if (split[i][in_line] == ',')
				map->coord[i][j].color = special_atoi_hex(&split[i][in_line],
						&in_line);
			else
				map->coord[i][j].color = WHITE;
			j++;
		}
		i++;
	}
}

int	create_struct(t_map *map, char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, '\n');
	if (!split)
		return (0);
	map->columns = check_columns(split, map->rows);
	if (map->columns == 0)
		return (ft_free_tab(split, map->rows), 0);
	map->coord = malloc(sizeof(t_pixel) * map->rows + 1);
	if (!map->coord)
		return (0);
	while (i <= map->rows)
	{
		map->coord[i] = malloc(sizeof(t_pixel) * map->columns + 1);
		if (!map->coord[i])
			return (free_map(map, i), 0);
		i++;
	}
	asign_values(map, split);
	ft_free_tab(split, map->rows);
	return (1);
}

int	create_map(t_map *map, int fd)
{
	int		rows;
	char	*line;
	char	*buffer;

	rows = 0;
	line = ft_strdup("");
	if (!line)
		return (0);
	while (1)
	{
		buffer = get_next_line(fd);
		if (rows == 0 && !buffer)
			return (free(line), 0);
		if (buffer == 0)
			break ;
		line = free_join(line, buffer);
		free(buffer);
		if (!line)
			return (free(buffer), 0);
		rows++;
	}
	map->rows = rows;
	if (create_struct(map, line) == 0)
		return (free(buffer), free(line), 0);
	return (free(buffer), free(line), 1);
}

int	parse(t_map *map, char *file)
{
	int	fd;

	if (!file)
		quit(ERR_NO_FILE);
	if (check_last_characters(file, ".fdf") == 0)
		quit(ERR_FILE_TYPE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		quit(ERR_READ_FILE);
	else if (create_map(map, fd) == 0)
		return (0);
	close(fd);
	return (1);
}
