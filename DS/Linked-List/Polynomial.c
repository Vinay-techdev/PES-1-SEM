#include <stdio.h>
#include <stdlib.h>

// Node structure for a polynomial term
typedef struct Node {
    int coeff;
    int pow;
    struct Node* link;
}*Node;

// Create a new node
Node createNode(int coeff, int pow) {
    Node newNode = (Node) malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->link = NULL;
    return newNode;
}

// Insert term in ascending order of powers
Node insertOrder(int coeff, int pow, Node head) {
    Node newNode = createNode(coeff, pow);
    if(newNode == NULL){
        printf("Cannot insert due to insufficient memory!!\n");
        return head;
    }

    if(head == NULL || pow < head->pow){
        newNode->link = head;
        return newNode;
    }

    Node temp = head;
    while(temp->link != NULL && temp->link->pow < pow){
        temp = temp->link;
    }

    newNode->link = temp->link;
    temp->link = newNode;
    return head;
}

// Display polynomial
void display(Node head) {
    if(head == NULL){
        printf("Polynomial is empty!\n");
        return;
    }

    Node temp = head;
    while(temp != NULL){
        printf("%dx^%d", temp->coeff, temp->pow);
        if(temp->link != NULL)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

// Add two polynomials (ascending powers)
Node addPoly(Node p1, Node p2) {
    
    Node result = NULL;
    
    while(p1 != NULL && p2 != NULL){
        if(p1->pow < p2->pow){
            result = insertOrder(p1->coeff, p1->pow, result);
            p1 = p1->link;
        } else if(p2->pow < p1->pow){
            result = insertOrder(p2->coeff, p2->pow, result);
            p2 = p2->link;
        } else { // same power
            int sum = p1->coeff + p2->coeff;
            if(sum != 0)
                result = insertOrder(sum, p1->pow, result);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while(p1 != NULL){
        result = insertOrder(p1->coeff, p1->pow, result);
        p1 = p1->link;
    }
    while(p2 != NULL){
        result = insertOrder(p2->coeff, p2->pow, result);
        p2 = p2->link;
    }

    return result;
}

int main() {
    Node poly1 = NULL, poly2 = NULL, sum = NULL;

    // Polynomial 1: 5x^3 + 4x^2 + 2
    poly1 = insertOrder(5, 3, poly1);
    poly1 = insertOrder(4, 2, poly1);
    poly1 = insertOrder(2, 0, poly1);

    // Polynomial 2: 3x^3 + 2x^1 + 1
    poly2 = insertOrder(3, 3, poly2);
    poly2 = insertOrder(2, 1, poly2);
    poly2 = insertOrder(1, 0, poly2);

    printf("First Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    sum = addPoly(poly1, poly2);
    printf("Sum of Polynomials: ");
    display(sum);

    return 0;
}
