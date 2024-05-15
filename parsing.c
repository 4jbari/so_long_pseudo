#include "so_long.h"
int flag = 0;
void path_find(game_t *game, char **map, int x, int y,int ys)
{
    if (map[y][x] == '1' || map[y][x]  == '2' || x < 0 || x > (int)(ft_strlen(map[1])) || y < 0 || y > ys)
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
    // int x1 = 0;
    // while (map[x1])
    // {
    //     printf("buffer :%s\n", map[x1]);
    //     x1++;
    // }
    // printf("daaam:\n\n\n");
    // sleep(1);

    path_find(game, map, x - 1, y, ys);
    path_find(game, map, x, y + 1, ys);
    path_find(game, map, x + 1, y, ys);
    path_find(game, map, x, y - 1, ys);
}  

int    check_path(game_t *game, char **map)
{
    (void)game;//
    int ys;
    int xs;
    int x;
    int y;

    ys = 0;
    xs = 0;
    while (map[ys])
    {
        xs = 0;
        while (map[ys][xs])
        {
            if (map[ys][xs]== 'P')
            {
                x = xs;
                y = ys;
            }
            if (map[ys][xs] != '1' && map[ys][xs] != '0' && map[ys][xs] != 'C' && map[ys][xs] != 'P' && map[ys][xs] != 'E')
            {
                write(2, "incorrect character:\n", 21);
                exit(1);
            }
            xs++;
        }
        ys++;
    }
    // printf("nys:%d\n", ys);
    // printf("nys:%d\n", xs);
    char **map1 = copy_map(map);

    path_find(game, map1, x, y, ys - 1);
    int x1 = 0;
    while (map[x1])
    {
        printf("buffer :%s\n", map[x1]);
        x1++;
    }
    free_map(map1);
    return (0);
}
void    check_elements(char **buffer, game_t *game)
{
    int i;
    int j;
    int Ecount;
    int Ccount;
    int Pcount;

    Ecount = 0;
    Ccount = 0;
    Pcount = 0;
    i = 0;
    j = 1;
    while (buffer[j])
    {
        i = 0;
        while (buffer[j][i])
        {
            if (buffer[j][i] == 'E')
                Ecount++;
            else if(buffer[j][i] == 'C')
                Ccount++;
            else if(buffer[j][i] == 'P')
                Pcount++;
            i++;
        }
        j++;
    }
    printf("Ecount:%d Ccount:%d Pcount:%d\n", Ecount, Ccount, Pcount);
    game->c = Ccount;
    if (Ecount < 1 || Ecount > 1 || Pcount < 1 || Pcount > 1 ||Ccount < 1)
    {
        write(2, "must at least one: E,C,P and at most 1 :E ,P\n", 45);
        exit(1);
    }
    

}

void    check_size(char **map)
{
    size_t j;
    size_t i;
    i = 0;
    j = 0;
    while (map[j])
    {
        if ( map[j + 1] && (ft_strlen(map[j]) != ft_strlen(map[j + 1])  ))
        {

            write(2, "invalidMap:its not equal lines\n", 31);
            exit(1);
        }
        if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
        {
            write(2, "invalidMap1:lines not starting and ending with 1\n", 49);
            exit(1);
        }
        j++;

    }
    if (ft_strlen(map[0]) == j)
    {
        write(2, "must be rectangular\n", 21);
        exit (1);
    }
    size_t y = 0;
    j--;                                                    // withdrawling from the null 
        // printf("y:>>%zu\n", y);
    while (map[0][y] && map[0][y] == '1' && map[j][y] == '1')
        y++;
    if (y != ft_strlen(map[0]))
        write (2, "the firstline and the last must be borders\n", 43);
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
    i = 0;
    while (av[i] && av[i] != '.')
        i++;
    if (av[i] == '.')
    {
        if (!ft_strncmp(&av[i], ".ber", ft_strlen(&av[i])))
            return (1);
        else
            return (0);
    }
    return (0);
}


char    **parsing(char *av, game_t *game)
{
    char **buffer;

    buffer = NULL;


    if (!check_format(av))
    {
        write(2, "Error\nWrongFormat\n", 19);
        exit (1);

    }
    printf("CorrectFormat\n");
    int fd = open(av, O_RDONLY);
    if (fd == -1)
        write(2, "notExisting\n", 12);
    printf(">>%d\n", fd);
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