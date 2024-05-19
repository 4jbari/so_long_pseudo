#include "so_long.h"
void ft_error(char *s, int fd)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
    exit(1);
}
void path_find(game_t *game, char **map, int x, int y)
{
    if (map[y][x] == '1' || x < 0 || x > (int)(ft_strlen(map[1])) \
    || y < 0 || y > game->lines)
    {
        // printf("fail >> return\n\n");
        return;
    }        
    
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
void    find_palyer(game_t *game, char **map)
{
    int ys;
    int xs;

    ys = 0;
    xs = 0;
    while (map[ys])
    {
        xs = 0;
        while (map[ys][xs])
        {
            if (map[ys][xs]== 'P')
            {
                game->x = xs;
                game->y = ys;
            }
            if (map[ys][xs] != '1' && map[ys][xs] != '0' && map[ys][xs] != 'C'\
            && map[ys][xs] != 'P' && map[ys][xs] != 'E')
                ft_error("incorrect character:1\n", 2);
            xs++;
        }
        ys++;
    }
    game->lines = ys;
}
int    check_path(game_t *game, char **map)
{
    char **map1;
    find_palyer(game, map);
    map1 = copy_map(map);
    game->coin = 0;
    game->exit = 0;
    path_find(game, map1, game->x, game->y);
    printf("coins:%d\nexits:%d\nc:%d\n", game->coin, game->exit, game->c);
    if (game->coin != game->c || game->exit != 1)
        ft_error("Error\nthere is no path to E or C\n", 2);
    free_map(map1);
    return (0);
}
void    check_elements(char **buffer, game_t *game)
{
    int Ecount;
    int Pcount;

    Ecount = 0;
    Pcount = 0;
    game->c = 0;
    game->x = 0;
    game->y = 1;
    while (buffer[game->y])
    {
        game->x = 0;
        while (buffer[game->y][game->x])
        {
            if (buffer[game->y][game->x] == 'E')
            {
                Ecount++;
                game->exitx = game->x;
                game->exity = game->y;
            }
            else if(buffer[game->y][game->x] == 'C')
                game->c++;
            else if(buffer[game->y][game->x] == 'P')
                Pcount++;
            game->x++;
        }
        game->y++;
    }
    printf("Ecount:%d Ccount:%d Pcount:%d\n", Ecount, game->c, Pcount);
    if (Ecount < 1 || Ecount > 1 || Pcount < 1 || Pcount > 1 ||game->c < 1)
        ft_error("Error\nmust at least one: E,C,P and at most 1 :E ,P\n", 2);
}

void    check_size(char **map)
{
    size_t j;
    size_t i;
    i = 0;
    j = 0;
    while (map[j])
    {
        if ( map[j + 1] && (ft_strlen(map[j]) != ft_strlen(map[j + 1])))
            ft_error("Error\ninvalidMap:not rectangular / its not equal lines\n", 2);
        if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
            ft_error("Error\ninvalidMap1:lines not starting and ending with 1\n", 2);
        j++;
    }
    size_t y = 0;
    j--;                                                    // withdrawling from the null 
    while (map[0][y] && map[0][y] == '1' && map[j][y] == '1')
        y++;
    if (y != ft_strlen(map[0]))
        ft_error("Error\nthe firstline and the last must be borders\n", 2);
}

void    ft_read1(int fd, char ***buffer)
{
    char *line = NULL;
    char *jn;
    jn = NULL;

    line = get_next_line(fd);
    jn = ft_join(jn, line);
    //free(line);
    //line = NULL;
    // printf(">>:%s", line);

    while (line)
    {   
        free(line);
        line = get_next_line(fd);
        jn = ft_join(jn, line);
    }
    free(line);
    *buffer = ft_split(jn,'\n');
    free(jn);
}
int check_format(char *av)
{
    int i;
    int j;
    char *ber;

    j = 0;
    i = 0;
    ber = ".ber";
    while (av[i])
        i++;
    if (av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b' && av[i - 4] == '.')
    {

        printf("valid\n");
        return (1);

        // while (av[i] == ber[j])
        // {
        //     i++;
        //     j++;
        // }
        // if (ber[j] == '\0')
        //     return (1);
    }
    return (0);
}


char    **parsing(char *av, game_t *game)
{
    char **buffer;

    buffer = NULL;
    if (!check_format(av))
        ft_error("Error\nWrongFormat\n", 2);
    printf("CorrectFormat\n");
    int fd = open(av, O_RDONLY);
    if (fd == -1)
        write(2, "notExisting\n", 12);
    printf("fd>>%d\n", fd);
    ft_read1(fd, &buffer);
    // int x  = 0 ;
    // while (buffer[x])
    // {
    //     printf("buffer :%s\n", buffer[x]);
    //     x++;
    // }
    check_size(buffer);
    check_elements(buffer, game);
    check_path(game, buffer);
    // if (game->exit != 1 ||  != 0)
    //     write(2, "Error:nopath\n", 13);
    // x  = 0 ;
    // while (buffer[x])
    // {
    //     printf("buffer :%s\n", buffer[x]);
    //     x++;
    // }
    // printf("chekpath%d\n", check_path(buffer));
    return (buffer);

}
