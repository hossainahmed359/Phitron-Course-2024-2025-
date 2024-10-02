#include <stdio.h>
int main()
{
    printf("=== Semester One | Week One | Module Three | Loop ===\n");

    // for (int i = 0  -> INITIALIZATION STATEMENT; i < count -> CONDITION; i++ -> UPDATE)
    // {
    //     /* code */
    // }

    // while

    // do while
    // int i = 10;

    // do
    // {
    //     printf("Value of if %d\n", i);
    //     i++;
    // } while (i < 10);

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         for (int k = 0; k < 10; k++)
    //         {
    //             printf("%d, %d, %d\n", i, j, k);
    //         }
    //     }
    // }

    // for (char i = 'a'; i <= 'z'; i++)
    // {
    //     printf("%c : %d\n", i, i);
    // }
    // for (char i = 'A'; i <= 'Z'; i++)
    // {
    //     printf("%c : %d\n", i, i);
    // }

    int i = -5;
    while (i < 3)
    {
        printf("hello ");
        i += 2;
    }

    return 0;
}
