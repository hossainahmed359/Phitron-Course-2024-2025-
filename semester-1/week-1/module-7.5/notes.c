#include <stdio.h>
#include <limits.h>

int main()
{
    printf("=== Semester One | Week One | Module Seven | Introduction to array  ===");

    int arr[5] = {1, 2, 3, 4, 5};

    printf("%d\n", &arr[0]);

    // Arr Iteration
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d -> %d\n", &arr[i], arr[i]);
    }

    printf("\n");

    // Arr Min Max
    int n;
    scanf("%d", &n);

    int arrTwo[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrTwo[i]);
    }

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arrTwo[i] < min)
        {
            min = arrTwo[i];
        }

        if (arrTwo[i] > max)
        {
            max = arrTwo[i];
        }
    }

    printf("%d %d", min, max);

    return 0;
}
