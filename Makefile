cc = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = printf.a

SRCS = libftprintf.c putnbr.c strs.c

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.Phony: clean fclean all re 