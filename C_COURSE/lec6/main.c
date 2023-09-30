#include <stdio.h>

void swap (int* x, int* y);

int main (void)
{
    /*int x = 5;
    int y = 10;
    int* ptr = &x;
    *ptr = 7;
    printf("ptr = %p\n", ptr);
    printf("*ptr = %d\n", *ptr);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    ptr = &y;
    *ptr = 3;
    printf("ptr = %p\n", ptr);
    printf("*ptr = %d\n", *ptr);
    printf("x = %d\n", x);
    printf("y = %d\n", y);*/

    /*int x = 5, y = 10;
    printf("Before: x = %d\n", x);
    printf("Before: y = %d\n", y);
    swap(&x, &y);
    printf("After: x = %d\n", x);
    printf("After: y = %d\n", y);*/

    /*int x = 0xAABBCCDD;
    char y;
    int* ptr1 = &x;
    char* ptr2 = &x;
    *ptr2 = 0xBB;
    printf("%x\n",x);
    printf("%x\n",*ptr1);
    printf("%x\n",*ptr2);*/

    /*int x,y;
    int arr[10];
    int* ptr1 = &x;
    int* ptr2 = &y;
    int m = ptr1 - ptr2;
    printf("ptr1 = %d\n", ptr1);
    printf("ptr2 = %d\n", ptr2);
    printf("ptr1 - ptr2 = %d\n", &arr[0] - &arr[9]);*/

    /*int x;
    int*ptr = &x;
    scanf("%d", ptr);
    printf("%d", x);*/

    /*int arr[10] = {0xAABBCCDD,0x11223344,3,4,5,6,7,8,9,10};
    char* ptr = arr;
    printf("ptr = %d\n", ptr);
    printf("arr = %d\n", arr);
    printf("*arr = %d\n", *arr);
    printf("*(arr+3) = %d\n", *(arr+3));
    printf("arr[0] = %d\n", arr[0]);
    printf("ptr[1] = %x\n", ptr[4]);*/
    
	/*int arr[10] = {0,5,7,9,15,20,6,7,8,9};
	int *ptr;
	ptr = arr; //Assume 1st element at 0x1000
	printf("%d \n", *(ptr++)); // 0
	printf("%d \n", *ptr); // 5
	printf("%p \n", arr); // 0x1000
	printf("%d \n", *arr + 2); // 2
	printf("%d \n", *(arr + 2)); // 7
	printf("%d \n", arr[0]); // 0
	printf("%d \n", &arr[0]); // 0x1000
	printf("%d \n", 0[arr]); //  0
	printf("%d \n", arr++); // Error
	printf("%p \n", ptr); // 0x1004
	printf("%d \n", *ptr); // 5
	printf("%d \n", ptr[0]); // 5
	printf("%d \n", &ptr[0]); // 0x1004
	printf("%d \n", 0[ptr]); // 5 */



}

void swap (int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}