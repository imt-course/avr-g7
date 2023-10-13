#include <stdio.h>
#include "StdTypes.h"

struct student
{
    u32 id;
    u32 grade;
    f32 math;
    f32 english;
    f32 average;
};

typedef struct
{
    u32 id;
    u32 salary;
    u32 deduction;
    u32 net;
} Employee;

typedef struct
{
    f32 x;
    f32 y;
} Complex;

//#pragma pack(1)
typedef struct 
{
    u8 a;
    u32 b;
    u8 e;
    u32 d;
    u16 c;
    u32 f;
} MyStruct;

typedef struct 
{
    u8 x: 2;
    u8 y: 3;
    u8 z: 1;
} BitField;

typedef union
{
    u8 Byte;
    struct
    {
        u8 B0:1;
        u8 B1:1;
        u8 B2:1;
        u8 B3:1;
        u8 B4:1;
        u8 B5:1;
        u8 B6:1;
        u8 B7:1;
    }Bit;
} Register;

typedef enum
{
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
} Day;

typedef enum 
{
    JAN,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
} Month;

Complex addComplex (Complex n1, Complex n2);
Complex addComplexRef (const Complex* n1, const Complex* n2);

int main (void)
{
    Day day;
    day = TUESDAY;
    printf("%d\n", day);
    if (day == TUESDAY)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    /*Register x;
    x.Byte = 0;
    printf("%d\n", x.Byte);
    x.Bit.B2 = 1;
    printf("%d\n", x.Byte);
    x.Bit.B5 = 1;
    printf("%d\n", x.Byte);*/
    /*BitField a;
    a.x = 4;
    a.y = 5;
    a.z = 1;
    printf("size = %d\n", sizeof(a));
    printf("x = %d\n", a.x);
    printf("y = %d\n", a.y);
    printf("z = %d\n", a.z);*/
    /*MyStruct x;
    printf("%p -- %p", &x.a, &x.b);*/

    /*struct student ahmed;
    struct student ali = {10, 3, 70.2, 25.3};
    struct student mazen =
    {
        .id = 7,
        .grade = 2,
        .english = 80.6,
        .math = 40.7,
        .average = (mazen.math + mazen.english) / 2
    };
    ahmed.id = 5;
    ahmed.grade = 4;
    ahmed.math = 50.60;
    ahmed.english = 60.9;
    ahmed.average = (ahmed.math + ahmed.english) / 2;
    ali.average = (ali.math + ali.english) / 2;
    printf("%f", ali.average);*/

    /*Employee ahmed, ali;
    printf("Please enter Ahmed id: ");
    scanf("%d", &ahmed.id);
    printf("Please enter Ahmed salary: ");
    scanf("%d", &ahmed.salary);
    printf("Please enter Ahmed deduction: ");
    scanf("%d", &ahmed.deduction);
    ahmed.net = ahmed.salary - ahmed.deduction;
    printf("Please enter Ali id: ");
    scanf("%d", &ali.id);
    printf("Please enter Ali salary: ");
    scanf("%d", &ali.salary);
    printf("Please enter Ali deduction: ");
    scanf("%d", &ali.deduction);
    ali.net = ali.salary - ali.deduction;

    printf("Total Pay = %d", ahmed.net + ali.net);*/

    /*Employee employees[100];
    u8 i,n;
    u32 totalPay = 0;
    printf("Please enter employees count: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Please enter employee %d salary: ", i+1);
        scanf("%d", &employees[i].salary);
        printf("Please enter employee %d deduction: ", i+1);
        scanf("%d", &employees[i].deduction);
        employees[i].net = employees[i].salary - employees[i].deduction;
        totalPay += employees[i].net;
    }
    printf("Total Pay = %d", totalPay);*/

    /*Complex n1,n2,result;
    printf("Pleas enter first number: ");
    scanf("%f %f", &n1.x, &n1.y);
    printf("Pleas enter second number: ");
    scanf("%f %f", &n2.x, &n2.y);
    result = addComplex(n1, n2);
    printf("Result = %.2f%+.2fi", result.x, result.y);*/

    /*Complex n1,n2,result;
    printf("Pleas enter first number: ");
    scanf("%f %f", &n1.x, &n1.y);
    printf("Pleas enter second number: ");
    scanf("%f %f", &n2.x, &n2.y);
    result = addComplexRef(&n1, &n2);
    printf("Result = %.2f%+.2fi", result.x, result.y);*/



}


Complex addComplex (Complex n1, Complex n2)
{
    Complex result;
    result.x = n1.x + n2.x;
    result.y = n1.y + n2.y;
    return result;
}

Complex addComplexRef (const Complex* n1, const Complex* n2)
{
    Complex result;
    //result.x = (*n1).x + (*n2).x;
    result.x = n1->x + n2->x;
    //result.y = (*n1).y + (*n2).y;
    result.y = n1->y + n2->y;
    return result;
}