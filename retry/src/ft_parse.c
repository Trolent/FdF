/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:04:58 by trolland          #+#    #+#             */
/*   Updated: 2024/02/01 19:00:45 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_columns(char ***split, int rows)
{
	int	columns;
	int	i;

	i = 0;
	columns = ft_count_words((*split)[i], "0123456789,-xABCDEFabcdef");
	while (i < rows)
	{
		if (columns != ft_count_words((*split)[i], "0123456789,-xABCDEFabcdef"))
			return (0);
		i++;
	}
	return (columns);
}

int	assign_values(t_map *map, char *line, int rows)
{
	char	**split;
	int		columns;
	int		i;

	i = 0;
	split = ft_split(line, '\n');
	if (!split)
		return (0);
	columns = check_columns(&split, rows);
	if (columns == 0)
		return (ft_free_tab(split, rows), 0);
	(*map).coord = malloc(sizeof(t_pixel) * rows);
	if (!(*map).coord)
		return (0);
	while (i < rows)
	{
		(*map).coord[i] = malloc(sizeof(t_pixel) * columns);
		if (!(*map).coord[i])
			return (free_struct((*map).coord, i), 0);
		i++;
	}
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
		if (!buffer)
			return (free(line), 0);
		if (buffer == 0)
			break ;
		line = ft_strjoin(line, buffer);
		rows++;
	}
	if (assign_values(map, line, rows) == 0)
		return (free(buffer), 0);
	return (free(buffer), 1);
}

int	parse(t_map *map, char *file)
{
	int fd;

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