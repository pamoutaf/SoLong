# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:15:30 by pamoutaf          #+#    #+#              #
#    Updated: 2021/11/16 11:10:27 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

SRCS = ./srcs/

SOURCES =	ft_keys.c main.c init_map.c ${SRCS}get_next_line.c \
			${SRCS}get_next_line_utils.c \

OBJECTS = $(subst .c,.o,$(SOURCES))

CFLAGS = -Wall -Wextra -g -I libft -I minilibx_mms_20200219/ #-Werror
LINKS = -L libft \
	-L. -lmlx
	
all : $(NAME)

$(NAME): $(OBJECTS)
			gcc $(OBJECTS) -o $(NAME) $(FLAGS) $(LINKS)


clean:
	/bin/rm -f $(OBJECTS) all

fclean: clean
	/bin/rm -f $(NAME) all

re: fclean all

.PHONY: clean fclean re all
