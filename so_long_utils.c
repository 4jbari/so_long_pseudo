/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:18:36 by ajbari            #+#    #+#             */
/*   Updated: 2024/05/22 12:05:29 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *av)
{
	int		i;
	int		j;
	char	*ber;

	j = 0;
	i = 0;
	ber = ".ber";
	while (av[i])
		i++;
	if (av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b' 
		&& av[i - 4] == '.')
		return (1);
	return (0);
}

void	ft_error(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit(1);
}

void	get_player(char **map, t_game *game, void *mlx, char *path)
{
	game->x = 0;
	game->y = 0;
	game->j = 0;
	game->i = 0;
	while (map[game->j])
	{
		game->i = 0;
		game->x = 0;
		while (map[game->j][game->i])
		{
			if (map[game->j][game->i] == 'P')
				print_player(game, mlx, path);
			game->i++;
			game->x += 64;
		}
		game->y += 64;
		game->j++;
	}
}
