# Source files
SRC_FILES =  main.c  game/map.c game/render.c parse_input/check_error.c \
		parse_input/check_road.c  parse_input/errors.c  parse_input/parse_utils.c \
		parse_input/valid_map.c gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c 

# Include directories
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

# Compiler and flags
CC = cc
CFLAGS = -Wall #-Wextra -Werror
LDFLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Output executable
NAME = so_long

# Object files
OBJ = $(SRC_FILES:.c=.o)

# Make rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
