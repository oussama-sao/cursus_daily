SRC_FILES = ft_putaddress_printf.c ft_putchar_printf.c ft_puthexa_printf.c ft_putnbr_printf.c ft_putnbr_u_printf.c \
	ft_putpourcent_printf.c ft_putstr_printf.c ft_printf.c
BONUS = bonus/ft_printf_bonus.c bonus/ft_putaddress_printf_bonus.c bonus/ft_putchar_printf_bonus.c \
	bonus/ft_puthexa_printf_bonus.c bonus/ft_putnbr_printf_bonus.c bonus/ft_putnbr_u_printf_bonus.c bonus/ft_putpourcent_printf_bonus.c bonus/ft_putstr_printf_bonus.c

AR = ar scr
CC = cc
RM = rm  -rf
FLAG = -Werror -Wextra -Wall
NAME = libftprintf.a
SRC_OBJ = $(SRC_FILES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(SRC_OBJ)
	$(AR) $(NAME) $(SRC_OBJ)

bonus : $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)
%.o : %.c
	$(CC) $(FLAG) -c $^ -o $@

clean :
	$(RM) $(SRC_OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
