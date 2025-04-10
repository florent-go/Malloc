ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
SYMLINK = libft_malloc.so

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
LDFLAGS = -shared

SRCS_DIR = srcs/
LIBFT_SRCS_DIR = libft/srcs/
FT_PRINTF_SRCS_DIR = libft/ft_printf/srcs/

VPATH := $(SRCS_DIR) $(LIBFT_SRCS_DIR) $(FT_PRINTF_SRCS_DIR)

OBJS_DIR = objs/
INC_DIR = includes/ libft/includes/ libft/ft_printf/includes/

SRCS = $(wildcard $(SRCS_DIR)*.c)
LIBFT_SRCS = $(wildcard $(LIBFT_SRCS_DIR)*.c)
FT_PRINTF_SRCS = $(wildcard $(FT_PRINTF_SRCS_DIR)*.c)

INC := $(addprefix -I, $(INC_DIR))

ALL_SRCS := $(SRCS) $(LIBFT_SRCS) $(FT_PRINTF_SRCS)

OBJS := $(patsubst %.c, $(OBJS_DIR)%.o, $(notdir $(ALL_SRCS)))

all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	ln -sf $@ $(SYMLINK)
	echo "✅ Compilation terminée : $(NAME)"

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Nettoyage des fichiers objets."

fclean: clean
	@rm -rf $(NAME) $(SYMLINK)
	@echo "🚮 Suppression complète."

re: fclean all

.PHONY: all clean fclean re
