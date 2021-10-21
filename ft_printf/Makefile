# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:48:38 by pamoutaf          #+#    #+#              #
#    Updated: 2021/10/19 12:56:50 by pamoutaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
CC      = gcc
RM      = rm -f
ARRC    = ar rc
FCTS    = ./fcts/
SRCS    =   ${FCTS}ft_conversions.c \
            ${FCTS}ft_lens.c \
            ${FCTS}ft_printf_utils.c \
			${FCTS}ft_conver_p.c \
            ${FCTS}ft_printf.c \
			${FCTS}ft_double_percent.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: $(SRCS_PATH)%.c
	$(CC) $(FLAGS) -I $(FCTS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.PHONY: clean

clean:
	/bin/rm -f $(OBJS) all

fclean: clean
	/bin/rm -f $(NAME) all

re: fclean all