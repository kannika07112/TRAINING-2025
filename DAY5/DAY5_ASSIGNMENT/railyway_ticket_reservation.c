#include<stdio.h>
#include<string.h>
#define MAX_CAPACITY 2
#define Queue_SIZE 1000

typedef struct { 
    int passengerId;
    char passengerName[30];
} Passenger;

typedef struct { 
    Passenger elements[Queue_SIZE];
    int _size;
    int _front;
    int _back;
} Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, Passenger element);
int QueueEmpty(Queue* q);
Passenger QueueFront(Queue* q);
void QueuePop(Queue* q);

int main() {    
    Queue reservationQueue, waitingList;
    QueueInit(&reservationQueue);
    QueueInit(&waitingList);

    Passenger passenger1 = {1, "Alice"};
    Passenger passenger2 = {2, "Bob"};
    Passenger passenger3 = {3, "Charlie"};

    if (reservationQueue._size < MAX_CAPACITY) {
        printf("Booking Confirmed: Passenger %d (%s)\n", passenger1.passengerId, passenger1.passengerName);
        QueuePush(&reservationQueue, passenger1);
    } else {
        printf("Waiting List: Passenger %d (%s)\n", passenger1.passengerId, passenger1.passengerName);
        QueuePush(&waitingList, passenger1);
    }

    if (reservationQueue._size < MAX_CAPACITY) {
        printf("Booking Confirmed: Passenger %d (%s)\n", passenger2.passengerId, passenger2.passengerName);
        QueuePush(&reservationQueue, passenger2);
    } else {
        printf("Waiting List: Passenger %d (%s)\n", passenger2.passengerId, passenger2.passengerName);
        QueuePush(&waitingList, passenger2);
    }

    if (reservationQueue._size < MAX_CAPACITY) {
        printf("Booking Confirmed: Passenger %d (%s)\n", passenger3.passengerId, passenger3.passengerName);
        QueuePush(&reservationQueue, passenger3);
    } else {
        printf("Waiting List: Passenger %d (%s)\n", passenger3.passengerId, passenger3.passengerName);
        QueuePush(&waitingList, passenger3);
    }

    printf("\n\nProcessing Reservations:\n");
    while(!QueueEmpty(&reservationQueue)) {
        Passenger p = QueueFront(&reservationQueue);
        printf("Passenger %d (%s)\n", p.passengerId, p.passengerName);
        QueuePop(&reservationQueue);
    }

    printf("Remaining Waiting List:\n");
    while(!QueueEmpty(&waitingList)) {
        Passenger p = QueueFront(&waitingList);
        printf("Passenger %d (%s)\n", p.passengerId, p.passengerName);
        QueuePop(&waitingList);
    }

    return 0;
}

void QueueInit(Queue* q) {
    q->_size = 0;
    q->_front = -1;
    q->_back = -1;
}

void QueuePush(Queue* q, Passenger element) {
    q->_back++;
    q->elements[q->_back] = element;
    q->_size++;
    if(q->_front == -1) {
        q->_front = 0;
    }
}

int QueueEmpty(Queue* q) {
    return (q->_front == -1);
}

Passenger QueueFront(Queue* q) {
    return q->elements[q->_front];
}

void QueuePop(Queue* q) {
    if(QueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    if(q->_front == q->_back) {
        q->_front = -1;
        q->_back = -1;
        q->_size = 0;
    } else {
        q->_front++;
    }
}
