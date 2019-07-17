/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:19:05 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/15 18:06:56 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	print_manager(t_fdf *fdf)
{
	ft_bzero(fdf->img_addr, (size_t)(WIDTH * HEIGHT * fdf->bits_pp / 8));
	rotate_map(fdf);
	print_map(fdf, -1, -1);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	print_help(fdf);
}

void	print_help(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 5, 0xFFFFFF,
			"Press 7 or 9 to rotate Y");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 25, 0xFFFFFF,
			"Press 8 or 2 to to rotate X");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 45, 0xFFFFFF,
			"Press 4 or 6 to to rotate Z");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 5, 65, 0xFFFFFF,
			"Press arrow keys to change offset");
}

void	print_map(t_fdf *fdf, int h, int w)
{
	while (++h < fdf->height_d)
	{
		while (++w < fdf->width_d - 1)
			normalize_vec(fdf, fdf->dots[h][w], fdf->dots[h][w + 1]);
		w = -1;
	}
	while (++w < fdf->width_d)
	{
		h = -1;
		while (++h < fdf->height_d - 1)
			normalize_vec(fdf, fdf->dots[h][w], fdf->dots[h + 1][w]);
	}
}

void	print_line(t_fdf *fdf, t_dot *start, t_dot *end)
{
	t_dot	*current;

	current = init_dot(start->vec.x, start->vec.y, start->vec.z);
	while (1)
	{
		current->color = get_color(fdf, start, end, current);
		print_dot(fdf, current);
		if (fabs(current->vec.x - end->vec.x) < 2 &&
		fabs(current->vec.y - end->vec.y) < 2)
			break ;
		fdf->pr.err2 = 2 * fdf->pr.err;
		if (fdf->pr.err2 >= fdf->pr.deltay)
		{
			fdf->pr.err += fdf->pr.deltay;
			current->vec.x += fdf->pr.dirx;
		}
		if (fdf->pr.err2 <= fdf->pr.deltax)
		{
			fdf->pr.err += fdf->pr.deltax;
			current->vec.y += fdf->pr.diry;
		}
	}
	free(current);
	free(start);
	free(end);
}

void	print_dot(t_fdf *fdf, t_dot *dot)
{
	if (dot->vec.x < WIDTH && dot->vec.y < HEIGHT && dot->vec.x > 0 && dot->vec.y > 0)
		*(int*)(fdf->img_addr + (int)((dot->vec.x + (dot->vec.y) * WIDTH) *
		fdf->bits_pp / 8)) = dot->color;
}
