/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:19:09 by ajbari            #+#    #+#             */
/*   Updated: 2024/05/22 11:24:25 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_player(t_game *game, void *mlx, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error("Error:load_png failed\n", 2);
	game->player = mlx_texture_to_image(mlx, texture);
	if (!game->player)
		ft_error("Error:texture_to_image failed\n", 2);
	mlx_delete_texture(texture);
	if (mlx_image_to_window(mlx, game->player, game->x, game->y) < 0)
		ft_error("Error:image_to_window failed\n", 2);
}

void	print_element(int x, int y, char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	img = NULL;
	texture = mlx_load_png(path);
	if (!texture)
		ft_error("Error:loading png failed\n", 2);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		ft_error("Error:mlx_texture_to_imag failed\n", 2);
	mlx_delete_texture(texture);
	if (mlx_image_to_window(game->mlx, img, x, y) < 0)
		ft_error("Error:image_to_window failed\n", 2);
}

void	print_stone(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->y = 0;
	while (map[j])
	{
		game->x = 0;
		i = 0;
		while (map[j][i])
		{
			print_element(game->x, game->y, "textures/RockWall_Dark.png", game);
			game->x += 64;
			i++;
		}
		j++;
		game->y += 64;
	}
}

void	print_background(char **map, void *mlx, t_game *game)
{
	int	i;
	int	j;

	print_stone(map, game);
	game->y = 0;
	j = 0;
	while (map[j])
	{
		game->x = 0;
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				print_element(game->x, game->y, "textures/stone.png", game);
			else if (map[j][i] == 'C')
				print_element(game->x, game->y, "textures/apple.png", game);
			else if (map[j][i] == 'E')
				print_element(game->x, game->y, "textures/exit.png", game);
			game->x += 64;
			i++;
		}
		j++;
		game->y += 64;
	}
	get_player(map, game, mlx, "textures/right.png");
}
