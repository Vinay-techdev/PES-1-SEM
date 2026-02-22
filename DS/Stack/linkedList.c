#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} *node;

node push(node top, int data){

    node newNode = (node) malloc(sizeof(node));
    if(newNode == NULL){
        printf("Stack Overflow\n");
        return top;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;

    return top;
}

node pop(node top){

    if(top == NULL){
        printf("Stack Underflow\n");
        return NULL;
    }

    node temp = top;
    printf("Popped Element: %d\n", temp->data);

    top = top->next;
    free(temp);

    return top;
}

void peek(node top){
    if(top == NULL){
        printf("Stack is Empty\n");
        return;
    }

    printf("Top Element: %d\n", top->data);
}

void display(node top){
    if(top == NULL){
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");
    node temp = top;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){

    node top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    display(top);

    top = pop(top);
    display(top);

    peek(top);

    return 0;
}
