#include <stdio.h>
#include "algorithms.h"

int main (void)
{
    /*int i;
    int arr[10];
    printf("Please enter 10 numbers: ");
    for (i=0; i<10; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("You entered: ");
    for (i=0; i<10; i++)
    {
        printf("%d ", arr[i]);
    }*/

    /*int i, sum=0, arr[10];
    float avg;
    printf("Please enter 10 numbers: ");
    for (i=0; i<10; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = (float) sum / 10;
    printf("Sum = %d\n", sum);
    printf("Avg = %f\n", avg);*/

    /*int i,j,n;
    printf("Please enter height: ");
    scanf("%d", &n);
    for (j=1; j<=n; j++)
    {
        for (i=0; i<(n-j); i++)
        {
            printf(" ");
        }
        for (i=0; i<(2*j-1); i++)
        {
            printf("*");
        }
        for (i=0; i<(n-j); i++)
        {
            printf(" ");
        }
        printf("\n");
    }*/

    
    /*int number, index;
    int arr[10] = {1,10,15,3,4,7,9,11,25,0};
    printf("Please enter number to search: ");
    scanf("%d", &number);
    index = LinearSearch(arr, 10, number);
    if (index == 10)
    {
        printf("Number not found");
    }
    else 
    {
        printf("Number exists at index %d", index);
    }*/

    /*int arr[10] = {1,10,15,3,4,7,9,11,25,0};
    int i;
    printf("Array Before Sort: ");
    for (i=0; i<10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    BubbleSort(arr, 10);
    printf("Array After Sort: ");
    for (i=0; i<10; i++)
    {
        printf("%d ", arr[i]);
    }*/

    /*int number, index, i;
    int arr[10] = {1,10,15,3,4,7,9,11,25,0};
    BubbleSort(arr, 10);
    printf("Array After Sort: ");
    for (i=0; i<10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nPlease enter number to search: ");
    scanf("%d", &number);
    index = BinarySearch(arr, 10, number);
    if (index == 10)
    {
        printf("Number not found");
    }
    else 
    {
        printf("Number exists at index %d", index);
    }*/

    char str[] = "Ahmed Hassan";
    printf("%s", str);

}

