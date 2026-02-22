
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}*Node;

Node createNode(int data){
    Node newNode = (Node) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Unable to create node!");
        return NULL;
    }

    newNode->data = data;
    newNode->link = NULL;
    return newNode; 
}

Node insertFront(int data, Node head){

    Node newNode = createNode(data);
    if(newNode == NULL){
        printf("Cannot insert due to insufficent memory!!");
        return head;
    }

    newNode->link = head;
    head = newNode;
    return head;
}

Node insertEnd(int data, Node head){
    Node newNode = createNode(data);
    if(newNode == NULL){
        printf("Cannot insert due to insufficent memory!!");
        return head;
    }

    if(head == NULL){
        head = newNode;
        return head;
    }

    Node temp = head;
    while(temp->link != NULL) temp = temp->link;
    temp->link = newNode;
    return head;
}

Node insertPos(int data, int pos, Node head){

    Node newNode = createNode(data);
    if(newNode == NULL){
        printf("Cannot insert due to insufficent memory!!");
        return head;
    }

    if(pos == 1){
        newNode->link = head;
        return newNode;
    }

    Node temp = head;
    int count = 1;
    while(temp != NULL && count < pos -1){
        temp = temp->link;
        count +=1;
    }

    if(temp == NULL){
        printf("Postion %d out of bound while inserting!\n", pos);
        free(newNode);
        return head;
    }

    newNode->link = temp->link;
    temp->link = newNode;
    return head;
}

Node insertOrder(int data, Node head){
    Node newNode = createNode(data);

    if(newNode == NULL){
        printf("Cannot insert due to insufficent memory!!");
        return head;
    }

    if(head == NULL || data < head->data){
        newNode->link = head;
        return newNode;
    }

    Node temp = head;
    while(temp->link != NULL && temp->link->data < data) 
    temp = temp->link;
    
    newNode->link = temp->link;
    temp->link = newNode;
    return head;
}

Node deleteFront(Node head){
    Node temp = head;
    if(head == NULL){
        printf("List is Empty!");
        return NULL;
    }

    if(head->link == NULL){
        free(head);
        return NULL;
    }

    head = head->link;
    free(temp);
    return head;
}

Node deleteEnd(Node head){
    if(head == NULL){
        printf("List is Empty!");
        return NULL;
    }

    if(head->link == NULL){
        free(head);
        return NULL;
    }

    Node temp = head;
    Node prev;
    while(temp->link != NULL){
        prev = temp;
        temp = temp->link;  
    } 

    prev->link = NULL;
    free(temp);
    return head;
}

Node deletePos(int pos, Node head){
    
    if(head == NULL){
        printf("List Empty");
        return head;
    }
    
    Node temp = head;
    Node prev = NULL;
    int count = 1;

    if(pos == 1){
        head = head->link;
        free(temp);
        return head;
    }

    while(temp != NULL && count < pos){
        prev = temp;
        temp=temp->link;
        count++;
    }

    if(temp == NULL){
        printf("Postion %d out of bound while deleting!\n", pos);
        return head;
    }

    prev->link = temp->link;
    free(temp);

    return head;
}

Node deleteByContent(int key, Node head){
    if(head == NULL){
        printf("Head is empty!");
        return head;
    }
    if(key == head->data){
        head = head->link;
        free(head);
        return head;
    }
    Node temp = head; Node prev = NULL;

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->link;
    }

    if(temp == NULL){
        printf("Element not found!\n");
        return head;
    }

    prev->link = temp->link;
    free(temp);
    return head; 
}

Node reverse(Node head){
    Node newHead = NULL;

    while(head != NULL){
        int data = head->data;
        head = deleteFront(head);   // remove from old list
        newHead = insertFront(data, newHead); // add to new list
    }

    return newHead;
}

Node sort(Node head){
    Node newHead = NULL;
    while(head != NULL){
        int data = head->data;
        head = deleteFront(head);
        newHead = insertOrder(data, newHead);
    }

    return newHead;
}

Node merge(Node head1, Node head2){
    while(head2 != NULL){
        int data = head2->data;
        head2 = deleteFront(head2);
        head1 = insertOrder(data, head1);
    }

    return head1;
}

void display(Node head){
    Node temp = head;
    if(head==NULL){
        printf("List is Empty");
        return ;
    }

    printf("\nLinked List -> ");
    while(temp != NULL){
        printf("%d |",temp->data);
        temp = temp->link;
    }
}

int main(){
    Node head = NULL;
    Node head2 = NULL;
    Node head3 = NULL;
    head = insertEnd(5, head);
    head = insertEnd(10, head);
    head = deleteFront(head);
    head = insertFront(20, head);
    head = insertFront(15, head);
    head = deleteFront(head);
    head = insertFront(40, head);
    head = insertFront(30, head);
    head = insertPos(20, 2,head);
    head = deletePos(1,head);
    head = deletePos(3,head);
    head = deletePos(5,head);
    head = insertPos(20,10,head);
    head = insertEnd(5, head);
    
    head2 = insertOrder(20,head2);
    head2 = insertOrder(2,head2);
    head2 = insertOrder(10,head2);
    head2 = insertOrder(60,head2);
    head2 = deleteByContent(60, head2);
    display(head);
    display(head2);

    head = reverse(head);
    display(head);

    head = sort(head);
    display(head);
    
    head2 = sort(head2);
    display(head2);
    
    head3 =  merge(head, head2);
    display(head3);

    return 0;
}

