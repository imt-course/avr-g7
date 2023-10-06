#include "StdTypes.h"
#include <stdio.h>

u32 x = 5;


static void func (void)
{
    static u8 x = 0;
    x++;
    printf("%d\n", x);
}
