#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i;
    printf("Tokio\n");
    int r = fork();
    printf("Rio de Janeiro\n");
    if (r == 0)
    {
        printf("Toronto\n");
        int k = fork();
        if (k >= 0)
        {
            printf("Sydney\n");
        }
    }
    else if (r > 0)
    {
        printf("Beijing\n");
        for (i = 0; i < 3; i++)
        {
            if ((r = fork()) == 0)
            {
                printf("Singapur\n");
                exit(EXIT_SUCCESS);
                printf("Dubai\n");
            }
            else if (r > 0)
            {
                printf("Nueva York\n");
            }
        }
    }
    return EXIT_SUCCESS;
}