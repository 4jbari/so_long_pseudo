/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajbari <ajbari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:13:31 by ajbari            #+#    #+#             */
/*   Updated: 2024/05/22 13:12:55 by ajbari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int yo, int xo, t_game *game)
{
	int	new_y;
	int	new_x;

	new_y = game->player->instances->y + yo;
	new_x = game->player->instances->x + xo;
	ft_printf("moves:%d\n", game->movement++);
	if (game->map[(new_y - yo) / 64][(new_x - xo) / 64 / 64] != 'E')
		game->map[game->player->instances->y / 64][game->player->instances->x
			/ 64] = '0';
	if (game->map[new_y / 64][new_x / 64] == 'C')
	{
		game->map[new_y / 64][new_x / 64] = 'P';
		mlx_delete_image(game->mlx, game->player);
		print_element(new_x, new_y, "textures/RockWall_Dark.png", game);
		get_player(game->map, game, game->mlx, game->path);
		game->c--;
		return ;
	}
	if (new_y / 64 == game->exity && new_x / 64 == game->exitx && game->c == 0)
		exit(1);
	game->player->instances->y += yo;
	game->player->instances->x += xo;
}

void	move_right(int yo, int xo, t_game *game)
{
	int	new_y;
	int	new_x;

	game->path = "textures/right.png";
	new_y = game->player->instances->y + yo;
	new_x = game->player->instances->x + xo;
	ft_printf("moves:%d\n", game->movement++);
	if (game->map[(new_y - yo) / 64][(new_x - xo) / 64] != 'E')
		game->map[(new_y - yo) / 64][(new_x - xo) / 64] = '0';
	if (game->map[new_y / 64][new_x / 64] == 'C')
	{
		game->map[new_y / 64][new_x / 64] = 'P';
		mlx_delete_image(game->mlx, game->player);
		print_element(new_x, new_y, "textures/RockWall_Dark.png", game);
		get_player(game->map, game, game->mlx, "textures/right.png");
		game->c--;
		return ;
	}
	game->map[new_y / 64][new_x / 64] = 'P';
	mlx_delete_image(game->mlx, game->player);
	get_player(game->map, game, game->mlx, "textures/right.png");
	if (new_y / 64 == game->exity && new_x / 64 == game->exitx && game->c == 0)
		exit(1);
}

void	move_left(int yo, int xo, t_game *game)
{
	int	new_y;
	int	new_x;

	game->path = "textures/left.png";
	new_y = game->player->instances->y + yo;
	new_x = game->player->instances->x + xo;
	ft_printf("moves:%d\n", game->movement++);
	if (game->map[(new_y - yo) / 64][(new_x - xo) / 64] != 'E')
		game->map[(new_y - yo) / 64][(new_x - xo) / 64] = '0';
	if (game->map[new_y / 64][new_x / 64] == 'C')
	{
		game->map[new_y / 64][new_x / 64] = 'P';
		mlx_delete_image(game->mlx, game->player);
		print_element(new_x, new_y, "textures/RockWall_Dark.png", game);
		get_player(game->map, game, game->mlx, "textures/left.png");
		game->c--;
		return ;
	}
	game->map[new_y / 64][new_x / 64] = 'P';
	mlx_delete_image(game->mlx, game->player);
	get_player(game->map, game, game->mlx, "textures/left.png");
	if (new_y / 64 == game->exity && new_x / 64 == game->exitx && game->c == 0)
		exit(1);
}

void	my_keyhook(mlx_key_data_t keydata, void *parm)
{
	t_game	*game;

	game = (t_game *)parm;
	game->yinstance = game->player->instances->y;
	game->xinstance = game->player->instances->x;
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action && game->map[game->yinstance / 64 + 1][game->xinstance
		/ 64] != '1')
		move_player(64, 0, game);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action && game->map[game->yinstance / 64 - 1][game->xinstance
		/ 64] != '1')
		move_player(-64, 0, game);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action && game->map[game->yinstance / 64][game->xinstance
		/ 64 + 1] != '1')
		move_right(0, 64, game);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action && game->map[game->yinstance / 64][game->xinstance
		/ 64 - 1] != '1')
		move_left(0, -64, game);
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(1);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		y;

	(void)ac;
	if (!av[1])
		ft_error("Error:no file\n", 2);
	game.map = parsing(av[1], &game);
	game.x = ft_strlen(game.map[0]);
	y = 0;
	while (game.map[y])
		y++;
	game.y = y;
	if (game.y > 22 || game.x > 40)
		ft_error("Error: map is too big\n", 2);
	game.mlx = mlx_init(game.x * 64, game.y * 64, "so_long", false);
	if (!game.mlx)
		ft_error("Error:Mlx init failed\n", 2);
	print_background(game.map, game.mlx, &game);
	game.path = "textures/right.png";
	game.movement = 1;
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
}
