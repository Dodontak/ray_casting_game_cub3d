# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:45:29 by byejeon           #+#    #+#              #
#    Updated: 2023/07/24 14:10:05 by byejeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parse.a

SRC = parse.c \
	  make_rawdata.c check_input_error.c check_invalid_file.c print_err_and_exit.c\
	  get_matrix_len.c get_strs_len.c count_char_in_str.c check_path.c\
	  set_texture_names.c make_matrix_from_rawdata.c set_pos_xy.c set_map_xy.c\
	  get_map_start_idx_in_matrix.c check_invalid_map.c make_base_map.c\
	  check_and_set_color.c set_map.c check_invalid_textures.c\
	  free_strs.c free_matrix.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -c -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS = -g -c -Wall -Wextra -Werror
endif

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re :
	make clean
	make all

.PHONY: all clean fclean re

.PHONY: debug
debug:
	make DEBUG=1
