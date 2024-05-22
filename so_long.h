/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:40:18 by ajbari            #+#    #+#             */
/*   Updated: 2024/05/22 13:12:13 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFERSIZE

#  define BUFFERSIZE 4
# endif

typedef struct info
{
	int			c;
	int			x;
	int			y;
	int			lines;
	mlx_image_t	*player;
	mlx_t		*mlx;
	char		**map;
	int			exit;
	int			coin;
	char		*path;
	int			exitx;
	int			exity;
	int			j;
	int			i;
	int			xinstance;
	int			yinstance;
	int			ecount;
	int			pcount;
	int			movement;
}				t_game;

char			**parsing(char *av, t_game *game);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
int				check_format(char *av);
void			ft_read1(int fd, char ***buffer);
void			check_size(char **map);
void			check_elements(char **buffer, t_game *game);
int				check_path(t_game *game, char **map);
char			**copy_map(char **buffer, t_game *game);
void			free_map(char **map);
int				ft_strlen_nl(char *line);
void			ft_error(char *s, int fd);
void			find_palyer(t_game *game, char **map);
void			path_find(t_game *game, char **map, int x, int y);
void			print_player(t_game *game, void *mlx, char *path);
void			print_element(int x, int y, char *path, t_game *game);
void			get_player(char **map, t_game *game, void *mlx, char *path);
void			print_background(char **map, void *mlx, t_game *game);

#endif