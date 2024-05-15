#include "so_long.h"
int count_lines(char **buffer)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (buffer[j])
    {
        i = 0;
        while (buffer[j][i])
            i++;
        j++;
    }
    return (j);
}

char    **copy_map(char **buffer)
{
    // int len = ft_strlen(buffer[0]);
    // (void)len;//
    int i;
    int j = count_lines(buffer);

    i = 0;

    printf(">>j:%d\n",j);
    char **map = malloc(sizeof(char **) * j + 1);

    while (buffer[i])
    {
        map[i] = ft_strdup(buffer[i]);
        i++;
    }
    map[i] = NULL;
    int x = 0;
    while (map[x])
    {
        printf(">>%s\n", map[x]);
        x++;
    }
    ///

    return (map);

}
void    free_map(char **map)
{
    int x = 0;
    while (map[x])
    {
        free(map[x]);
        x++;
    }
    free(map);
    printf("haha\n\n");

}
