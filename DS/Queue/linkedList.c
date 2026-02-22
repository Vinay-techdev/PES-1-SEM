#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} *node;

typedef struct {
    node front;
    node rear;
} *queue;

queue createQueue() {
    queue q = (queue) malloc(sizeof(*q));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue q, int data) {
    node newNode = (node) malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory Overflow\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(q->rear == NULL) {   // first element
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(queue q) {
    if(q->front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    node temp = q->front;
    printf("Deleted: %d\n", temp->data);

    q->front = q->front->next;

    if(q->front == NULL)   // queue becomes empty
        q->rear = NULL;

    free(temp);
}

void peek(queue q) {
    if(q->front == NULL) {
        printf("Queue Empty\n");
        return;
    }

    printf("Front Element: %d\n", q->front->data);
}

void display(queue q) {
    if(q->front == NULL) {
        printf("Queue Empty\n");
        return;
    }

    node temp = q->front;
    printf("Queue: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    queue q = createQueue();
    int choice, data;

    while(1) {
        printf("\n---- QUEUE MENU ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                peek(q);
                break;

            case 4:
                display(q);
                break;

            case 5:
                printf("Existing...");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
