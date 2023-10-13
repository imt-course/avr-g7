#include <stdio.h>
#include "StdTypes.h"

#define ENABLE 1
#define PRINT printf
#define PRINT_NUMBER(X) printf("%d\n", X)
#define ADD(X,Y) (X+Y)
#define PRINT_MY_NAME() do {\
printf("Ahmed\n");\
printf("Hassan");\
} while(0)

    typedef enum {
        ON,
        OFF
    } State;

#define PTR_T int*
typedef int* ptr_t;

#define SET_BIT(REG,BIT)    REG|=(1<<BIT)
#define CLR_BIT(REG,BIT)    REG&=~(1<<BIT)
#define TOG_BIT(REG,BIT)    REG^=(1<<BIT)
#define GET_BIT(REG,BIT)    ((REG>>BIT)&1)

int main (void)
{
    int x = 137;
    SET_BIT(x, 2);
    printf("bit 3 = %d, bit 6 = %d", GET_BIT(137,3),GET_BIT(137,6));
    /*ptr_t x,y,z;
    PTR_T a,b,c;
    printf("Size of x = %d\n", sizeof(x));
    printf("Size of y = %d\n", sizeof(y));
    printf("Size of z = %d\n", sizeof(z));
    printf("Size of a = %d\n", sizeof(a));
    printf("Size of b = %d\n", sizeof(b));
    printf("Size of c = %d\n", sizeof(c));*/
    /*
#define PI 3.14
    f32 x = PI;
    State m = OFF;
    #ifndef ENABLE
    printf("Enabled");
    #endif
    PRINT_NUMBER(ADD(3,5));
    PRINT_NUMBER(10);
    if (1)
        PRINT_MY_NAME();
    else
        printf("INVALID");*/
}


inline void func (void)
{
    State m = OFF;
    printf("%d", 2);
}
