/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:40:08 by trolland          #+#    #+#             */
/*   Updated: 2024/02/24 10:27:20 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		s1len;
	char	*dup;

	i = 0;
	s1len = (int)ft_strlen(s1);
	dup = malloc(sizeof(char) * (unsigned long)(s1len + 1));
	if (!dup)
		return (NULL);
	while (i < s1len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
