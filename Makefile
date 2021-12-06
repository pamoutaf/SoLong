# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:15:30 by pamoutaf          #+#    #+#              #
#    Updated: 2021/12/06 11:41:20 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong

SRCS = ./srcs/

SOURCES =   ft_images.c ft_keys.c main.c init_map.c ${SRCS}get_next_line.c ft_itoa.c \
            ${SRCS}get_next_line_utils.c ft_protections.c ft_protections_2.c

OBJECTS = $(subst .c,.o,$(SOURCES))

CFLAGS = -Wall -Wextra -Werror -g -I libft -I minilibx_mms_20200219/ -g -fsanitize=address
LINKS = -L. -lmlx -framework OpenGL -framework AppKit 

all : $(NAME)

$(NAME): $(OBJECTS)
			gcc $(OBJECTS) -o $(NAME) $(CFLAGS) $(LINKS)

clean:
	/bin/rm -f $(OBJECTS) all

fclean: clean
	/bin/rm -f $(NAME) all

re: fclean all

.PHONY: clean fclean re all
