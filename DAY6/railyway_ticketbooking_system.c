// 3. Railway Ticket Booking – Seat Availability Search`  
// `Scenario:`  
// A `railway reservation system` allows passengers 
// to check seat availability. The system should:  
// - Sort `seat numbers` (ascending order)  
// - Search `for a specific seat number` using `binary search`  
// - Display `the next available seat`  

// `Operations Example:`  
// ```
// Available Seats: [45, 12, 78, 23, 56]
// Sorted: [12, 23, 45, 56, 78]
// Search Seat 23: Found (Available)
// Next Available Seat: 45
// ```
#include <stdio.h>

void bubbleSort(int* seats, int size);
void printSeats(int* seats, int size);
void swap(int* first, int* second);
int searchBinary(int* seats, int size, int searchSeat);
int getNextAvailableSeat(int* seats, int size, int searchSeat);

int main() {
    int seats[] = {45, 12, 78, 23, 56};
    int seatsCount = 5;
    int searchSeat = 23;

    printf("Before Sort:\n");
    printSeats(seats, seatsCount);

    bubbleSort(seats, seatsCount);

    printf("After Sort:\n");
    printSeats(seats, seatsCount);

    int index = searchBinary(seats, seatsCount, searchSeat);
    if (index != -1) {
        printf("Search Seat %d: Found (Available)\n", searchSeat);
    } else {
        printf("Search Seat %d: Not Found\n", searchSeat);
    }

    int nextSeat = getNextAvailableSeat(seats, seatsCount, searchSeat);
    if (nextSeat != -1) {
        printf("Next Available Seat: %d\n", nextSeat);
    } else {
        printf("No Available Seat Found\n");
    }

    return 0;
}

void printSeats(int* seats, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", seats[i]);
    }
    printf("\n");
}

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int* seats, int size) {
    int isSwapped;
    do {
        isSwapped = 0;
        for (int i = 0; i < (size - 1); i++) {
            if (seats[i] > seats[i + 1]) {
                swap(&seats[i], &seats[i + 1]);
                isSwapped = 1;
            }
        }
        size--;
    } while (isSwapped);
}

int searchBinary(int* seats, int size, int searchSeat) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (seats[mid] == searchSeat) {
            return mid;
        } else if (searchSeat < seats[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int getNextAvailableSeat(int* seats, int size, int searchSeat) {
    for (int i = 0; i < size; i++) {
        if (seats[i] > searchSeat) {
            return seats[i];
        }
    }
    return -1;
}
