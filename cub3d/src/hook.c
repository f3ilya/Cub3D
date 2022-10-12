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

void	key_w_key_s(int key, t_all *a)
{
	if (key == KEY_W)
	{
		if (a->map.map[(int)(a->plr.pos.y)]
			[(int)(a->plr.pos.x + a->plr.dir.x * SPD_K)] == '0')
			a->plr.pos.x += a->plr.dir.x * SPD_K;
		if (a->map.map[(int)(a->plr.pos.y + a->plr.dir.y * SPD_K)]
			[(int)(a->plr.pos.x)] == '0')
			a->plr.pos.y += a->plr.dir.y * SPD_K;
	}
	if (key == KEY_S)
	{
		if (a->map.map[(int)(a->plr.pos.y)]
			[(int)(a->plr.pos.x - a->plr.dir.x * SPD_K)] == '0')
			a->plr.pos.x -= a->plr.dir.x * SPD_K;
		if (a->map.map[(int)(a->plr.pos.y - a->plr.dir.y * SPD_K)]
			[(int)(a->plr.pos.x)] == '0')
			a->plr.pos.y -= a->plr.dir.y * SPD_K;
	}
	draw_window(a);
}

void	key_a_key_d(int key, t_all *a)
{
	if (key == KEY_D)
	{
		if (a->map.map[(int)(a->plr.pos.y)]
			[(int)(a->plr.pos.x + a->plane.x * SPD_K)] == '0')
			a->plr.pos.x += a->plane.x * SPD_K;
		if (a->map.map[(int)(a->plr.pos.y + a->plane.y * SPD_K)]
			[(int)(a->plr.pos.x)] == '0')
			a->plr.pos.y += a->plane.y * SPD_K;
	}
	if (key == KEY_A)
	{
		if (a->map.map[(int)(a->plr.pos.y)]
			[(int)(a->plr.pos.x - a->plane.x * SPD_K)] == '0')
			a->plr.pos.x -= a->plane.x * SPD_K;
		if (a->map.map[(int)(a->plr.pos.y - a->plane.y * SPD_K)]
			[(int)(a->plr.pos.x)] == '0')
			a->plr.pos.y -= a->plane.y * SPD_K;
	}
	draw_window(a);
}

void	move_l_move_r(int key, t_all *a)
{
	double	old_dir;
	double	old_plane;

	old_dir = a->plr.dir.x;
	old_plane = a->plane.x;
	if (key == MOVE_L)
	{
		a->plr.dir.x = a->plr.dir.x * cos(-SPD_M) - a->plr.dir.y * sin(-SPD_M);
		a->plr.dir.y = old_dir * sin(-SPD_M) + a->plr.dir.y * cos(-SPD_M);
		a->plane.x = a->plane.x * cos(-SPD_M) - a->plane.y * sin(-SPD_M);
		a->plane.y = old_plane * sin(-SPD_M) + a->plane.y * cos(-SPD_M);
	}
	if (key == MOVE_R)
	{
		a->plr.dir.x = a->plr.dir.x * cos(SPD_M) - a->plr.dir.y * sin(SPD_M);
		a->plr.dir.y = old_dir * sin(SPD_M) + a->plr.dir.y * cos(SPD_M);
		a->plane.x = a->plane.x * cos(SPD_M) - a->plane.y * sin(SPD_M);
		a->plane.y = old_plane * sin(SPD_M) + a->plane.y * cos(SPD_M);
	}
	draw_window(a);
}

int	ft_exit(t_all *a)
{
	ft_free_exit(NULL, a);
	return (0);
}

int	ft_hook(int key, t_all *a)
{
	if (key == ESC)
		ft_free_exit(NULL, a);
	else if (key == KEY_W || key == KEY_S)
		key_w_key_s(key, a);
	else if (key == KEY_A || key == KEY_D)
		key_a_key_d(key, a);
	else if (key == MOVE_L || key == MOVE_R)
		move_l_move_r(key, a);
	return (0);
}
