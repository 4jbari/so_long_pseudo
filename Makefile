NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ~/MLX42
LIBFT	:= libft
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit $(LIBFT)/libft.a
SRCS	:= so_long.c parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS	:= ${SRCS:.c=.o}

# FS = -fsanitize=address -g


all: libmlx libft $(NAME) 

libft :
	make -C $(LIBFT) all 

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC)  $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(LIBMLX)/build
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx