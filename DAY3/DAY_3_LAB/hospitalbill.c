#include <stdio.h>
#include<string.h>
float amtg, amts, amtp,amtgd, amtsd, amtpd;
void calculateBill(char wardtype[], int days)
{
    if (strcmp(wardtype, "G") == 0)
    {
        amtg = 1000 * days;
        printf("Bill:%.2f\n",amtg);    
        if (days > 7)
        {
            amtgd = amtg * 0.95f;
            printf("Discounted amount= %.2f\n",amtgd);
             printf("Total bill after discount is:%.2f\n",amtg-amtgd);
        }
       
    }
    if (strcmp(wardtype, "S") == 0)
    {
        amts = 2000 * days;
        printf("Bill:%.2f\n",amts);
        if (days > 7)
        {
            amtsd = amts * 0.95f;
            printf("Discounted amount= %.2f\n",amtsd);
            printf("Total bill after discount is:%.2f\n",amts-amtsd);
        }
        
    }
    if (strcmp(wardtype, "P") == 0)
    {
        amtp = 5000 * days;
        printf("Bill:%.2f\n",amtp);

        if (days > 7)
        {
            amtpd = amtp * 0.95f;
            printf("Discounted amount= %.2f\n",amtpd);
            printf("Total bill after discount is:%.2f\n",amtp-amtpd);
        }
        
    }
}

int main()
{
    char name[100];
    char wardtype[10];
    int days;
    float amtg, amts, amtp;
    printf("Enter patient name: ");
    scanf("%s", name);

    printf("Enter Ward type (G/S/P): ");
    scanf("%s", wardtype);

    printf("Enter number of days: ");
    scanf("%d", &days);
    calculateBill(wardtype,days);

    return 0;
}