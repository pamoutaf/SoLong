# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:15:30 by pamoutaf          #+#    #+#              #
#    Updated: 2021/12/08 12:51:40 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_GNL = ./gnl/

SOURCES =   ft_images.c ft_keys.c main.c init_map.c ${SRCS_GNL}get_next_line.c ft_itoa.c \
            ${SRCS_GNL}get_next_line_utils.c ft_protections.c ft_protections_2.c \
			ft_button_hook.c

HEADERS =	solong.h mlx/mlx.h gnl/get_next_line.h

OBJECTS = $(subst .c,.o,$(SOURCES))

CFLAGS = -Wall -Wextra -Werror -I mlx/
LINKS = -L. -lmlx

all: $(NAME)

libmlx.dylib:
			$(MAKE) -C mlx/
			cp mlx/libmlx.dylib .
	

$(NAME): $(OBJECTS) $(HEADERS) libmlx.dylib
			gcc $(OBJECTS) -o $(NAME) $(CFLAGS) $(LINKS)

clean:
	/bin/rm -f $(OBJECTS) all 
	$(MAKE) clean -C mlx/

fclean: clean
	/bin/rm -f $(NAME) all libmlx.dylib

re: fclean all

.PHONY: clean fclean re all
