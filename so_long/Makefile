SRC_FILES =  main.c  game/map.c game/render.c game/move.c game/utils.c \
	parse_input/check_error.c parse_input/check_road.c parse_input/errors.c \
	parse_input/parse_utils.c parse_input/valid_map.c \
	gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c 

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc -I/usr/include -Imlx_linux -O3
RM = rm -rf
FLAGS = -Werror -Wextra -Wall
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME = so_long
SRC_OBJ = $(SRC_FILES:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) ; make -C $(LIBFT_DIR) bonus

$(NAME): $(SRC_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SRC_OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.SECONDARY: $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
