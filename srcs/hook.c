/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:12:22 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/15 18:06:30 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

int	keyb_conf(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
		close_win(key, param);
	else if (key == NUM_8)
		rotate_hook(fdf, fdf->rad.x + 1, fdf->rad.y, fdf->rad.z);
	else if (key == NUM_2)
		rotate_hook(fdf, fdf->rad.x - 1, fdf->rad.y, fdf->rad.z);
	else if (key == NUM_4)
		rotate_hook(fdf, fdf->rad.x, fdf->rad.y, fdf->rad.z + 1);
	else if (key == NUM_6)
		rotate_hook(fdf, fdf->rad.x, fdf->rad.y, fdf->rad.z - 1);
	else if (key == NUM_7)
		rotate_hook(fdf, fdf->rad.x, fdf->rad.y - 1, fdf->rad.z);
	else if (key == NUM_9)
		rotate_hook(fdf, fdf->rad.x, fdf->rad.y + 1, fdf->rad.z);
	else if (key == KEY_UP)
		offset_hook(fdf, 0, -1);
	else if (key == KEY_DOWN)
		offset_hook(fdf, 0, 1);
	else if (key == KEY_LEFT)
		offset_hook(fdf, -1, 1);
	else if (key == KEY_RIGHT)
		offset_hook(fdf, 1, -1);
	print_manager(fdf);
	return (0);
}

int	close_win(int key, void *param)
{
	(void)param;
	free(param);
	system("leaks -q fdf");
	exit(0);
}

void	offset_hook(t_fdf *fdf, int x, int y)
{
	fdf->offset.x += x;
	fdf->offset.y += y;
}

void	rotate_hook(t_fdf *fdf, int x, int y, int z)
{
	fdf->rad.x = x;
	fdf->rad.y = y;
	fdf->rad.z = z;
}
