cc = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = printf.a

SRCS = ft_printf.c putnbr.c strs.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.Phony: clean fclean all re 
