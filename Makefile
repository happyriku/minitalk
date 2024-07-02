NAME = minitalk.a
NAME_CLIENT = client
NAME_SERVER = server

LIBRARY_PRINTF = minitalk_utils/libftprintf.a
SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Imintalk.h 
MAKE = make
RM = rm -f

all: $(NAME)

$(NAME) : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJS_CLIENT) $(LIBRARY_PRINTF)
		$(CC) $(CFLAGS) $^ -o $@

$(NAME_SERVER) : $(OBJS_SERVER) $(LIBRARY_PRINTF)
		$(CC) $(CFLAGS) $^ -o $@

$(LIBRARY_PRINTF) :
		$(MAKE) -C ./minitalk_utils

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C ./minitalk_utils clean


fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C ./minitalk_utils fclean

re: fclean all

.PHONY: all clean fclean re