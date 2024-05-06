# ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
# include "libft/libft.h"
#ifndef BUFFERSIZE

#define BUFFERSIZE 4
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);


//reedited ft_strlen and ft_strjoin

# endif