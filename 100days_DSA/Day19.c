#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() 
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int minSum = INT_MAX;
    int first = 0, second = 0;

    for(int i = 0; i < n; i++) 
    {
        for(int j = i + 1; j < n; j++) 
        {

            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(minSum)) 
            {
                minSum = sum;
                first = arr[i];
                second = arr[j];
            }
        }
    }

    printf("%d %d\n", first, second);

    return 0;
}
