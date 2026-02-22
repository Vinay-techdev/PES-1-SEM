#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stk[MAX];
int minStack[MAX];   // store current min
int top = -1;

int isEmpty() { return top == -1; }
int isFull() { return top == MAX-1; }


void push(int x) {
    if(isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stk[++top] = x;

    if(top == 0) minStack[top] = x;
    else minStack[top] = (x < minStack[top-1]) ? x : minStack[top-1];

    printf("%d pushed\n", x);
}

void pop() {
    if(isEmpty()) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped = %d\n", stk[top]);
    top--;
}

void peek() {
    if(isEmpty()) { printf("Stack Empty\n"); return; }
    printf("Top = %d\n", stk[top]);
}

void getMin() {
    if(isEmpty()) { printf("Stack Empty\n"); return; }
    printf("Min = %d\n", minStack[top]);
}

void display() {
    if(isEmpty()) { printf("Stack Empty\n"); return; }
    printf("Stack -> ");
    for(int i=top; i>=0; i--) printf("%d| ", stk[i]);
    printf("\n");
}

// MAIN
int main() {
    int choice, x;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Get Min\n6.Exit\n");
        printf("Enter choice: "); scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element: "); scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                getMin();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
