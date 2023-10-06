#include <stdio.h>
#include "StdTypes.h"

extern u32 x;

void func (void);

int main (void)
{
    /*
    printf("Size of char            = %d\n", sizeof(char         ));
    printf("Size of short int       = %d\n", sizeof(short int    ));
    printf("Size of int             = %d\n", sizeof(int          ));
    printf("Size of long int        = %d\n", sizeof(long int     ));
    printf("Size of long long int   = %d\n", sizeof(long long int));
    printf("Size of float           = %d\n", sizeof(float        ));
    printf("Size of double          = %d\n", sizeof(double       ));
    printf("Size of long double     = %d\n", sizeof(long double  ));
    printf("Size of short           = %d\n", sizeof(short        ));
    printf("Size of long            = %d\n", sizeof(long         ));
    printf("Size of long long       = %d\n", sizeof(long long    ));
    */

   /*printf ("Please enter value: ");
   scanf("%d", &x);
   printf("You entered %d\n", x);
    func();
    func();
    func();
    func();
    func();
    func();
    func();
    func();
    func();
    func();*/

    const u8 x = 10;
    u8 y = 7;
    const u8* const ptr = &x;
    ptr++;
    printf("%d", x);

}

