CFILES = ft_memcpy.c ft_isdigit.c  ft_strlen.c ft_bzero.c ft_isprint.c ft_memset.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_substr.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BFILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c  ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
TOOBJ = $(CFILES:.c=.o)
BTOOBJ = $(BFILES:.c=.o)

all: $(NAME)

$(NAME):$(TOOBJ)
	ar rcs $(NAME) $(TOOBJ)

bonus: $(BTOOBJ)
	ar rcs $(NAME) $(BTOOBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fr $(TOOBJ) $(BTOOBJ)

fclean: clean
	@rm -fr $(NAME)

re: fclean all

.PHONY: clean fclean re bonus all
