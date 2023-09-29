#include <stdio.h>
#include "math.h"

void printMyName (void);
void printNumber (int number);
int getNumber (void);
void swap (void);

int x = 5, y = 3;

int main (void)
{
    /*
    int m,n,res;
    printf("Please enter two numbers: ");
    scanf("%d %d", &m, &n);
    res = add(m,n);
    printf("Result = %d", res);
    */
   /*
    int x,res;
    printf("Please enter number: ");
    scanf("%d", &x);
    res = factorial(x);
    printf("%d! = %d", x, res);
    */

   /*
    int m,n,res;
    printf("Please enter two numbers: ");
    scanf("%d %d", &m, &n);
    res = power(m,n);
    printf("%d power %d = %d", m, n, res);
    */
   /*
   printMyName();
   printNumber(10);
   printf("%d", getNumber());
   */
  /*
  printf("Before: x = %d, y = %d\n", x, y);
  swap();
  printf("After: x = %d, y = %d\n", x, y);
  */

    int n;
    printf("Please enter number: ");
    scanf("%d", &n);
    printf("Fib = %d\n", fib(n));
    printf("Fib Recursion = %d\n", fib_recursion(n));

}

void swap (void)
{
    int temp;
    printf("[In Function] Before: x = %d, y = %d\n", x, y);
    temp = x;
    x = y;
    y = temp;
    printf("[In Function] After: x = %d, y = %d\n", x, y);
}

void printMyName (void)
{
    printf("Ahmed Hassan\n");
}

void printNumber (int number)
{
    printf("%d\n", number);
}

int getNumber (void)
{
    return 5;
}