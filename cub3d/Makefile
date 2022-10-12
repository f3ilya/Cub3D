NAME	= cub3d

SRCS	=	src/main.c\
          	src/chk_map.c\
          	src/chk_textures.c\
          	src/hook.c\
          	src/init.c\
          	src/minimap.c\
          	src/scene.c\
          	src/texture.c\
          	common_funcs/cub_utils.c\
            common_funcs/ft_split.c\
            common_funcs/ft_split2.c\
            common_funcs/gnl.c\
            common_funcs/libft_func1.c

OBJS	= ${SRCS:.c=.o}

HDRS	= -I./includes/cub3d.h

MLX		=	mlx/libmlx.a

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror ${HDRS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${MAKE} -C mlx/
				${CC} ${HDRS} ${OBJS} ${MLX} -framework OpenGL -framework AppKit -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${MAKE} -C mlx/ clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
