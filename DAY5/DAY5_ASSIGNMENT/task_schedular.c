// `1. Task Scheduler for Customer Support Calls`  
// `Scenario:`  
// A `customer support` team handles `incoming calls` on a `first-come, first-served` basis using a `queue`. The system should:  
// - Add `new calls to the queue`  
// - Process `calls in order`  
// - Display `remaining calls in the queue`  

// `Operations Example:`  
// ```
// New Call Added:  Call 101 from Alice  
// New Call Added:  Call 102 from Bob  
// Processing Call: 101 from Alice  
// Remaining Calls: 102 from Bob  

#include<stdio.h>
#include<string.h>
#define Queue_SIZE 1000

typedef struct { 
    int callId;
    char customerName[30];
} Call;

typedef struct { 
    Call elements[Queue_SIZE];
    int _size;
    int _front;
    int _back;
} Queue;

void QueueInit(Queue* stk);
void QueuePush(Queue* stk, Call element);
int QueueEmpty(Queue* stk);
Call QueueFront(Queue* stk);
Call QueueBack(Queue* stk);
void QueuePop(Queue* stk);

int main() {    
    Queue callQueue;
    QueueInit(&callQueue);

    Call call1 = {101, "Alice"};
    Call call2 = {102, "Bob"};

    printf("New Call Added: Call %d from %s\n", call1.callId, call1.customerName);
    QueuePush(&callQueue, call1);
    
    printf("New Call Added: Call %d from %s\n", call2.callId, call2.customerName);
    QueuePush(&callQueue, call2);

    printf("Processing Call: %d from %s\n", QueueFront(&callQueue).callId, QueueFront(&callQueue).customerName);
    QueuePop(&callQueue);

    printf("Remaining Calls:\n");
    while(!QueueEmpty(&callQueue)) {
        Call call = QueueFront(&callQueue);
        printf("Call %d from %s\n", call.callId, call.customerName);
        QueuePop(&callQueue);
    }

    return 0;
}

void QueueInit(Queue* stk) {
    stk->_size = 0;
    stk->_front = -1;
    stk->_back = -1;
}

void QueuePush(Queue* stk, Call element) {
    stk->_back++;
    stk->elements[stk->_back] = element;
    stk->_size++;
    if(stk->_front == -1) {
        stk->_front = 0;
    }
}

int QueueEmpty(Queue* stk) {
    return (stk->_front == -1);
}

Call QueueFront(Queue* stk) {
    return stk->elements[stk->_front];
}

Call QueueBack(Queue* stk) {
    return stk->elements[stk->_back];
}

void QueuePop(Queue* stk) {
    if(QueueEmpty(stk)) {
        printf("Queue is empty.\n");
        return;
    }
    if(stk->_front == stk->_back) {
        stk->_front = -1;
        stk->_back = -1;
        stk->_size = 0;
    } else {
        stk->_front++;
    }
}
