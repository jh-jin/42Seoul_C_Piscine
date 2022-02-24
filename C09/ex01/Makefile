SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
HEADER = includes
CC = gcc
WFLAG = -Wall -Werror -Wextra
NAME = libft.a

%.o: %.c
	$(CC) $(WFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	ar -rc $@ $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
