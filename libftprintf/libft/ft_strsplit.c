/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:23:44 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/09 19:56:06 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ptr;

	if (!s || !(ptr = (char **)malloc((ft_cwords(s, c) + 1) * sizeof(*ptr))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_cwords(s, c))
	{
		k = 0;
		if (!(ptr[i] = ft_strnew(ft_lenword(&(s[j]), c) + 1)))
			ptr[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			ptr[i][k++] = s[j++];
		ptr[i][k] = '\0';
	}
	ptr[i] = NULL;
	return (ptr);
}
