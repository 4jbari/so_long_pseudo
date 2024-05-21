#include "so_long.h"

int compare(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s1[i] && s2[j] && s1[i] == s2[j])
    {
        i++;
        j++;
    }
    printf("s1:%s\ns2:%s\n", s1, s2);
    return (s1 - s2);
}