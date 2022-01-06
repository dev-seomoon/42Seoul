# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/14 13:25:02 by seomoon           #+#    #+#              #
#    Updated: 2021/02/22 03:12:19 by seomoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = arch -x86_64 gcc -g -I. -Wall -Wextra -Werror

MLX = -Lmlx_beta -lmlx -Lmlx -lmlxopengl -framework OpenGL -framework AppKit

NAME = cub3D

SRC_FILES = main.c game.c init.c keys.c clear.c \
	    treat_description.c config.c config_color.c \
	    treat_map.c valid_map.c \
	    raycast.c raycast2.c textures.c \
	    sprite.c draw_sprite.c sprite_image.c \
	    player.c camera.c bitmap.c image.c \
	    get_next_line.c \
	    utils/utils_libft.c utils/utils_ascii.c utils/utils_string.c

SRCS = $(addprefix srcs/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	arch -x86_64 $(MAKE) -C ./mlx_beta
	arch -x86_64 $(MAKE) -C ./mlx
	$(CC)  $(OBJS) $(MLX) -o $(NAME)
	install_name_tool -change libmlx.dylib ./mlx_beta/libmlx.dylib cub3D

all : $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C ./mlx
	$(MAKE) clean -C ./mlx_beta

fclean : clean
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all
