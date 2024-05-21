#include "so_long.h"

void	print_element(int x, int y, char *path, game_t *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	img = NULL;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error("Error:\nloading png failed", 2);

	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
		ft_error("Error\nmlx_texture_to_imag",2);

	mlx_delete_texture(texture);
	if (mlx_image_to_window(game->mlx, img, x, y) < 0)
		ft_error("Error\nimage_to_window failed", 2);

}
void	print_player(game_t *game, void *mlx, char *path)
{
	mlx_texture_t *texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error("Error\nload_png", 2);
	game->player = mlx_texture_to_image(mlx, texture);
	if (!game->player)
		ft_error("Error\ntexture_to_image failed", 2);
	mlx_delete_texture(texture);
	if (mlx_image_to_window(mlx, game->player, game->x, game->y) < 0)
		ft_error("Error\nimage_to_window failed", 2);

}

void	get_player(char **map, game_t *game, void *mlx, char *path)
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
void print_stone(char **map, game_t *game)
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
			print_element(game->x, game->y, "RockWall_Dark.png", game);
			game->x += 64;
			i++;
		}
		j++;
		game->y += 64;
	}
}
void	print_background(char **map, void *mlx, game_t *game)
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
				print_element(game->x, game->y, "stone.png", game);
			else if (map[j][i] == 'C')
				print_element(game->x, game->y,"apple.png", game);
			else if (map[j][i] == 'E')
				print_element(game->x, game->y, "exit.png", game);
			game->x += 64;
			i++;
		}
		j++;
		game->y += 64;
	}
	get_player(map, game, mlx, "right.png");
}

void	move_player(int yo, int xo, game_t *game)
{
	int	new_y;
	int	new_x;

	new_y = game->player->instances->y + yo;
	new_x = game->player->instances->x + xo;
	if (game->map[(new_y - yo) / 64][(new_x - xo) / 64 / 64] != 'E')
		game->map[game->player->instances->y / 64][game->player->instances->x
			/ 64] = '0';
	if (game->map[new_y / 64][new_x / 64] == 'C')
	{
		game->map[new_y / 64][new_x / 64] = 'P';
		mlx_delete_image(game->mlx, game->player);
		print_element(new_x, new_y, "RockWall_Dark.png", game);
		get_player(game->map, game, game->mlx, game->path);
		game->c--;
		return ;
	}
	if (new_y / 64 == game->exity && new_x / 64 == game->exitx && game->c == 0)
		exit(1);
	game->player->instances->y += yo;
	game->player->instances->x+=xo;
	ft_printf("moves:%d\n", game->movement++);
}
void	move_right(int yo, int xo, game_t *game)
{
	int	new_y;
	int	new_x;
	
	game->path = "right.png";
	new_y = game->player->instances->y + yo;
	new_x = game->player->instances->x + xo;
	if (game->map[(new_y - yo) / 64][(new_x - xo )/ 64] != 'E')
		game->map[(new_y - yo) / 64][(new_x - xo )/ 64] = '0';
	if (game->map[new_y / 64][new_x / 64] == 'C')
	{
		game->map[new_y / 64][new_x / 64] = 'P';
		mlx_delete_image(game->mlx, game->player);
		print_element(new_x, new_y, "RockWall_Dark.png", game);
		get_player(game->map, game, game->mlx, "right.png");
		game->c--;
		return ;
	}
	game->map[new_y / 64][new_x / 64] = 'P';
	mlx_delete_image(game->mlx, game->player);
	get_player(game->map, game, game->mlx, "right.png");
	if (new_y / 64 == game->exity && new_x / 64 == game->exitx && game->c == 0)
		exit(1);
	ft_printf("moves:%d\n", game->movement++);
}
void	move_left(int yo, int xo, game_t *game)
{
	int	new_y;
	int	new_x;

	game->path = "left.png";
	new_y = game->player->instances->y + yo;
	new_x = game->player->instances->x + xo;
	if (game->map[game->player->instances->y / 64][game->player->instances->x
		/ 64] != 'E')
		game->map[game->player->instances->y / 64][game->player->instances->x
			/ 64] = '0';
	if (game->map[new_y / 64][new_x / 64] == 'C')
	{
		game->map[new_y / 64][new_x / 64] = 'P';
		mlx_delete_image(game->mlx, game->player);
		print_element(new_x, new_y, "RockWall_Dark.png", game);
		get_player(game->map, game, game->mlx, "left.png");
		game->c--;
		return ;
	}
	game->map[new_y / 64][new_x / 64] = 'P';
	mlx_delete_image(game->mlx, game->player);
	get_player(game->map, game, game->mlx, "left.png");
	// game->player->instances->x+=xo;
	// game->player->instances->y+=yo;
	if (new_y / 64 == game->exity && new_x / 64 == game->exitx && game->c == 0)
		exit(1);
	ft_printf("moves:%d\n", game->movement++);
}

void	my_keyhook(mlx_key_data_t keydata, void *parm)
{
	game_t	*game;

	game = (game_t *)parm;
	game->yinstance = game->player->instances->y;
	game->xinstance = game->player->instances->x;
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action &&
		game->map[game->yinstance / 64 + 1][game->xinstance / 64] != '1')
		move_player(64, 0, game);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action && game->map[game->yinstance / 64
		- 1][game->xinstance / 64] != '1')
		move_player(-64, 0, game);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action && game->map[game->yinstance
		/ 64][game->xinstance / 64 + 1] != '1')
		move_right(0, 64, game);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action && game->map[game->yinstance
		/ 64][game->xinstance / 64 - 1] != '1')
		move_left(0, -64, game);
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(1);
}

void	leaks(void)
{
	system("leaks -q so_long");
}
int	main(int ac, char **av)
{
	game_t	game;
	int		y;
	int		i;

	(void)ac;
	atexit(leaks);
	if (!av[1])
		ft_error("Error\n", 2);
	game.map = parsing(av[1], &game);
	game.x = ft_strlen(game.map[0]);
	y = 1;
	while (game.map[y])
		y++;
	game.y = y;
	i = 0;
	//
	//  int j = 0;
	// while (game.map[j])
	// {
	//     i = 0;
	//     while (game.map[j][i]){
	//         if (game.map[j][i] == 'C')
	//             game.map[j][i] = '0';
	//         i++;
	//     }
	//     j++;
	// }
	// i = 0;
	// j = 0;
	// while (game.map[j])
	// {
	//     printf("%s\n", game.map[j]);
	//     j++;
	// }
	game.mlx = mlx_init(game.x * 64, game.y * 64, "test", true);
	print_background(game.map, game.mlx, &game); //printing the backgroundf
	game.path = "right.png";
	game.movement = 1;
	mlx_key_hook(game.mlx, &my_keyhook, &game); // moving the player
	mlx_loop(game.mlx);
	i = 0;
	while (game.map[i])
		free(game.map[i++]);
	free(game.map);
}
