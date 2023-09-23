#include <stdio.h>

int main(void)
{
    /*int x = 0;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;
    printf("%d ", x);
    x++;*/

    /*
    int x = 0;
    while (x < 10)
    {
        printf("%d\n", x);
        x++;
    }
    printf("Exit Loop");
    */

    /*int result;
    printf("Please enter 3x4 = ");
    scanf("%d", &result);
    while (result != 12)
    {
     printf("Incorrect, try again: ");
     scanf("%d", &result);
    }
    printf("Correct Answer");
    */

    /*
      int n, counter = 1;
      printf("Please enter a number: ");
      scanf("%d", &n);
      while (counter <= n)
      {
        printf("%d * %d = %d\n", n, counter, n*counter);
        counter++;
      }
      */

    /* int n, counter = 1;
    printf("Please enter a number: ");
    scanf("%d", &n);
    do
    {
      printf("%d * %d = %d\n", n, counter, n*counter);
      counter++;
    } while (counter <= n);*/

    /*int n, result = 1;
    printf("Please enter a number: ");
    scanf("%d", &n);
    while (n > 0)
    {
        result *= n;
        n--;
    }
    printf("Factorial = %d", result);*/
    /*
    int result;
    int trials = 0;
    printf("Please enter 3x4 = ");
    scanf("%d", &result);
    while (result != 12)
    {
        trials++;
        if (trials > 3)
        {
            break;
        }
        printf("Incorrect, try again: ");
        scanf("%d", &result);
    }
    if (trials <= 3)
    {
        printf("Correct Answer");
    }
    else
    {
        printf("Maximum trials reached");
    }
    */
    /*
     int x;
     while (1)
     {
         scanf("%d", &x);
         if (x == 5) {
             continue;;
         }
         printf("You entered %d\n", x);
     }
     */

    /*int x;
    for (x=0; x<10; x++)
    {
        printf("%d\n", x);
    }*/
    
    /*int i, x, n, sum = 0;
    float avg;
    printf("Please enter numbers count: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &x);
        sum += x;
    }
    avg = (float)sum / n;
    printf("Sum = %d\n", sum);
    printf("Avg = %f\n", avg);*/

    /*
    // Number of Decimal Digits
    int x;
    int counter = 0;
    printf("Please enter a number: ");
    scanf("%d", &x);
    do
    {
        x /= 10;
        counter++;
    } while (x > 0);
    printf("Number of digits = %d\n", counter);
    */

    /*
    // Number of Binary Digits
    int x;
    int counter = 0;
    printf("Please enter a number: ");
    scanf("%d", &x);
    do
    {
        x /= 2; // x >>= 1;
        counter++;
    } while (x > 0);
    printf("Number of digits = %d\n", counter);
    */
    
    /*
    // Number of Hex Digits
    int x;
    int counter = 0;
    printf("Please enter a number: ");
    scanf("%d", &x);
    do
    {
        x /= 16; // x >>= 4;
        counter++;
    } while (x > 0);
    printf("Number of digits = %d\n", counter);
    */
   /* comment*/ 
   int i;
   for (i=0; i<10; i++)
    printf("%d\n", i);
    
}