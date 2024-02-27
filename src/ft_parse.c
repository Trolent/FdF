/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:04:58 by trolland          #+#    #+#             */
/*   Updated: 2024/02/25 20:33:06 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	create_struct(t_map *map, char *line)
{
	char	**split;
	int		i;

	split = ft_split(line, '\n');
	if (!split)
		return (free(line), 0);
	free(line);
	map->columns = check_columns(split, map->rows);
	if (map->columns == 0)
		return (ft_free_tab(split, map->rows), 0);
	if (map->rows >= 1 && map->columns >= 1)
		map->coord = malloc(sizeof(t_pixel *) * (map->rows + 1));
	if (!map->coord)
		return (ft_free_tab(split, map->rows), quit(ERR_MAP_DATA));
	i = -1;
	while (++i <= map->rows)
	{
		map->coord[i] = malloc(sizeof(t_pixel) * (map->columns + 1));
		if (!map->coord[i])
			return (free_map(map, i), ft_free_tab(split, map->rows), 0);
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
			return (free(line), 0);
		rows++;
	}
	map->rows = rows;
	if (create_struct(map, line) == 0)
		return (free(buffer), 0);
	return (free(buffer), 1);
}

int	parse(t_map *map, char *file)
{
	int	fd;

	if (!file)
		return (quit(ERR_NO_FILE));
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
