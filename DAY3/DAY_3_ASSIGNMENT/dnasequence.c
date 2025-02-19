#include <stdio.h>
#include <string.h>

int main() {
    char dna[100], pattern[10];
    int count = 0;
    int dna_length, pattern_length;

    // Input DNA sequence
    printf("Enter DNA Sequence: ");
    scanf("%s", dna);

    // Input pattern to search
    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    dna_length = strlen(dna);
    pattern_length = strlen(pattern);

    for (int i = 0; i <= dna_length - pattern_length; i++) {
        int found = 1;
        for (int j = 0; j < pattern_length; j++) {
            if (dna[i + j] != pattern[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            count++;
        }
    }
    printf("Pattern found %d time(s) in the DNA sequence.\n", count);

    return 0;
}