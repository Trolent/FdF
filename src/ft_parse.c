/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:04:58 by trolland          #+#    #+#             */
/*   Updated: 2024/01/16 14:32:35 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_get_map_input(int fd)
{
	char	*line;
	char	*concat;

	concat = "";
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		concat = ft_strjoin(concat, line);
	}
	if (!concat[0])
		return (NULL);
	return (concat);
}

int	ft_chek_arg_no(char **split)
{
	int	i;
	int	j;
	int	val;
	int	max;

	i = 0;
	max = ft_count_words(split[i], " ");
	while (split[i])
	{
		j = 0;
		val = 0;
		while (split[i][j])
		{
			val = ft_count_words(split[i], " ");
			j++;
		}
		if (val != max)
			return (0);
		i++;
	}
	printf("%d\n", max);
	return (max);
}

void	ft_assign_values(t_alt **map, char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			map[i][j].z = ft_atoi(&split[i][j]);
			j++;
		}
		i++;
	}
}

t_alt	**ft_create_map(t_alt **map, int fd)
{
	int		rows;
	char	**split;
	char	*line;
	int		col;
	int		i;

	line = ft_get_map_input(fd);
	if (!line)
		return (NULL);
	split = ft_split(line, '\n');
	if (!split)
		return (free(line), NULL);
	rows = 0;
	while (split[rows])
		rows++;
	map = malloc(sizeof(t_alt *) * rows);
	if (!map)
		return (free(line), ft_free_tab(split, rows), NULL);
	col = ft_chek_arg_no(split);
	if (col == 0)
		return (free(line), ft_free_tab(split, rows), free(map), NULL);
	i = -1;
	while (i++ < rows)
	{
		map[i] = malloc(sizeof(t_alt) * col);
		if (!map[i])
			free(map[i]);
	}
	ft_assign_values(map, split);
	return (map);
}

int	ft_parse(t_alt **map, char *file)
{
	int fd;

	if (!file)
		ft_quit(ERR_NO_FILE);
	if (ft_check_last_characters(file, ".fdf") == 0)
		ft_quit(ERR_FILE_TYPE);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_quit(ERR_READ_FILE);
	else
		map = ft_create_map(map, fd);
	close(fd);
	return (1);
}