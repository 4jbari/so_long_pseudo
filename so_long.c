#include "so_long.h"
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
void    ft_read1(int fd, char ***buffer)
{
    char *line = NULL;

    int count;
    count = 0;
    char *jn;
    jn = NULL;
    
    line = get_next_line(fd);
    jn = ft_join(jn, line);
    

    while (line)
    {
        count++;
        line = get_next_line(fd);
        jn = ft_join(jn, line);
    }
    *buffer = ft_split(jn,'\n');


}
void    check_size(char **map)
{
    size_t j;
    size_t i;
    i = 0;
    j = 0;
    while (map[j] && map[j + 1])
    {

        printf("hah%c\n", map[j][ft_strlen(map[j]) - 1]);
        if (ft_strlen(map[j]) != ft_strlen(map[j + 1]) && map[j][0] != '1' && map[j][ft_strlen(map[j]) - 1 ] != '1')
        {

            write(2, "invalidMap\n", 11);
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
    j--;
        printf("y:>>%zu\n", y);
    while (map[0][y] && map[0][y] == '1' && map[j][y] == '1')
        y++;
    if (y != ft_strlen(map[0]))
    {
        write (2, "the firstline and the last must be borders\n", 43);
    }
}
void    parsing(char *av)
{
    char **buffer;
    buffer = NULL;

    if (!check_format(av))
    {
        write(2, "Error:WrongFormat\n", 18);
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
    //

}

int main(int ac, char **av)
{
    (void)ac;
    if (!av[1])
        write (2, "nofile", 7 );
    parsing(av[1]);


}