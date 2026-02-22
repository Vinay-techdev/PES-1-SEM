
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct stack{
    int stk[50];
    int top;
}*stack;

int isFUll(stack Mystack){
    return ((Mystack->top) == (MAX -1) ? 1 :0);
}

int isEmpty(stack Mystack){
    return ((Mystack->top) == -1 ? 1 : 0);
}

void push(stack Mystack){
    int element;
    if(isFUll(Mystack)){
        printf("\nStack overflow!");
        return;
    }

    printf("Enter Element to insert: ");
    scanf("%d", &element);
    Mystack->stk[++Mystack->top] = element;
}

void pop(stack Mystack){
    if(isEmpty(Mystack)){
        printf("\nStack underflow!");
        return;
    }

    printf("\nPoped element - %d\n", Mystack->stk[Mystack->top--]);
}

void peek(stack Mystack){

    if(isEmpty(Mystack)){
        printf("\nStack underflow!");
        return;
    }

    printf("\nTop element - %d\n", Mystack->stk[Mystack->top]);
}

void display(stack Mystack){
    if(isEmpty(Mystack)){
        printf("\nEmpty stack!");
        return;
    }

    printf("\nStack -> ");
    for(int i = Mystack->top; i>=0; i--){
        printf("%d| ", Mystack->stk[i]);
    }
}

int main(){

    stack Mystack = (stack) malloc(sizeof(struct stack));
    Mystack->top = -1;
    push(Mystack);
    push(Mystack);
    push(Mystack);
    push(Mystack);
    display(Mystack);

    pop(Mystack);
    pop(Mystack);
    display(Mystack);

    peek(Mystack);

    return 0;
}