CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I../includes

SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:srcs/%.c=objs/%.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) ../libft.a
	ar rcs $@ $^

objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f objs/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re