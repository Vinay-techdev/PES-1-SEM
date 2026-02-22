
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *lptr;
    struct Node *rptr;
}*node;

node createNode(int data){
    node newNode = (node) malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("Unable to create node!");
        return NULL;
    }

    newNode->data = data;
    newNode->lptr = newNode->rptr = NULL;
    return newNode;
}

node insertFront(int data, node head){
    node newNode = createNode(data);

    if(newNode==NULL){
        printf("Cannot insert due to insufficent memory!!");
        return head;
    }

    if(head == NULL)
        return newNode;

    head->lptr = newNode;
    newNode->rptr = head;
    return newNode; 
}

node insertEnd(int data, node head){

    node newNode = createNode(data);
    if(newNode == NULL){
        printf("Cannot insert due to insufficent memory!!");
        return head;
    }

    if(head == NULL) return newNode;

    node temp = head;
    while(temp->rptr != NULL) temp = temp->rptr;
    temp->rptr = newNode;
    newNode->lptr = temp;
    return head;
}

node insertAfter(int data, int key, node head){
    
    node newNode = createNode(data);
    if(newNode == NULL){
        printf("Cannot Insert due to insufficent memory!\n");
        return head;
    }

    if(head == NULL) return newNode;
    node temp = head;

    while(temp != NULL && temp->data != key) temp = temp->rptr;
    
    if(temp == NULL){
        printf("\nkey %d not found in the list!\n", key);
        return head;
    }
    
    newNode->lptr = temp;
    newNode->rptr = temp->rptr;

    if(temp->rptr != NULL)temp->rptr->lptr = newNode;
    
    temp->rptr = newNode;
    return head;
}

node insertPos(int data, int pos, node head){
    node newNode = createNode(data);

    if(newNode == NULL){
        printf("Cannot Insert due to insufficent memory!\n");
        return head;
    }

    if(head == NULL || pos == 1) {
        newNode->rptr = head;
        if(head != NULL) head->lptr = newNode;
        return newNode;
    }

    node temp = head;
    int count = 1;
    while(temp->rptr != NULL && count<pos-1){
        temp=temp->rptr;
        count ++;
    } 

    if(temp == NULL){
        printf("Position %d not found!\n", pos);
        free(newNode);
        return head;
    }
    newNode->lptr = temp;
    newNode->rptr = temp->rptr;

    if(temp->rptr != NULL)
        temp->rptr->lptr = newNode;

    temp->rptr = newNode;
    return head;
}

node insertOrder(int data, node head){

    node newNode = createNode(data);
    if(newNode == NULL){
        printf("Cannot Insert due to insufficent memory!\n");
        return head;
    }
    if(head == NULL) return newNode;

    if(data<head->data){
        head->lptr=newNode;
        newNode->rptr=head;
        return newNode;
    }


    node temp = head;
    while(temp->rptr != NULL && temp->rptr->data<data) temp = temp->rptr;
    
    newNode->lptr = temp;
    newNode->rptr = temp->rptr;

    if(temp->rptr != NULL){
        temp->rptr->lptr = newNode;
    }
    temp->rptr = newNode;
    return head;
}

node deleteFront(node head){

    if(head == NULL){
        printf("List is Empty!\n");
        return NULL;
    }

    node temp = head;
    head = head->rptr;
    if(head !=NULL) head->lptr = NULL;
    free(temp);
    return head;
}

node deleteEnd(node head){
    if(head == NULL){
        printf("List is Empty!\n");
        return NULL;
    }

    if(head->rptr == NULL){
        free(head);
        return NULL;
    }

    node temp = head;
    while(temp->rptr->rptr != NULL) temp = temp->rptr;

    node freeNode = temp->rptr;
    temp->rptr = NULL;
    free(freeNode);
    return head;
}

node deletePos(int pos, node head){

    node temp = head;
    int count =1;

    if(head == NULL) return head;

    if(pos == 1){
        head = head->rptr;
        if(head!=NULL) head->lptr = NULL;
        free(temp);
        return head;
    }

    while(temp != NULL && count<pos){
        temp=temp->rptr;
        count++;
    }

    if(temp == NULL){
        printf("Position %d not found!\n", pos);
        return head;
    }
    
    if(temp->lptr != NULL) temp->lptr->rptr = temp->rptr;
    if(temp->rptr != NULL) temp->rptr->lptr = temp->lptr;
    
    free(temp);
    return head;
}

node reverse(node head){
    if(head == NULL){
        printf("List is Empty\n");
        return NULL;
    }

    node temp = NULL;
    node curr = head;

    while(curr!=NULL){
        temp = curr->lptr;
        curr->lptr = curr->rptr;
        curr->rptr = temp;
        curr = curr->lptr;
    }

    if(temp!=NULL) head = temp->lptr;

    return head;
}

node sort(node head){

    if(head == NULL){
        printf("List is Empty\n");
        return NULL;
    }

    node i,j;

    for(i=head; i != NULL; i=i->rptr){
        for(j=i->rptr; j!= NULL; j=j->rptr){
            if(i->data > j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return head;
}

int nodeCount(node head){
    if(head == NULL){
        printf("List is Empty\n");
        return 0;
    }

    if(head->rptr == NULL) return 1;

    node temp = head;
    int counter = 0;
    while(temp != NULL){
        temp = temp->rptr;
        counter++;
    }

    return counter;
}

void display(node head){

    if(head == NULL){
        printf("List is Empty!\n");
        return ;
    }

    node temp = head;
    printf("\nLinked List -> ");
    while(temp!=NULL){
        printf("%d| ", temp->data);
        temp= temp->rptr;
    }
}

int main(){
    node head = NULL;
    node head2 = NULL;
    head = insertFront(10, head);
    head = insertFront(20, head);
    head = insertEnd(40, head);
    head = insertEnd(60, head);
    display(head);

    head = deleteFront(head);
    display(head);
    head = deleteEnd(head);
    head = insertAfter(30, 10, head);
    head = insertPos(100, 4, head);
    display(head);
    head = deletePos(3, head);
    display(head);

    head2 = insertOrder(20,head2);
    head2 = insertOrder(10,head2);
    head2 = insertOrder(8,head2);
    head2 = insertOrder(60,head2);
    display(head2);

    head2 = reverse(head2);
    display(head2);

    head2 = sort(head2);
    display(head2);

    int numOfNodes = nodeCount(head);
    printf("\nNumber of nodes in Linked List 1 - %d", numOfNodes); 

    numOfNodes = nodeCount(head2);
    printf("\nNumber of nodes in Linked List 2 - %d", numOfNodes); 
    return 0;
}