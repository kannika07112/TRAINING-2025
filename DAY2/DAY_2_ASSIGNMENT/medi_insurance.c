#include <stdio.h>
#include <string.h>

void medical_insurance(int age, int sal, char preq[5])
{
    if ((age >= 18 && age <= 60) && (strcmp(preq, "no") == 0) && (sal >= 25000))
    {
        printf("Eligible for Medical Insurance\n");
    }
    else
    {
        printf("Not eligible for Medical Insurance\n");
    }
}

int main()
{
    int age, sal;
    char preq[5];

    printf("Enter the age: ");
    scanf("%d", &age);

    printf("Any Pre-existing Condition? (yes/no): ");
    scanf("%s", preq);

    printf("Enter your monthly salary: ");
    scanf("%d", &sal);

    medical_insurance(age, sal, preq); // Corrected function call

    return 0;
}