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

void	init_mlx(t_all *a)
{
	a->mlx.mlx = mlx_init();
	a->mlx.win = mlx_new_window(a->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	a->mlx.img = mlx_new_image(a->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	a->mlx.addr = mlx_get_data_addr(a->mlx.mlx,
			&a->mlx.bits, &a->mlx.size_l, &a->mlx.end);
	mlx_mouse_move(a->mlx.win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_mouse_get_pos(a->mlx.win, (int *)&a->mouse.x, (int *)&a->mouse.y);
}

void	init(t_all *a)
{
	a->mlx.addr = NULL;
	a->mlx.mlx = NULL;
	a->mlx.bits = 0;
	a->mlx.end = 0;
	a->mlx.img = NULL;
	a->mlx.size_l = 0;
	a->mlx.win = NULL;
	a->map.c = -1;
	a->map.map = NULL;
	a->map.count = 0;
	a->map.ea = NULL;
	a->map.f = -1;
	a->map.no = NULL;
	a->map.so = NULL;
	a->map.we = NULL;
	a->map.x = 0;
	a->map.y = 0;
	a->plane.y = 0;
	a->plane.x = FOV;
	init2(a);
}

void	init2(t_all *a)
{
	a->plr.dir.x = 0;
	a->plr.dir.y = 0;
	a->plr.pos.y = 0;
	a->plr.pos.x = 0;
	a->ray.dir.x = 0;
	a->ray.dir.y = 0;
	a->ray.delta.x = 0;
	a->ray.delta.y = 0;
	a->ray.dist.x = 0;
	a->ray.dist.y = 0;
	a->ray.i = 0;
	a->ray.side = 0;
	a->ray.step_x = 0;
	a->ray.step_y = 0;
	a->wall.dist = 0;
	a->wall.height = 0;
	a->wall.tex_x = 0;
	a->wall.tex_y = 0;
	a->wall.start = 0;
}
