SRC_FILES = child_processes.c pipex_utils.c pipe.c
BONUS = bonus/child_managment_bonus.c bonus/pipex_utils_bonus.c bonus/pipe_bonus.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

AR = ar scr
CC = cc
RM = rm  -rf
FLAGS = -Werror -Wextra -Wall
NAME = pipex
SRC_OBJ = $(SRC_FILES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all : $(NAME)

$(LIBFT) :
		make -C $(LIBFT_DIR)

$(NAME) : $(SRC_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SRC_OBJ) $(LIBFT) -o $(NAME)

bonus : $(BONUS_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	$(RM) $(SRC_OBJ) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all bonus clean fclean re
