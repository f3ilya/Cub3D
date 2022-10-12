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

int	texture(t_all *a, int x, int y)
{
	int	*texture;

	if (!a->ray.side)
	{
		if (a->ray.dir.x >= 0)
			texture = a->map.ea;
		else
			texture = a->map.we;
	}
	else
	{
		if (a->ray.dir.y >= 0)
			texture = a->map.so;
		else
			texture = a->map.no;
	}
	return (texture[64 * y + x]);
}

void	draw_vertical(t_all *a)
{
	double	step;
	int		color;
	int		i;

	step = 64.0 / (double)a->wall.height;
	a->wall.tex_y = 0;
	i = -1;
	while (++i < a->wall.height)
	{
		color = texture(a, a->wall.tex_x, (int)a->wall.tex_y);
		img_pixel(a, a->ray.i, a->wall.start + i, color);
		a->wall.tex_y += step;
	}
}

void	img_pixel(t_all *a, int x, int y, int color)
{
	int	*img;
	int	bits;
	int	size;
	int	end;

	img = (int *) mlx_get_data_addr(a->mlx.img, &bits, &size, &end);
	if (x < WIN_WIDTH && y < WIN_HEIGHT && x >= 0 && y >= 0)
	{
		color = mlx_get_color_value(a->mlx.mlx, color);
		img[y * WIN_WIDTH + x] = color;
	}
}

void	floor_create(t_all *a, int i, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (WIN_HEIGHT / 2))
	{
		x = -1;
		while (++x < WIN_WIDTH)
			img_pixel(a, x, y + i, color);
	}
}

int	mouse(int x, int y, t_all *a)
{
	mlx_mouse_hide();
	mlx_mouse_get_pos(a->mlx.win, (int *)&a->mouse.x, (int *)&a->mouse.y);
	if (x < a->mouse.x)
		move_l_move_r(MOVE_L, a);
	else if (x > a->mouse.x)
		move_l_move_r(MOVE_R, a);
	mlx_mouse_move(a->mlx.win, (int)a->mouse.x, (int)a->mouse.y);
	if (y)
		return (0);
	return (0);
}
