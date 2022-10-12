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

void	init_ray(t_all *a)
{
	double	camera;

	camera = 2 * a->ray.i / (double)WIN_WIDTH - 1.0;
	a->ray.dir.x = a->plr.dir.x + a->plane.x * camera;
	a->ray.dir.y = a->plr.dir.y + a->plane.y * camera;
	a->map.x = (int)a->plr.pos.x;
	a->map.y = (int)a->plr.pos.y;
	a->ray.delta.x = fabs(1.0 / a->ray.dir.x);
	a->ray.delta.y = fabs(1.0 / a->ray.dir.y);
	a->ray.step_x = 1;
	a->ray.dist.x = (a->map.x + 1.0 - a->plr.pos.x) * a->ray.delta.x;
	a->ray.step_y = 1;
	a->ray.dist.y = (a->map.y + 1.0 - a->plr.pos.y) * a->ray.delta.y;
	if (a->ray.dir.x < 0)
	{
		a->ray.step_x = -1;
		a->ray.dist.x = (a->plr.pos.x - a->map.x) * a->ray.delta.x;
	}
	if (a->ray.dir.y < 0)
	{
		a->ray.step_y = -1;
		a->ray.dist.y = (a->plr.pos.y - a->map.y) * a->ray.delta.y;
	}
}

void	ray(t_all *a)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (a->ray.dist.x < a->ray.dist.y)
		{
			a->ray.dist.x += a->ray.delta.x;
			a->map.x += a->ray.step_x;
			a->ray.side = 0;
		}
		else
		{
			a->ray.dist.y += a->ray.delta.y;
			a->map.y += a->ray.step_y;
			a->ray.side = 1;
		}
		if (a->map.map[a->map.y][a->map.x] == '1')
			hit = 1;
	}
}

void	calculate_wall(t_all *a)
{
	if (a->ray.side == 0)
		a->wall.dist = a->ray.dist.x - a->ray.delta.x;
	else
		a->wall.dist = a->ray.dist.y - a->ray.delta.y;
	a->wall.height = (int)(WIN_HEIGHT / a->wall.dist);
	a->wall.start = -a->wall.height / 2 + WIN_HEIGHT / 2;
}

void	calculate_tex_x(t_all *a)
{
	double	wall_x;

	if (!a->ray.side)
		wall_x = a->plr.pos.y + a->wall.dist * a->ray.dir.y;
	else
		wall_x = a->plr.pos.x * a->wall.dist * a->ray.dir.x;
	wall_x -= floor(wall_x);
	a->wall.tex_x = (int)(wall_x * 64.0);
	if ((a->ray.side == 0 && a->ray.dir.x > 0)
		|| (a->ray.side == 1 && a->ray.dir.y < 0))
		a->wall.tex_x = 64 - a->wall.tex_x - 1;
}

void	draw_window(t_all *a)
{
	a->ray.i = -1;
	floor_create(a, 0, a->map.c);
	floor_create(a, WIN_HEIGHT / 2, a->map.f);
	while (++a->ray.i < WIN_WIDTH)
	{
		init_ray(a);
		ray(a);
		calculate_wall(a);
		calculate_tex_x(a);
		draw_vertical(a);
	}
	minimap(a);
	mlx_put_image_to_window(a->mlx.mlx, a->mlx.win, a->mlx.img, 0, 0);
}
