#include "so_long.h"

char    **parsing(char *av)
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
    int x  = 0 ;
    while (buffer[x])
    {
        printf("buffer :%s\n", buffer[x]);
        x++;
    }
    check_size(buffer);
    check_elements(buffer);
    if (!check_path(buffer))
        write(2, "Error:nopath\n", 13);
    x  = 0 ;
    while (buffer[x])
    {
        printf("buffer :%s\n", buffer[x]);
        x++;
    }
    // printf("chekpath%d\n", check_path(buffer));
    return (buffer);

}

void print_background(char **map, void *mlx)
{
    int i;
    int j;
    int x = 0;
    int y = 0;
    mlx_texture_t *texture;
    
    i = 0;
    j = 0;
    while (map[j])
    {
        x = 0;
        i = 0;
        while (map[j][i])
        {
            if (map[j][i] == '1')
            {
                texture = mlx_load_png("RockWall_Dark.png");
                void *img = mlx_texture_to_image(mlx, texture);
                mlx_image_to_window(mlx, img, x, y);

            }
            x+= 64;
            i++;
        }
        j++;
        y+= 64;

    }

}



int main(int ac, char **av)
{
    (void)ac;
    if (!av[1])
        write (2, "nofile\n", 8);
    char **map = parsing(av[1]);

    int x = ft_strlen(map[0]);
    printf("%d\n", x);
    int y = 1;
    while (map[y])
        y++;

    mlx_t *mlx = mlx_init(x * 64,y * 64, "test", true);

    print_background(map, mlx);
    mlx_loop(mlx);

}