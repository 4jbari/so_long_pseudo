# ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>//
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <MLX42/MLX42.h>

#ifndef BUFFERSIZE

#define BUFFERSIZE 4
#endif
typedef struct info{
    int         c;
    int         x;
    int         y;
    int         lines;
    mlx_image_t *player;
    mlx_t       *mlx;
    char        **map;
    int         exit;
    int         coin;
    char        *path;
    int         exitx;
    int         exity;
    //for iter
    int         j;
    int         i;
    int         xinstance;
    int         yinstance;
    int         movement;
} game_t;

char    **parsing(char *av, game_t *game);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int     check_format(char *av);
void    ft_read1(int fd, char ***buffer);
void    check_size(char **map);
void    check_elements(char **buffer, game_t *game);
int    check_path(game_t *game, char **map);

char    **copy_map(char **buffer);
void    free_map(char **map);






//reedited ft_strlen and ft_strjoin

# endif