/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:35:19 by ajbari            #+#    #+#             */
/*   Updated: 2024/05/22 13:09:26 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_find(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '1' || x < 0 || x > (int)(ft_strlen(map[1])) || y < 0
		|| y > game->lines)
		return ;
	if (map[y][x] == 'C')
		game->coin++;
	if (map[y][x] == 'E')
		game->exit++;
	if (map[y][x] && map[y][x] != '1')
		map[y][x] = '1';
	path_find(game, map, x - 1, y);
	path_find(game, map, x, y + 1);
	path_find(game, map, x + 1, y);
	path_find(game, map, x, y - 1);
}

void	find_palyer(t_game *game, char **map)
{
	int	ys;
	int	xs;

	ys = 0;
	xs = 0;
	while (map[ys])
	{
		xs = 0;
		while (map[ys][xs])
		{
			if (map[ys][xs] == 'P')
			{
				game->x = xs;
				game->y = ys;
			}
			if (map[ys][xs] != '1' && map[ys][xs] != '0' && map[ys][xs] != 'C'
				&& map[ys][xs] != 'P' && map[ys][xs] != 'E')
				ft_error("Error:incorrect character\n", 2);
			xs++;
		}
		ys++;
	}
	game->lines = ys; 
}

int	ft_strlen_nl(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	free_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
}

char	**copy_map(char **buffer, t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = game->lines;
	map = malloc(sizeof(char **) * (j + 1));
	while (buffer[i])
	{
		map[i] = ft_strdup(buffer[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}
