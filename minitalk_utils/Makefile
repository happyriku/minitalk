NAME = libftprintf.a
SRCS = ft_atoi.c ft_printf.c ft_put_unsigned_nbr.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c

# OBJS = $(SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ift_printf.h -Ilibft.h
RM = rm -f

$(NAME):$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re