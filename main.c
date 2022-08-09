#include <stdio.h>
#include <stdlib.h>

//#define NB 3

int ft_push_swap(int i)
{
    if (!i)
        return (0);
    return (i);
}

int main(int argc, char **argv)
{
    int i[argc];
    int j;

    j = -1;
    while (++j < argc - 1)
        i[j] = atoi(argv[j + 1]);
    j = 0;
    if (argc <= 4)

    while (i[j] && j < argc - 1)
    {
        if (j == argc - 2)
            printf("PS:%d", ft_push_swap(i[j]));
        else
            printf("PS:%d\n", ft_push_swap(i[j]));
        j++;
    }
    return 0;
}
