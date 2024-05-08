#include "so_long.h"

void    parsing(char *av)
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
    //

}

int main(int ac, char **av)
{
    (void)ac;
    if (!av[1])
        write (2, "nofile", 7 );
    parsing(av[1]);

    // void *mlx_ptr;
    // void *win_ptr;

    // mlx_ptr = mlx_init(1200, 600, "test", true);
    // if (!mlx_ptr)
    //     return -1;

    // win_ptr = mlx_new_image(mlx_ptr, 1200, 600);
    // if (!win_ptr)
    //     return -1;
    // mlx_image_t    *img = mlx_new_image(mlx_ptr,1200, 600);
    // memset(img->pixels, 200, img->height * img->width * sizeof(int32_t));
    // mlx_image_to_window(mlx_ptr, img, 0, 0);
    
    
    

    // mlx_loop(mlx_ptr);



}