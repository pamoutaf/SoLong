# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:15:30 by pamoutaf          #+#    #+#              #
#    Updated: 2021/10/21 13:50:32 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

SOURCES = main.c

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra #-Werror
LINKS = -I libft -L libft \
		-I ft_printf/fcts/ft_printf -L ft_printf/fcts/ft_printf \
    -I /usr/local/include -L /usr/local/lib \
    -l mlx -framework OpenGL -framework Appkit \
	

$(NAME): $(OBJECTS)
			gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)

.PHONY: clean

clean:
	/bin/rm -f $(OBJECTS) all

fclean: clean
	/bin/rm -f $(NAME) all

re: fclean all
