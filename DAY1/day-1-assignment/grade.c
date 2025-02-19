#include <stdio.h>

int main()
{
    int N, marks;

    printf("Enter number of students: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks);

        if (marks >= 90 && marks <= 100)
        {
            printf("Student %d: Grade A\n", i + 1);
        }
        else if (marks >= 80 && marks <= 89)
        {
            printf("Student %d: Grade B\n", i + 1);
        }
        else if (marks >= 70 && marks <= 79)
        {
            printf("Student %d: Grade C\n", i + 1);
        }
        else if (marks >= 60 && marks <= 69)
        {
            printf("Student %d: Grade D\n", i + 1);
        }
        else
        {
            printf("Student %d: Grade F\n", i + 1);
        }
    }

    return 0;
}
