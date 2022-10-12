/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:29:33 by                   #+#    #+#             */
/*   Updated: 2021/12/25 14:50:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../mlx/mlx.h"
# include <math.h>

# define FOV 0.66
# define WIN_HEIGHT 720
# define WIN_WIDTH 1280
# define SPD_K 0.15
# define SPD_M 0.04
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define ESC 53
# define MOVE_L 123
# define MOVE_R 124
# define POINT 12

typedef struct s_xy
{
	double	x;
	double	y;
}	t_xy;

typedef struct s_plr
{
	t_xy	pos;
	t_xy	dir;
}	t_plr;

typedef struct s_map {
	int		*no;
	int		*so;
	int		*we;
	int		*ea;
	int		f;
	int		c;
	int		x;
	int		y;
	int		count;
	char	**map;
}	t_map;

typedef struct s_wall
{
	int		height;
	int		start;
	int		tex_x;
	double	tex_y;
	double	dist;
}	t_wall;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits;
	int		size_l;
	int		end;
}	t_mlx;

typedef struct s_ray
{
	t_xy	dir;
	t_xy	delta;
	t_xy	dist;
	int		i;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

typedef struct s_all
{
	t_mlx	mlx;
	t_map	map;
	t_plr	plr;
	t_ray	ray;
	t_wall	wall;
	t_xy	plane;
	t_xy	mouse;
}	t_all;

int		get_next_line(char **line, int fd);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
char	**ft_split2(char const *s, char c, int *w_count);
char	**clear(char **dst);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	**append(char **map, char *str);
void	read_config(t_all *a, char *file);
int		chk_wall(char **map, int rows);
void	set_zero(char *arr, int n);
int		map_sz(char **map);
int		chk_symb(char **map, t_all *a, int i, char *sym);
void	check_valid(t_all *a);
int		ft_check_filename(char *str);
int		exit_func(char *msg);
char	*ft_strdup(const char *s);
int		ft_isdigit(int c);
int		ft_atoi_cub(char *str);
char	**ft_split(char const *s, char c);
int		free_and_return(char **str_arr, int return_val);

void	init(t_all *a);
void	init2(t_all *a);
void	init_mlx(t_all *a);

int		ft_hook(int key, t_all *a);
int		ft_exit(t_all *a);

void	draw_window(t_all *a);
void	draw_vertical(t_all *a);
void	floor_create(t_all *a, int i, int color);
void	img_pixel(t_all *a, int x, int y, int color);
void	minimap(t_all *a);

void	move_l_move_r(int key, t_all *a);
int		mouse(int x, int y, t_all *a);

void	ft_free(char **str);
void	ft_free_exit(char *msg, t_all *a);

#endif
