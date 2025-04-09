# Makefile pour libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Sources et objets pour libft
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:srcs/%.c=objs/%.o)

# Nom de la bibliothèque
NAME = libft.a

all: $(NAME)

# Règle pour créer la bibliothèque statique libft
$(NAME): $(OBJ)
	ar rcs $@ $^

# Règle pour compiler les fichiers sources en fichiers objets
objs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers objets
clean:
	rm -f objs/*.o

# Nettoyer les fichiers objets et la bibliothèque
fclean: clean
	rm -f $(NAME)

# Recompiler après nettoyage
re: fclean all

.PHONY: all clean fclean re