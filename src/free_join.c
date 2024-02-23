/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:58:06 by trolland          #+#    #+#             */
/*   Updated: 2024/02/21 15:52:10 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_valid_len(int *s1len, int *s2len, char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	else
	{
		*s1len = (int)ft_strlen(s1);
		*s2len = (int)ft_strlen(s2);
		return (1);
	}
}

char	*free_join(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if (!ft_valid_len(&s1len, &s2len, s1, s2))
		return (free(s1), NULL);
	join = malloc(sizeof(char) * (long unsigned int)(s1len + s2len + 1));
	if (!join)
		return (free(s1), NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (free(s1), join);
}
