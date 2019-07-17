/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:20:03 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/09 17:43:19 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	print_map_debug(t_fdf *fdf)
{
	int h;
	int w;

	h = 0;
	while (h < fdf->height_d)
	{
		w = 0;
		while (w < fdf->width_d)
		{
			ft_printf("{x:%i y:%i z:%i} ", fdf->dots[h][w]->vec.x,
			fdf->dots[h][w]->vec.y, fdf->dots[h][w]->vec.z);
			w++;
		}
		ft_printf("\n");
		h++;
	}
}
