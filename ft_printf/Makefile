SRC_FILES = ft_putaddress_printf.c ft_putchar_printf.c ft_puthexa_printf.c ft_putnbr_printf.c ft_putnbr_u_printf.c \
	ft_putpourcent_printf.c ft_putstr_printf.c ft_printf.c

AR = ar scr
CC = cc
RM = rm  -rf
FLAG = -Werror -Wextra -Wall
NAME = libftprintf.a
SRC_OBJ = $(SRC_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(SRC_OBJ)
	$(AR) $(NAME) $(SRC_OBJ)

bonus : $(NAME)

%.o : %.c
	$(CC) $(FLAG) -c $^ -o $@

clean :
	$(RM) $(SRC_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
