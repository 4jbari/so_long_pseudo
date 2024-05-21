NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ~/MLX42

LIBFTPATH	= libft
LIBFT       = $(LIBFTPATH)/libft.a

PRINTFPATH 	= ft_printf
PRINTF	    = $(PRINTFPATH)/libftprintf.a

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit \
			$(LIBFTPATH)/libft.a $(PRINTFPATH)/libftprintf.a
SRCS	:= so_long.c parsing.c parsing_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
OBJS	:= ${SRCS:.c=.o}

# FS = -fsanitize=address -g


all: libmlx $(LIBFT) $(PRINTF) $(NAME) 

$(LIBFT) : 
	make -C $(LIBFTPATH) 

$(PRINTF) :
	make -C $(PRINTFPATH) all

libmlx: 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	@$(CC)  $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFTPATH)/*.o
	@rm -rf $(PRINTFPATH)/*.o

fclean: clean
	@rm -rf $(LIBMLX)/build
	@rm -rf $(NAME)

	@rm -rf $(LIBFTPATH)/*.a
	@rm -rf $(PRINTFPATH)/*.a

re: clean all

.PHONY: all, clean, fclean, re, libmlx