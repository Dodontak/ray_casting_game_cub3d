# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 17:58:31 by byejeon           #+#    #+#              #
#    Updated: 2023/04/07 14:00:13 by byejeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isascii.c ft_isprint.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_atoi.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c ft_bzero.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_calloc.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c ft_isalnum.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SOBJECTS = $(SRCS:.c=.o)
BOBJECTS = $(BONUS:.c=.o)

CC = cc
CFLAGS = -c -Wall -Wextra -Werror

ifdef WITH_BONUS
	OB = $(SOBJECTS) $(BOBJECTS)
else
	OB = $(SOBJECTS)
endif

all : $(NAME)

$(NAME) : $(OB)
	ar -rc $@ $^

bonus :
	make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf $(SOBJECTS) $(BOBJECTS)

fclean : clean
	rm -rf $(NAME)

re :
	make clean
	make all

.PHONY: all bonus clean fclean re
