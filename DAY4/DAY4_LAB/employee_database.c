#include <stdio.h>
struct Employee_t
{
    int id;
    char name[255];
    float salary;
    char department[50];
};
typedef struct Employee_t Emp;
void readEmployees(Emp emp[], int n);
void displayEmployees(Emp emp[], int n);
Emp findHighestSalary(Emp emp[], int n);
int main()
{
    int employeeCount;
    printf("Enter number of employees:");
    scanf("%d", &employeeCount);
    Emp employees[1000];
    readEmployees(employees, employeeCount);
    displayEmployees(employees, employeeCount);
    Emp highestSalariedEmployee = findHighestSalary(employees, employeeCount);
    printf("Employee with highest salary: %s, %.2f (%s)\n",
           highestSalariedEmployee.name,
           highestSalariedEmployee.salary,
           highestSalariedEmployee.department);
    return 0;
}

void readEmployees(Emp emp[], int n)
{
    printf("Enter details (ID, Name, Salary, Department):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s%f%s", &emp[i].id, emp[i].name, &emp[i].salary, emp[i].department);
    }
}

void displayEmployees(Emp emp[], int n)
{
    printf("Employees:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %f %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}
Emp findHighestSalary(Emp emp[], int n)
{
    Emp highestSalaried = emp[0];
    for (int i = 1; i <= n; i++)
    {
        if (emp[i].salary > highestSalaried.salary)
        {
            highestSalaried = emp[i];
        }
    }
    return highestSalaried;
}