#include<stdio.h>
#define queue_size 1000
typedef float T;
typedef struct
{
    T element[queue_size];
    int size;
    int front;
    int back;
}queue;

void queueinit(queue* stk);
void queuepush(queue* stk,T element);
int queueempty(queue* stk);
T queuefront(queue* stk);
T queueback(queue* stk);
void queuepop(queue* stk);

int main()
{
    float salaries[]={50000,40000,48000,23000,2000};
    queue stk;
    queueinit(&stk);
    for(int i=0;i<5;i++)
    {
        queuepush(&stk,salaries[i]);
    }
    printf("Salaries from queue:\n");
    while(!queueempty(&stk))
    {
        float sal=queuefront(&stk);
        printf("%.2f ",sal);
        queuepop(&stk);
    }
    return 0;
}

void queueinit(queue* stk)
{
    stk->size=0;
    stk->front=-1;
    stk->back=-1;
}
void queuepush(queue* stk,T element)
{
    stk->back++;
    stk->element[stk->size]=element;
    stk->size++;
    if(stk->front==-1)
    {
        stk->front=0;
    }
}
int queueempty(queue* stk)
{
    return (stk->front==-1);
}
T queuefront(queue* stk)
{
    return stk->element[stk->front];
}
T queueback(queue* stk)
{
    return stk->element[stk->back];
}
void queuepop(queue* stk)
{
    if(queueempty(stk))
    {
        printf("queue is empty.\n");
        return;
    }
    
    if(stk->front==stk->back)
    {
        stk->front=-1;
        stk->back=-1;
        stk->size=0;
    }
    else
    {
        stk->size--;
    }
}
