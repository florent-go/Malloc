ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
SYMLINK = libft_malloc.so

# LIBFT_DIR = ./libft
SRC_DIR = ./srcs
OBJ_DIR = ./objs
INCLUDE_DIR = ./includes

CC = cc
# CFLAGS = -Wall -Wextra -Werror -fPIC
CFLAGS = -fPIC
LDFLAGS = -shared

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SOURCES = srcs/*.c

OBJECTS = $(SOURCES:%.c=$(PATH_OBJ)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)
	ln -sf $(NAME) $(SYMLINK)
	echo "✅ Compilation terminée : $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Nettoyage des fichiers objets."

fclean: clean
	@rm -f $(NAME) $(SYMLINK)
	@echo "🚮 Suppression complète."

re: fclean all