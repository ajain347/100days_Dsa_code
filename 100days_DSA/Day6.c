#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);   
    }

    int pos =1;

    for (int i=0;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            arr[pos]=arr[i];
            pos++;
        }
    }

    for (int i = 0; i < pos; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}