/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cwords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:10:09 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/10 16:05:21 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cwords(char const *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	if (count == (int)ft_strlen(str) - 1)
		count = 2;
	return ((int)count);
}
