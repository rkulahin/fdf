/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:41:48 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/14 12:45:06 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

t_dot		*normalize_dot(t_dot *dot, int pp_line, t_fdf *fdf)
{
	int		cent[2];

	dot->vec.x -= (fdf->width_d - 1) / 2.0;
	dot->vec.y -= (fdf->height_d -1) / 2.0;
	dot->vec.x = dot->vec.x * pp_line;
	dot->vec.y = dot->vec.y * pp_line;
	dot->vec.z = dot->vec.z * pp_line;
	return (dot);
}

void	normalize_vec(t_fdf *fdf, t_dot *start, t_dot *end)
{
	t_dot	*f;
	t_dot	*s;
	
	f = init_dot(start->vec.x + (fdf->offset.x - (WIDTH / 2)), start->vec.y +
	(fdf->offset.y - (HEIGHT / 2)), start->vec.z);
	s = init_dot(end->vec.x + (fdf->offset.x - (WIDTH / 2)), end->vec.y +
	(fdf->offset.y - (HEIGHT / 2)), end->vec.z);
	f->color = start->color;
	s->color = end->color;
	fdf->pr.deltax = fabs(end->vec.x - start->vec.x);
	fdf->pr.deltay = -fabs(end->vec.y - start->vec.y);
	fdf->pr.dirx = start->vec.x < end->vec.x ? 1 : -1;
	fdf->pr.diry = start->vec.y < end->vec.y ? 1 : -1;
	fdf->pr.err = fdf->pr.deltax + fdf->pr.deltay;
	normalize_to_cent(f, fdf);
	normalize_to_cent(s, fdf);
	print_line(fdf, f, s);
}

t_dot		*normalize_to_cent(t_dot *dot, t_fdf *fdf)
{
	dot->vec.x += fdf->offset.x;
	dot->vec.y += fdf->offset.x;
	return (dot);
}