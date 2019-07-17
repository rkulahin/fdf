/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:55:38 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/14 12:45:41 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

t_dot	*init_dot(int x, int y, int z)
{
	t_dot	*new;

	new = (t_dot*)malloc(sizeof(t_dot));
	new->vec.x = x;
	new->vec.y = y;
	new->vec.z = z;
	return (new);
}

void	parce_map_size(t_fdf *fdf)
{
	char	*line;
	char	**spl;

	get_next_line(fdf->fd, &line);
	spl = ft_strsplit(line, ' ');
	while (spl && spl[fdf->width_d])
		fdf->width_d++;
	ft_strdel(&line);
	free_arr(spl);
	fdf->height_d++;
	while (get_next_line(fdf->fd, &line))
	{
		fdf->height_d++;
		ft_strdel(&line);
	}
	close(fdf->fd);
	fdf->fd = open(fdf->file, O_RDONLY);
	if (fdf->height_d <= 0 || fdf->width_d <= 0)
		f_error();
}

t_dot	***create_dots_map(int w, int h)
{
	t_dot	***arr;
	int		i;

	i = 0;
	arr = (t_dot***)malloc(sizeof(t_dot**) * h + 1);
	while (i < h)
	{
		arr[i] = (t_dot**)malloc(sizeof(t_dot*) * w + 1);
		arr[i][w] = NULL;
		i++;
	}
	arr[h] = NULL;
	return (arr);
}

int		parce_map(t_fdf *fdf)
{
	char	**dots;
	char	*line;
	int		pp_line;
	int		w;
	int		h;

	h = 0;
	parce_map_size(fdf);
	fdf->dots = create_dots_map(fdf->width_d, fdf->height_d);
	pp_line = count_ppl(fdf);
	while (get_next_line(fdf->fd, &line))
	{
		w = 0;
		dots = ft_strsplit(line, ' ');
		while (w < fdf->width_d)
		{
			if (!dots || !dots[w])
				return (0);
			fdf->dots[h][w] = normalize_dot(init_dot(w, h,
								ft_atoi(dots[w])), pp_line, fdf);
			fdf->dots[h][w]->color = set_color(fdf->dots[h][w]->vec.z);
			w++;
		}
		ft_strdel(&line);
		free_arr(dots);
		h++;
	}
	return (1);
}

int		count_ppl(t_fdf *fdf)
{
	int		delta;
	int		pp_line;

	if (fdf->width_d > fdf->height_d)
		delta = fdf->width_d;
	else
		delta = fdf->height_d;
	pp_line = (WIDTH - SHIFT) / delta;
	if (pp_line < 2)
		pp_line = 2;
	return (pp_line);
}
