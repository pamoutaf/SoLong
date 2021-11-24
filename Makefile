# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:15:30 by pamoutaf          #+#    #+#              #
#    Updated: 2021/11/23 17:37:33 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = main

SRCS = ./srcs/

SOURCES =   ft_images.c ft_keys.c main.c init_map.c ${SRCS}get_next_line.c \
			${SRCS}get_next_line_utils.c

OBJECTS = $(subst .c,.o,$(SOURCES))

CFLAGS = -Wall -Wextra -g -I libft -I minilibx_mms_20200219/ -g #-fsanitize=address#-Werror
LINKS = -g -L libft \
		-L. -lmlx -framework OpenGL -framework AppKit 

all : $(NAME)

$(NAME): $(OBJECTS)
			gcc $(OBJECTS) -o $(NAME) $(CFLAGS) $(LINKS)

clean:
	/bin/rm -f $(OBJECTS) all

fclean: clean
	/bin/rm -f $(NAME) all

re: fclean all

.PHONY: clean fclean re all
