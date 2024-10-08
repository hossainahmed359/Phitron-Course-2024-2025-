#include <stdio.h>
#include <stdbool.h>
int main()
{
    // Patterns
    // 1
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }

        printf("\n");
    }

    printf("\n");

    // 2
    for (int i = 5; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            printf("%d ", j);
        }

        printf("\n");
    }

    printf("\n");

    // 3
    char ch = 'A';
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c ", ch);
        }

        ch++;
        printf("\n");
    }

    printf("\n");

    // 4

    for (int i = 1; i <= 10; i++)
    {

        for (int j = 10; j >= i; j--)
        {
            printf(" ");
        }
        

        for (int k = 1; k <= i; k++)
        {
            printf("* ");
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}
