# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 11:41:05 by byejeon           #+#    #+#              #
#    Updated: 2023/07/24 14:10:17 by seonlim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror

DIR_MLX = mlx_opengl
DIR_LIBFT = libft
DIR_GNL = get_next_line
DIR_PARSE = parse
MLX = libmlx.a
LIBFT = $(DIR_LIBFT)/libft.a
GNL = $(DIR_GNL)/libgnl.a
PARSE = $(DIR_PARSE)/parse.a

FRAME_WORK = -framework OpenGL -framework Appkit
SRCS = main.c \
	init_data.c \
	priority_queue.c \
	enemy_move.c \
	change_door_state.c \
	progress_door_state.c \
	mouse_hook.c \
	key_hook.c \
	loop_hook.c \
	ray_casting.c \
	ray_casting2.c \
	draw.c \
	draw_rays.c \
	draw_wall.c \
	draw_minimap.c \
	draw_stamina_bar.c \
	move.c \
	utils.c \
	is_in_circle.c \
	set_minimap_img.c \
	set_wall.c \
	draw_circle.c \
	pixel_put_in_map.c \
	fill_clear_pixel.c \
	sort_sprite.c \
	game_over.c \
	draw_sprites.c \
	set_sprites.c

DIR_OBJS = objs
OBJS = $(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

ifdef DEBUG
	CFLAGS = -g -Wall -Wextra -Werror
endif

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf $(DIR_OBJS)
	make -C $(DIR_LIBFT) fclean
	make -C $(DIR_GNL) fclean
	make -C $(DIR_PARSE) fclean

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean
	make all

.PHONY: debug
debug: fclean
	make -C $(DIR_PARSE) DEBUG=1
	make DEBUG=1

$(NAME) : $(OBJS) $(MLX) $(LIBFT) $(GNL) $(PARSE)
	$(CC) $(CFLAGS) $(FRAME_WORK) $(OBJS) $(MLX) $(LIBFT) $(GNL) $(PARSE) -o $(NAME)

$(DIR_OBJS)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(DIR_MLX) -o $@ -c $<

$(LIBFT) :
	make -C $(DIR_LIBFT)

$(GNL) :
	make -C $(DIR_GNL)

$(PARSE) :
	make -C $(DIR_PARSE)
