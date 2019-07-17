/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 10:44:54 by rkulahin          #+#    #+#             */
/*   Updated: 2019/07/15 18:01:47 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	init_window(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "fdf 42");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img_addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_pp, &fdf->size_line, &fdf->endian);
}

t_fdf	*init_node(void)
{
	t_fdf	*new;

	new = (t_fdf*)malloc(sizeof(t_fdf));
	new->button.help = 0;
	new->button.button = 0;
	new->dots = NULL;
	new->fd = 0;
	new->bits_pp = 0;
	new->endian = 0;
	new->offset.x = WIDTH / 2.0 ;
	new->offset.y = HEIGHT / 2.0;
	new->offset.z = 0;
	new->size_line = 0;
	new->height_d = 0;
	new->width_d = 0;
	new->rad.x = 0;
	new->rad.y = 0;
	new->rad.z = 0;
	return (new);
}

void	f_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

void	free_arr(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str[i]);
	free(str);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = init_node();
	if (ac != 2)
	{
		ft_putendl("usage: ./fdf source_file\n");
		exit(1);
	}
	fdf->file = av[1];
	fdf->fd = open(av[1], O_RDONLY);
	if (read(fdf->fd, av[0], 0) < 0 || fdf->fd < 0)
		f_error();
	if (parce_map(fdf))
	{
		init_window(fdf);
		print_manager(fdf);
	}
	else
		f_error();
	mlx_hook(fdf->win_ptr, 2, 0, keyb_conf, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_win, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
