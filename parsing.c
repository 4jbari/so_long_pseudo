/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:25:44 by ajbari            #+#    #+#             */
/*   Updated: 2024/05/22 13:09:28 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(t_game *game, char **map)
{
	char	**map_copy;

	find_palyer(game, map);
	map_copy = copy_map(map, game);
	game->coin = 0;
	game->exit = 0;
	path_find(game, map_copy, game->x, game->y);
	if (game->coin != game->c || game->exit != 1)
		ft_error("Error:there is no path to E or C\n", 2);
	free_map(map_copy);
	return (0); 
}

void	check_elements(char **buffer, t_game *game)
{
	game->ecount = 0;
	game->pcount = 0;
	game->c = 0;
	game->y = 1;
	while (buffer[game->y])
	{
		game->x = 0;
		while (buffer[game->y][game->x])
		{
			if (buffer[game->y][game->x] == 'E')
			{
				game->ecount++;
				game->exitx = game->x;
				game->exity = game->y;
			}
			else if (buffer[game->y][game->x] == 'C')
				game->c++;
			else if (buffer[game->y][game->x] == 'P')
				game->pcount++;
			game->x++;
		}
		game->y++;
	}
	if (game->ecount != 1 || game->pcount != 1 || game->c < 1)
		ft_error("Error:must at least one: E,C,P and at most 1 :E ,P\n", 2);
}

void	check_size(char **map)
{
	size_t	j;
	size_t	i;
	size_t	y;

	i = 0;
	j = 0;
	y = 0;
	while (map[j])
	{
		if (map[j + 1] && (ft_strlen(map[j]) != ft_strlen(map[j + 1])))
			ft_error("Error:invalidMap / not rectangular\n", 2);
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			ft_error("Error:Invalid Map\n", 2);
		j++;
	}
	j--;
	while (map[0][y] && map[0][y] == '1' && map[j][y] == '1')
		y++;
	if (y != ft_strlen(map[0]))
		ft_error("Error:the firstline and the last must be walls\n", 2);
}

void	ft_read1(int fd, char ***buffer)
{
	char	*line;
	char	*jn;
	int		len1;

	line = NULL;
	jn = NULL;
	line = get_next_line(fd);
	len1 = ft_strlen_nl(line);
	jn = ft_join(jn, line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		jn = ft_join(jn, line);
		if (line)
			if (ft_strlen_nl(line) != len1)
				ft_error("Error:not equal lines", 2);
	}
	free(line);
	*buffer = ft_split(jn, '\n');
	free(jn);
}

char	**parsing(char *av, t_game *game)
{
	char	**buffer;
	int		fd;

	buffer = NULL;
	if (!check_format(av))
		ft_error("Error:WrongFormat\n", 2);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("Error:NoExistingFile\n", 2);
	ft_read1(fd, &buffer);
	check_size(buffer);
	game->c = 0;
	check_elements(buffer, game);
	check_path(game, buffer);
	return (buffer);
}
