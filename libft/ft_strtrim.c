/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:52:28 by trolland          #+#    #+#             */
/*   Updated: 2024/02/24 10:28:52 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s1);
	while (s1[start] && ft_is_charset(s1[start], set))
		start++;
	while (s1[end - 1] && ft_is_charset(s1[end - 1], set) && end > start)
		end--;
	trim = malloc(sizeof(char) * (unsigned long)(end - start + 1));
	if (!trim)
		return (NULL);
	i = 0;
	while (start < end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
