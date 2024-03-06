ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

PATH_INC = include
PATH_OBJ = obj
PATH_SRC = src

SOURCES += utils/block.c malloc.c

OBJECTS = $(SOURCES:%.c=$(PATH_OBJ)/%.o)

NAME = libft_malloc_$(HOSTTYPE).so
LIB_NAME = libft_malloc.so
CC = gcc
FLAG_CC = -fPIC
FLAGS_LIB = -shared

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
		$(CC) $(FLAGS_LIB) -o $@ $(OBJECTS)
		@rm -f $(LIB_NAME)
		ln -s $(NAME) $(LIB_NAME)
		@echo "Make done"

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c
		@mkdir -p $(@D)
		$(CC) -c -o $@ $(FLAG_CC) $^ -g -I $(PATH_INC)

clean:
		@rm -rf $(PATH_OBJ)
		@echo "Clean done"

fclean: clean
		@rm -f $(NAME) $(LIB_NAME)
		@echo "fclean done"

re: fclean $(NAME)