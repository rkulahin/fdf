/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:02:46 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/12 15:21:55 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"


t_dot		*rotate(t_fdf *fdf, t_dot *dot)
{
	t_vector	p;
	
	p = dot->vec;
	dot->vec.y = p.y * cos(RAD * fdf->rad.x) + p.z * sin(RAD * fdf->rad.x);
	dot->vec.z = -p.y * sin(RAD * fdf->rad.x) + p.z * cos(RAD * fdf->rad.x);
	p = dot->vec;
	dot->vec.x = p.x * cos(RAD * fdf->rad.y) + p.z * sin(RAD * fdf->rad.y);
	dot->vec.z = -p.x * sin(RAD * fdf->rad.y) + p.z * cos(RAD * fdf->rad.y);
	p = dot->vec;
	dot->vec.x = p.x * cos(RAD * fdf->rad.z) + p.y * sin(RAD * fdf->rad.z);
	dot->vec.y = -p.x * sin(RAD * fdf->rad.z) + p.y * cos(RAD * fdf->rad.z);
	return (dot);
}

void		rotate_map(t_fdf *fdf)
{
	int h;
	int w;

	while(h < fdf->height_d)
	{
		w = 0;
		while(w < fdf->width_d)
		{
			fdf->dots[h][w] = rotate(fdf, fdf->dots[h][w]);
			w++;
		}
		h++;
	}
	fdf->rad.z = 0;
	fdf->rad.x = 0;
	fdf->rad.y = 0;
}
