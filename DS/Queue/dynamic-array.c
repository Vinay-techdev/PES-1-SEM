#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *arr;
    int front;
    int rear;
    int capacity;
} *myQueue;

myQueue createQueue(int capacity) {
    myQueue q = (myQueue) malloc(sizeof(struct queue));
    if (!q) {
        printf("Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }

    q->arr = (int*) malloc(sizeof(int) * capacity);
    if (!q->arr) {
        printf("Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }

    q->front = q->rear = -1;
    q->capacity = capacity;

    printf("Queue created with capacity %d\n", capacity);
    return q;
}


int resizeQueue(myQueue q, int size) {
    int newCapacity = q->capacity + size;
    if(newCapacity <= 0) return 0; 

    int *temp = (int*) realloc(q->arr, sizeof(int) * newCapacity);
    if(!temp) return 0;

    q->arr = temp;
    q->capacity = newCapacity;
    return 1;
}


int isEmpty(myQueue q) {
    return q->front == -1;
}

int isFull(myQueue q) {
    return q->rear == q->capacity - 1;
}

void enqueue(int data, myQueue q) {
    if(isFull(q)) {
        if(!resizeQueue(q, 1)) {
            printf("Queue overflow!\n");
            return;
        }
    }

    if(q->front == -1) q->front = 0;
    q->arr[++q->rear] = data;
    printf("Enqueued: %d\n", data);
}


int dequeue(myQueue q) {
    if(isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }

    int value = q->arr[q->front++];
    
    if(q->front > q->rear) {
        q->front = q->rear = -1;
        resizeQueue(q, -1);
    }

    return value;
}

int peek(myQueue q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(myQueue q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue -> ");
    for(int i = q->front; i <= q->rear; i++) {
        printf("%d| ", q->arr[i]);
    }
    printf("\n");
}


int main() {
    myQueue q = createQueue(2);

    enqueue(10, q);
    enqueue(20, q);
    enqueue(30, q);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    printf("Peek: %d\n", peek(q));
    return 0;
}
