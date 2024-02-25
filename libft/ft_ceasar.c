/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceasar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:03:45 by trolland          #+#    #+#             */
/*   Updated: 2024/02/24 10:30:36 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_index(int c, int num)
{
	if (ft_islower(c))
		return (((c - 97 + num) % 26) + 97);
	else
		return (((c - 65 + num) % 26) + 65);
}

char	*ft_ceasar(char *input, int num)
{
	int		i;
	char	*str;

	str = ft_strdup(input);
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			str[i] = (char)ft_index(str[i], num);
		i++;
	}
	return (str);
}
