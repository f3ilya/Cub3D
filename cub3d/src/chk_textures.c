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

int	check_xpm(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".xpm", 4))
		return (1);
	return (0);
}

int	parse_color(int *val, char *path)
{
	int		rgb[3];
	char	**str;

	if (*val != -1)
		return (12);
	str = ft_split(path, ',');
	rgb[0] = ft_atoi_cub(str[0]);
	rgb[1] = ft_atoi_cub(str[1]);
	rgb[2] = ft_atoi_cub(str[2]);
	if (rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		return (1);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		return (1);
	*val = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	ft_free(str);
	return (0);
}

int	parse_texture(t_all *a, int **val, char *path)
{
	void	*tex_img;
	int		arg[2];
	int		argg[3];
	int		*tmp;
	int		i;

	if (check_xpm(path))
		return (13);
	tex_img = mlx_xpm_file_to_image(a->mlx.mlx, path, &arg[0], &arg[1]);
	if (!tex_img)
		return (14);
	tmp = (int *)mlx_get_data_addr(tex_img, &argg[0], &argg[1], &argg[2]);
	*val = (int *) malloc(sizeof(int) * 4096);
	i = -1;
	while (++i < 4096)
		(*val)[i] = tmp[i];
	mlx_destroy_image(a->mlx.mlx, tex_img);
	return (0);
}

int	assign_tex(t_all *a, char *str)
{
	char		**str_arr;
	int			w_count;
	static int	err;

	str_arr = ft_split2(str, ' ', &w_count);
	if (w_count != 2)
		return (free_and_return(str_arr, 0));
	if (!ft_strncmp(str_arr[0], "NO", 3))
		err = parse_texture(a, &a->map.no, str_arr[1]);
	else if (!ft_strncmp(str_arr[0], "SO", 3))
		err = parse_texture(a, &a->map.so, str_arr[1]);
	else if (!ft_strncmp(str_arr[0], "WE", 3))
		err = parse_texture(a, &a->map.we, str_arr[1]);
	else if (!ft_strncmp(str_arr[0], "EA", 3))
		err = parse_texture(a, &a->map.ea, str_arr[1]);
	else if (!ft_strncmp(str_arr[0], "F", 2))
		err = parse_color(&a->map.f, str_arr[1]);
	else if (!ft_strncmp(str_arr[0], "C", 2))
		err = parse_color(&a->map.c, str_arr[1]);
	else
		return (free_and_return(str_arr, 0));
	if (err != 0)
		return (free_and_return(str_arr, 0));
	a->map.count = a->map.count + 1;
	return (free_and_return(str_arr, 1));
}

void	read_config(t_all *a, char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_free_exit("Map cannot be opened", a);
	a->map.map = (char **)malloc(sizeof(char *) * 1);
	a->map.map[0] = NULL;
	init_mlx(a);
	while ((get_next_line(&str, fd)))
	{
		if (*str == '\0')
		{
			free(str);
			if (a->map.map[0])
				break ;
			continue ;
		}
		if (a->map.count >= 6)
			a->map.map = append(a->map.map, str);
		if (a->map.count < 6 && !assign_tex(a, str))
			ft_free_exit("Not valid texture or color configuration.", a);
		free(str);
	}
	close(fd);
}
