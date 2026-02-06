#include <stdio.h>

int main()
{
    int n,a;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d",&a);
    int arr2[a];
    for (int i = 0; i < a; i++) 
    {
        scanf("%d", &arr2[i]);
    }

    int i=0,j=0;
    while(i<n && j<a)
    {
        if(arr[i]<arr2[j])
        {
            printf("%d ",arr[i]);
            i++;
        }
        else
        {
            printf("%d ",arr2[j]);
            j++;
        }
    }

    while(i<n)
    {
        printf("%d ",arr[i]);
        i++;
    }
    while(j<a)
    {
        printf("%d ",arr2[j]);
        j++;
    }
    return 0;
}