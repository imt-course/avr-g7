#include <stdio.h>

int main (void)
{
	/*
	int x, y;
	printf("Please enter first number: ");
	scanf("%d", &x);
	printf("Please enter second number: ");
	scanf("%d", &y);
	printf("%d + %d = %d", x, y, x+y);
	printf("%d - %d = %d", x, y, x-y);
	printf("%d * %d = %d", x, y, x*y);
	printf("%d / %d = %d", x, y, x/y);
	*/
	
	int x = 25, y = 115;
	printf("%d & %d = %d\n", x, y, x&y);
	printf("%d | %d = %d\n", x, y, x|y);
	printf("%d ^ %d = %d\n", x, y, x^y);
	printf("%d >= %d = %d\n", x, y, x>=y);
	printf("%d <= %d = %d\n", x, y, x<=y);
	printf("%d > %d = %d\n", x, y, x>y);
	printf("%d < %d = %d\n", x, y, x<y);
	printf("%d == %d = %d\n", x, y, x==y);
}
 