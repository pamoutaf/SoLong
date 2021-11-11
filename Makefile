# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:15:30 by pamoutaf          #+#    #+#              #
#    Updated: 2021/11/10 17:00:33 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

SRCS = ./srcs/

SOURCES =	init_map.c ${SRCS}get_next_line.c \
			${SRCS}get_next_line_utils.c \

OBJECTS = $(subst .c,.o,$(SOURCES))

CFLAGS = -Wall -Wextra -g #-Werror
LINKS = -I libft -L libft \
    -I /usr/local/include -L /usr/local/lib \
    -l mlx -framework OpenGL -framework Appkit \
	
all : $(NAME)

$(NAME): $(OBJECTS)
			gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)


clean:
	/bin/rm -f $(OBJECTS) all

fclean: clean
	/bin/rm -f $(NAME) all

re: fclean all

.PHONY: clean fclean re all
