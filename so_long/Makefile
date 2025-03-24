# Source files
SRC_FILES = mlx_test.c  # Add your source files here

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
