NAME 	= libft.a
CC		= gcc
RM		= rm -f
ARRC 	= ar rc

CFLAGS = -Wall -Wextra -Werror
FCTS    = ./fcts/
SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c\
		ft_isprint.c ft_itoa.c ft_memccpy.c ft_memcpy.c ft_memchr.c\
		ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
		ft_substr.c ft_printf.c\
		${FCTS}ft_conversions.c \
        ${FCTS}ft_lens.c \
		${FCTS}ft_printf_utils.c \
		${FCTS}ft_printf.c
		
SRCS_BONUS = ft_lstnew.c

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