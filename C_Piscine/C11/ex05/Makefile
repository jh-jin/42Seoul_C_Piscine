CC = gcc
WFLAGS = -Wall -Wextra -Werror
NAME = do-op
SRCS = srcs/ft_atoi.c srcs/ft_putnbr.c srcs/oprs.c srcs/main.c
OBJS = $(SRCS:.c=.o)
HEADER = includes
%.o : %.c
	$(CC) $(WFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS)
	$(CC) $(WFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
