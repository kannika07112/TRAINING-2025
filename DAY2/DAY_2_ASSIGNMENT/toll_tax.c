#include <stdio.h>
#include <string.h>

int main() {
    int num;
    char vtype[10];
    int total_tax = 0;

    printf("Enter number of vehicles: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter vehicle type: ");
        scanf("%s", vtype);

        if (strcmp(vtype, "car") == 0) {
            total_tax += 50;
        } else if (strcmp(vtype, "truck") == 0) {
            total_tax += 100;
        } else if (strcmp(vtype, "bike") == 0) {
            total_tax += 20;
        } else if (strcmp(vtype, "bus") == 0) {
            total_tax += 80;
        } else {
            printf("Invalid vehicle type!\n");
            i--;
        }
    }

    printf("Total Toll Tax: rupees %d\n", total_tax);

    return 0;
}