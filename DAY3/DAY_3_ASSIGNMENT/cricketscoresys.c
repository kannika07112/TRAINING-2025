#include <stdio.h>

int main() {
    int scores[5];
    int i;
    int highest, lowest;
    float sum = 0.0, average;

    // Input scores
    printf("Enter scores of 5 matches: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &scores[i]);
    }

    // Initialize highest and lowest with the first score
    highest = lowest = scores[0];

    // Calculate highest, lowest and sum of scores
    for (i = 0; i < 5; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
        sum += scores[i];
    }

    // Calculate average
    average = sum / 5;

    // Print the results
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.1f\n", average);

    return 0;
}