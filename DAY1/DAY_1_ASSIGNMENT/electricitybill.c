#include <stdio.h>

int main() {
    int N, units, i;
    float base_amt;

    printf("Enter the number of customers: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Enter units consumed for customer %d: ", i + 1);
        scanf("%d", &units);

        base_amt = 0.0f;

        if (units <= 100) {
            base_amt = units * 2;
        } else if (units <= 200) {
            base_amt = 100 * 2 + (units - 100) * 3;
        } else {
            base_amt = 100 * 2 + 100 * 3 + (units - 200) * 5;
        }

        printf("Total Bill for customer %d: ₹%.2f\n", i + 1, base_amt);
    }

    return 0;
}
