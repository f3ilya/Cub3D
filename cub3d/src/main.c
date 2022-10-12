/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:12:05 by                   #+#    #+#             */
/*   Updated: 2021/12/25 18:53:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

void	ft_free_exit(char *msg, t_all *a)
{
	ft_free(a->map.map);
	if (a->map.we)
		free(a->map.we);
	if (a->map.so)
		free(a->map.so);
	if (a->map.no)
		free(a->map.no);
	if (a->map.ea)
		free(a->map.ea);
	if (a->mlx.img)
		mlx_destroy_image(a->mlx.mlx, a->mlx.img);
	if (a->mlx.win)
		mlx_destroy_window(a->mlx.mlx, a->mlx.win);
	exit_func(msg);
}

int	exit_func(char *msg)
{
	if (msg)
		printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_all	a;

	if (argc == 2 && ft_check_filename(argv[1]))
	{
		init(&a);
		read_config(&a, argv[1]);
		check_valid(&a);
		draw_window(&a);
		mlx_hook(a.mlx.win, 6, 1L << 6, mouse, &a);
		mlx_hook(a.mlx.win, 2, 1L << 0, ft_hook, &a);
		mlx_hook(a.mlx.win, 17, 0, ft_exit, &a);
		mlx_loop(a.mlx.mlx);
		ft_free_exit(NULL, &a);
	}
	else
		exit_func("Invalid arguments.");
}
