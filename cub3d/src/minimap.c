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

void	draw_point(t_all *a, int color, int x, int y)
{
	int	start_x;
	int	start_y;

	start_y = y;
	while (start_y < POINT + y)
	{
		start_x = x;
		while (start_x < POINT + x)
		{
			img_pixel(a, start_x, start_y, color);
			start_x++;
		}
		start_y++;
	}
}

void	minimap(t_all *a)
{
	int	y;
	int	x;

	y = -1;
	while (a->map.map[++y])
	{
		x = -1;
		while (a->map.map[y][++x])
		{
			if (a->map.map[y][x] == '0')
				draw_point(a, 0xFFFFFF, x * POINT, y * POINT);
			if (a->map.map[y][x] == '1')
				draw_point(a, 0x000000, x * POINT, y * POINT);
		}
	}
	draw_point(a, 0xFF0000,
		(int)a->plr.pos.x * POINT, (int)a->plr.pos.y * POINT);
}
