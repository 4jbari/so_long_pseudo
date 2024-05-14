#include "so_long.h"

void    print_element(int x, int y, char *path, game_t *game)
{
    mlx_texture_t *texture = mlx_load_png(path);
    mlx_image_t *img = mlx_texture_to_image(game->mlx, texture);
    mlx_image_to_window(game->mlx, img, x, y);

}

void get_player(char **map, game_t *game , void *mlx)
{
    int i;
    int j;
    mlx_texture_t *texture;

    int x = 0;
    int y = 0;
    j = 0;
    i = 0;
    while (map[j])
    {
        i = 0;
        x = 0;
        while (map[j][i])
        {
            if (map[j][i] == 'P')
            {
                texture = mlx_load_png("output-onlinepngtools.png");
                game->player = mlx_texture_to_image(mlx, texture);
                mlx_image_to_window(mlx, game->player, x, y);
            }
            i++;
            x+= 64;
        }
        y += 64;
        j++;
    }
}
void print_background(char **map, void *mlx, game_t *game)
{
    int i;
    int j;
    i = 0;
    j = 0;
    game->y = 0;
    while (map[j])
    {
        game->x = 0;
        i = 0;
        while (map[j][i])
        {
            print_element(game->x, game->y, "stone.png", game);
            game->x+= 64;
            i++;
        }
        j++;
        game->y+= 64;
    }
    game->y = 0;
    j = 0;
    while (map[j])
    {
        game->x = 0;
        i = 0;
        while (map[j][i])
        {

            if (map[j][i] == '1')
                print_element(game->x, game->y, "RockWall_Dark.png", game);
            else if(map[j][i] == 'C')
                print_element(game->x, game->y, "_png_output-onlinepngtools.png", game);
            else if(map[j][i] == 'E')
                print_element(game->x, game->y, "spr_portal_strip8.png", game);
            game->x+= 64;
            i++;
        }
        j++;
        game->y+= 64;
    }
    get_player(map, game, mlx);
}

void    move_player(int yo, int xo, game_t *game)
{
    game->map[game->player->instances->y/64][game->player->instances->x/64] = '0';
    int new_y = game->player->instances->y+yo;
    int new_x = game->player->instances->x+xo;

    printf("game->map[new_y/64][new_x/64]:%c\n",game->map[new_y/64][new_x/64] );
    if(game->map[new_y/64][new_x/64] == 'C')
    {
        game->map[new_y/64][new_x/64] = 'P';
        printf("haha\n\n\n\n");
        mlx_delete_image(game->mlx, game->player);
        print_background(game->map, game->mlx, game);
        return ;

    }
    game->player->instances->y+=yo;
    game->player->instances->x+=xo;


}
void my_keyhook(mlx_key_data_t keydata, void *parm)
{
    game_t *game;

    game = (game_t *)parm;
    //  int   x  = 0 ;
    // while (game->map[x])
    // {
    //     printf("bufferBo:%s\n", game->map[x]);
    //     x++;
    // }
	// printf("game->player->instances->y:%c\n", game->map[game->player->instances->y/64][game->player->instances->x/64]);
    if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S) && keydata.action == MLX_PRESS \
        && game->map[game->player->instances->y/64 + 1][game->player->instances->x/64] != '1')
        move_player(64, 0, game);

	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D )&& keydata.action == MLX_PRESS\
        && game->map[game->player->instances->y/64][game->player->instances->x/64 + 1] != '1')
        move_player(0, 64, game);

	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)&& keydata.action == MLX_PRESS\
        && game->map[game->player->instances->y/64][game->player->instances->x/64-1] != '1')
        move_player(0, -64, game);

    if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W) && keydata.action == MLX_PRESS \
        && game->map[game->player->instances->y/64 -1 ][game->player->instances->x/64] != '1')
        move_player(-64, 0, game);
}

void leaks()
{
    system("leaks -q Game");
}
int main(int ac, char **av)
{
    (void)ac;
    atexit(leaks);


    game_t game;
    if (!av[1])
        write (2, "nofile\n", 8);
    game.map = parsing(av[1], &game);
    game.x = ft_strlen(game.map[0]);
    int y = 1;
    while (game.map[y])
        y++;
    game.y = y;
    int i = 0;
    while (game.map[i])
        free(game.map[i++]);
    
    // game.mlx = mlx_init(game.x * 64,game.y * 64, "test", true);
    

    // print_background(game.map, game.mlx, &game);//




    // mlx_key_hook(game.mlx, &my_keyhook, &game);

    // mlx_loop(game.mlx);
}
