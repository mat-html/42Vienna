NAME        = bsq

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

SRC_DIR     = src
OBJ_DIR     = obj

SRC_FILES   = main.c error_handling.c ft_putchar.c ft_putstr.c \
              generate_map.c open_file.c ft_strl.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
