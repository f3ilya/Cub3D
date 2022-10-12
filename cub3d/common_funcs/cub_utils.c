/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:14:41 by                   #+#    #+#             */
/*   Updated: 2021/12/23 13:56:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

int	ft_atoi_cub(char *str)
{
	int			i;
	int			k;
	long int	n;

	i = 0;
	k = 1;
	n = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		k = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (-1);
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + k * (str[i++] - 48);
		if ((n > 2147483647 && k == 1) || (n > 2147483648 && k == -1))
			return (-1);
	}
	if (str[i] != '\0')
		return (-1);
	return (n);
}

void	set_zero(char *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		arr[i++] = 0;
}

int	ft_check_filename(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (str && i < len - 4)
	{
		str++;
		i++;
	}
	if (ft_strncmp(str, ".cub", 4) == 0)
		return (1);
	return (0);
}

char	**append(char **map, char *str)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = ft_strdup(str);
	new_map[i + 1] = NULL;
	ft_free(map);
	return (new_map);
}

int	map_sz(char **map)
{
	int	sz;
	int	i;

	i = 0;
	sz = 0;
	while (map[i++])
		sz++;
	return (sz);
}
