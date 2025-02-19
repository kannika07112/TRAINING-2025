#include<stdio.h>

int main()
{
    int sal, N;
    int lowcount = 0, midcount = 0, higcount = 0;
    printf("Enter number of employees: ");
    scanf("%d", &N);
    printf("Enter Salaries: ");
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &sal);
        if(sal < 30000)
        {
            lowcount++;
        }
        else if(sal >= 30000 && sal <= 70000)
        {
            midcount++;
        }
        else if(sal > 70000)
        {
            higcount++;
        }
    }
    printf("Low income: %d\n", lowcount);
    printf("Middle income: %d\n", midcount);
    printf("High income: %d\n", higcount);

    return 0;
}
