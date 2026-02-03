#include <stdio.h>

int main()
{
    int n, x;
    int arr[100];
    int found = 0;
    int comparisons = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);

    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == x)
        {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    return 0;
}
