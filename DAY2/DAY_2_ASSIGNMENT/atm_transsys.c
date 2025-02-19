#include <stdio.h>
#include<conio.h>
// Function without pointer (wrong approach)
void atm_transaction(int choice, int balance) {
    int amount;
    
    switch (choice) {
        case 1: // Withdraw Money
            printf("Enter Amount to Withdraw: ");
            scanf("%d", &amount);
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                printf("Transaction Successful. Remaining Balance: rupees %d\n", balance);
            } else {
                printf("Insufficient balance or invalid amount!\n");
            }
            break;

        case 2: // Deposit Money
            printf("Enter Amount to Deposit: ");
            scanf("%d", &amount);
            if (amount > 0) {
                balance += amount; // This change only affects the local copy
                printf("Deposit Successful. Updated Balance: rupees %d\n", balance);
            } else {
                printf("Invalid deposit amount!\n");
            }
            break;

        case 3: // Check Balance
            printf("Current Balance: rupees %d\n", balance);
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
    }
}

int main() {
    int balance = 10000; // Initial balance
    int choice;

    printf("Enter your choice:\n");
    printf("1. Withdraw\n2. Deposit\n3. Check Balance\n");
    printf("Choice: ");
    scanf("%d", &choice);

    atm_transaction(choice, balance);

    return 0;
}
