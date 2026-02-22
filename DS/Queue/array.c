
#include <stdio.h>
#define MAX 50

typedef struct myqueue{
    int queue[MAX];
    int front;
    int rear;
} queue;

void createQueue(queue *myqueue){
    myqueue->front = myqueue->rear = -1;
}

int isEmpty(queue *myqueue){
    return myqueue->rear == -1;
}

int isFull(queue *myqueue){
    return myqueue->rear == MAX - 1;
}

void enqueue(int data, queue *myqueue){

    if(isFull(myqueue)){
        printf("Queue is Full");
        return;
    }

    if(myqueue->front == -1) myqueue->front = 0;
    myqueue->queue[++myqueue->rear] = data;
}

void dequeue(queue *myqueue){
    if(isEmpty(myqueue)){
        printf("Queue is Empty!\n");
        return;
    }

    int dequeued = myqueue->queue[myqueue->front++];
    if(myqueue->front > myqueue->rear) createQueue(myqueue);
}

void peek(queue *myqueue){
    if(isEmpty(myqueue)){
        printf("Queue is Empty!\n");
        return;
    }

    printf("Peek Element: %d\n", myqueue->queue[myqueue->front]);
}

void display(queue *myqueue){
    if(isEmpty(myqueue)){
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue:");
    for(int i = myqueue->front; i<=myqueue->rear; i++){
        printf(" %d ->", myqueue->queue[i]);
    }
    printf(" NULL\n");
}

int main(){
    queue q;
    createQueue(&q);

    enqueue(20, &q);
    enqueue(10, &q);
    enqueue(50, &q);
    enqueue(30, &q);
    display(&q);
    
    peek(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    peek(&q);
    return 0;
}
