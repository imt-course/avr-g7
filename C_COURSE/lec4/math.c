

int power (int number, int exp)
{
    int result = 1;
    if ((number == 1) || (number == 0))
    {
        result = number;
    }
    else
    {
        while (exp > 0)
        {
            result *= number;
            exp--;
        }
    }
    return result;
}

int factorial (int number)
{
    int result = 1;
    while (number > 1)
    {
        result *= number;
        number--;
    }
    return result;
}

int factorial_recursion (int number)
{
    if ((number == 0) || (number == 1))
    {
        return 1;
    }
    else 
    {
        return (number*factorial_recursion(number-1));
    }
}

int fib (int number)
{
    int n1 = 0;
    int n2 = 1;
    int result;
    int i = 2;
    if ((number == 0) || (number == 1))
    {
        result = number;
    }
    else
    {
        while (i <= number)
        {
            result = n1 + n2;
            n1 = n2;
            n2 = result;
            i++;
        }
    }
    return result;
}

int fib_recursion (int number)
{
    if ((number == 0) || (number == 1))
    {
        return number;
    }
    else 
    {
        return (fib_recursion(number-1) + fib_recursion(number-2));
    }
}

int add (int x, int y)
{
    int result;
    result = x + y;
    return result;
}
int sub (int x, int y)
{
    int result;
    result = x - y;
    return result;
}
int mul (int x, int y)
{
    int result;
    result = x * y;
    return result;
}
int divide (int x, int y)
{
    int result;
    if (0 != y)
    {
        result = x / y;
    }
    else 
    {
        result = 0;
    }
    return result;
}

int absolute (int number)
{
    if (number < 0)
    {
        number *= -1;
    }
    return number;
}
