#include <stdio.h>

int main (void)
{
	/*
	int degree;
	printf("Please enter your degree: ");
	scanf("%d", &degree);
	
	if ((degree > 100) || (degree < 0))
	{
		printf("Invalid");
	}
	else if (degree >= 50)
	{
		printf("PASS");
	}
	else if (	degree < 50)
	{
		printf("FAIL");
	}
	*/
	
	/*
	int number;
	printf("Please enter number: ");
	scanf("%d", &number);
	if (number%2 == 0)
	{
		printf("EVEN");
	}
	else
	{
		printf("ODD");
	}
	*/
	
	/*
	int hours;
	int hour_rate = 10;
	int salary;
	printf("Please enter hours: ");
	scanf("%d", &hours);
	if (hours == 40)
	{
		salary = 40*hour_rate;
	}
	else if (hours < 40)
	{
		salary = hours*hour_rate*0.9;
	}
	else if ((hours > 40) && (hours <= 50))
	{
		salary = 40*hour_rate + (hours-40)*hour_rate*2;
	}
	else if (hours > 50)
	{
		salary = 40*hour_rate + 10*hour_rate*2 + (hours-50)*hour_rate*1.5;
	}
	printf("Salary is %d", salary);
	*/
	
	int day;
	printf("Please enter day number: ");
	scanf("%d", &day);
	switch(day)
	{
		case 0:
			printf("Saturday\n");
			break;
		case 1:
			printf("Sunday\n");
			break;
		case 2:
			printf("Monday\n");
			break;
		case 3:
			printf("Tuesday\n");
			break;
		case 4:
			printf("Wednesday\n");
			break;
		case 5:
			printf("Thursday\n");
			break;
		case 6:
			printf("Friday\n");
			break;
		default:
			printf("Invalid Number\n");
			break;
	}
	
}
