# ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>//
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <MLX42/MLX42.h>

#ifndef BUFFERSIZE

#define BUFFERSIZE 4
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int     check_format(char *av);
void    ft_read1(int fd, char ***buffer);
void    check_size(char **map);
void    check_elements(char **buffer);
int    check_path(char **map);






//reedited ft_strlen and ft_strjoin

# endif