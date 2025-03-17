SRC_FILES = main.c errors/check_error.c errors/errors.c errors/utils.c errors/under_five_case.c \
	rules/swap_and_push.c rules/rotation.c chunks_sort/indexing.c chunks_sort/pseudo_sort.c \
	chunks_sort/is_already_sorted.c chunks_sort/sort.c chunks_sort/utils.c

BONUS = bonus/main_bonus.c bonus/errors_bonus/check_error_bonus.c bonus/errors_bonus/errors_bonus.c \
	bonus/errors_bonus/utils_bonus.c bonus/utils_bonus.c bonus/rules_bonus/apply_rule_bonus.c \
	bonus/rules_bonus/swap_and_push_bonus.c bonus/rules_bonus/rotation.c bonus/rules_bonus/double_rule.c \
	bonus/gnl_bonus.c bonus/gnl_utils_bonus.c


LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

AR = ar scr
CC = cc
RM = rm  -rf
FLAGS = -Werror -Wextra -Wall -g
NAME = push_swap
BONUS_NAME = checker
SRC_OBJ = $(SRC_FILES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all : $(NAME)

$(LIBFT) :
		make -C $(LIBFT_DIR) ; make bonus -C $(LIBFT_DIR)

$(NAME) : $(SRC_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SRC_OBJ) $(LIBFT) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

bonus : $(BONUS_NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	$(RM) $(SRC_OBJ) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all bonus clean fclean re
