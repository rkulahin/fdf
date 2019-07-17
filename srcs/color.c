/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:28:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/12 17:52:26 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

double	percent(int start, int end, int curr)
{
	double place;
	double dist;

	place = curr - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int		get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int		get_color(t_fdf *fdf, t_dot *s, t_dot *e, t_dot *c)
{
	int		red;
	int		green;
	int		blue;
	double	perc;

	if (s->color == e->color)
		return (e->color);
	if (fabs(s->vec.x - e->vec.x) > fabs(s->vec.y - e->vec.y))
		perc = percent((int)s->vec.x, (int)e->vec.x, (int)c->vec.x);
	else
		perc = percent((int)s->vec.y, (int)e->vec.y, (int)c->vec.y);
	red = get_light((s->color >> 16) & 0xFF,
			(e->color >> 16) & 0xFF, perc);
	green = get_light((s->color >> 8) & 0xFF,
			(e->color >> 8) & 0xFF, perc);
	blue = get_light(s->color & 0xFF, e->color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}

int		set_color(int z)
{
	int col;

	if (z < 0)
		col = E_COL;
	else if (z < 5)
		col = L_COL;
	else
		col = S_COL;
	return (col);
}