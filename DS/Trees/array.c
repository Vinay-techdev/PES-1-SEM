#include <stdio.h>
#define MAX 20

int tree[MAX];   // array to store tree

void initTree() {
    for(int i = 0; i < MAX; i++)
        tree[i] = -1;   // -1 means empty
}

void insertRoot(int data) {
    if(tree[1] != -1) {
        printf("Root already exists!\n");
        return;
    }
    tree[1] = data;
}

void insertLeft(int parent, int data) {
    int index = parent * 2;
    if(tree[parent] == -1) {
        printf("Parent does not exist!\n");
        return;
    }
    if(tree[index] != -1) {
        printf("Left child already exists!\n");
        return;
    }
    tree[index] = data;
}

void insertRight(int parent, int data) {
    int index = parent * 2 + 1;
    if(tree[parent] == -1) {
        printf("Parent does not exist!\n");
        return;
    }
    if(tree[index] != -1) {
        printf("Right child already exists!\n");
        return;
    }
    tree[index] = data;
}

void display() {
    printf("Binary Tree Array:\n");
    for(int i = 1; i < MAX; i++) {
        if(tree[i] != -1)
            printf("Index %d -> %d\n", i, tree[i]);
    }
}

void displayNodeRelationship() {
    printf("\nNode Relationships:\n");

    for(int i = 1; i < MAX; i++) {
        if(tree[i] != -1) {
            printf("Node %d -> ", tree[i]);

            // Left child
            if(2*i < MAX && tree[2*i] != -1)
                printf("Left: %d ", tree[2*i]);
            else
                printf("Left: NULL ");

            // Right child
            if(2*i+1 < MAX && tree[2*i+1] != -1)
                printf("Right: %d ", tree[2*i+1]);
            else
                printf("Right: NULL ");

            printf("\n");
        }
    }
}


int main() {
    initTree();

    insertRoot(10);
    insertLeft(1, 20);
    insertRight(1, 30);
    insertLeft(2, 40);
    insertRight(2, 50);

    display();
    displayNodeRelationship();

    return 0;
}

