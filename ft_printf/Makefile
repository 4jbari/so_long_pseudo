CFILES = ft_printf.c ft_putaddress.c

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJ = $(CFILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rc $(NAME) $(OBJ) 


%.o:%.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM)  $(NAME)

re : fclean all

.PHONY : all clean fclean re
