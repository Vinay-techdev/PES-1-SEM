
#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int *stk;
    int capacity;
}*myStack;

myStack createStack(int capcity){

    myStack newStack = (myStack) malloc(sizeof(struct stack));
    if(newStack == NULL){
        printf("insufficent memory");
        exit(EXIT_FAILURE);
    }

    newStack->stk = (int *) malloc(sizeof(int) * capcity);
    if(newStack->stk == NULL){
        printf("insufficent memory");
        exit(EXIT_FAILURE);
    } 

    newStack->top = -1;
    newStack->capacity = capcity;

    printf("Stack Successfully created!\n");
    return newStack;
}

int doSize(int size, myStack stack){

    int newSize = stack->capacity + size;
    int *array = (int *) realloc(stack->stk, sizeof(int) * newSize);

    if(array == NULL){
        printf("insufficent memory");
        return 0;
    }

    stack->stk = array;
    stack->capacity = newSize;
    return 1;
}

void push(int element, myStack stack){

    int status = ((stack->top) == (stack->capacity-1) ? doSize(1, stack) : 1);

    if(status){
        stack->stk[++stack->top] = element;
    } else {
        printf("stack overflow!");
    }

}

void pop(myStack stack){
    
    if(stack->top == -1){
        printf("Stack underflow\n");
        return;
    }

    printf("\nPOPed item %d\n", stack->stk[stack->top--]);
    doSize(-1, stack);
}

void peek(myStack stack){
    if(stack->top == -1){
        printf("Stack underflow\n");
        return;
    }

    printf("\nTop Element - %d\n", stack->stk[stack->top]);
}

void display(myStack stack){
    if(stack->top == -1){
        printf("Stack underflow\n");
        return;
    }

    printf("Stack -> ");
    for(int i = stack->top; i>=0; i--){
        printf("%d| ", stack->stk[i]);
    }
}

int main(){
    myStack stack = createStack(20);
    push(10,stack);
    push(20,stack);
    push(30,stack);
    display(stack);

    pop(stack);
    pop(stack);
    display(stack);

    peek(stack);
    return 0;
}
