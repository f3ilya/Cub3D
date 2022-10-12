/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:04:19 by                   #+#    #+#             */
/*   Updated: 2021/12/25 18:50:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

void	check_valid(t_all *a)
{
	char	sym[19];
	int		n;

	set_zero(sym, 19);
	if (chk_wall(a->map.map, map_sz(a->map.map)))
		ft_free_exit("The map must be surrounded by walls", a);
	n = chk_symb(a->map.map, a, -1, sym);
	if (n == 1)
		ft_free_exit("More than one or no hero on map", a);
	if (n == 3)
		ft_free_exit("Map consists of not only allowed symbols", a);
}

int	check_space_col(int i, char **map, int rows)
{
	int	j;

	j = -1;
	while (map[i][++j])
	{
		if (map[i][j] == ' ')
		{
			if (i - 1 >= 0 && j < ft_strlen(map[i - 1]) && map[i - 1][j] == '0')
				return (1);
			if (i + 1 < rows && j < ft_strlen(map[i + 1])
				&& map[i + 1][j] == '0')
				return (1);
			if (j - 1 >= 0 && map[i][j - 1] == '0')
				return (1);
			if (j + 1 < ft_strlen(map[i]) && map[i][j + 1] == '0')
				return (1);
		}
		if ((i == 0 || i == rows - 1 || j == 0
				|| j == ft_strlen(map[i]) - 1) && map[i][j] == '0')
			return (1);
	}
	return (0);
}

int	chk_wall(char **map, int rows)
{
	int		i;

	i = 0;
	while (i < rows)
	{
		if (check_space_col(i, map, rows))
			return (1);
		i++;
	}
	return (0);
}

void	set_position(t_all *a, char c, int y, int x)
{
	a->map.map[y][x] = '0';
	a->plr.pos.x = x + 0.5;
	a->plr.pos.y = y + 0.5;
	if (c == 'E')
	{
		a->plr.dir.x = 1;
		a->plane.x = 0;
		a->plane.y = FOV;
	}
	else if (c == 'W')
	{
		a->plr.dir.x = -1;
		a->plane.x = 0;
		a->plane.y = -FOV;
	}
	else if (c == 'S')
	{
		a->plr.dir.y = 1;
		a->plane.x = -FOV;
	}
	else if (c == 'N')
		a->plr.dir.y = -1;
}

int	chk_symb(char **map, t_all *a, int y, char *sym)
{
	int		x;

	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("10 NSEW", map[y][x]) == NULL)
				return (3);
			if (ft_strchr("NSEW", map[y][x]))
			{
				sym[map[y][x] - 69] += 1;
				set_position(a, map[y][x], y, x);
			}
		}
	}
	if ((sym[0] + sym[9] + sym[14] + sym[18]) != 1)
		return (1);
	return (0);
}
