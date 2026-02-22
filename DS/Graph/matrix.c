
#include <stdio.h>
#include <stdlib.h>

typedef struct graphADT{
    int vertices;
    int **matrix;
}*Graph;

Graph createGraph(int vertices){
    Graph Mygraph = malloc(sizeof(struct graphADT));
    Mygraph->vertices = vertices;

    Mygraph->matrix = malloc(vertices * sizeof(int*));
    for(int i = 0; i<vertices; i++){
        Mygraph->matrix[i] = malloc(vertices * sizeof(int));
        for(int j=0; j<vertices; j++){
            Mygraph->matrix[i][j]=0;
        }
    }
    return Mygraph;
}

void addEdge(Graph Mygraph, int src, int dest){
    Mygraph->matrix[src][dest] = 1;
    Mygraph->matrix[dest][src] = 1;
}

void print(Graph Mygraph){
    for(int i = 0; i<Mygraph->vertices; i++){
        for(int j=0; j<Mygraph->vertices;j++){
            printf("%d ", Mygraph->matrix[i][j]);
        }
        printf("\n");
    }
}

void destroy(Graph Mygraph){
    for(int i = 0; i<Mygraph->vertices; i++){
        free(Mygraph->matrix[i]);
    }
    free(Mygraph->matrix);
    free(Mygraph);
}

int main(){
    int numVertices = 4;
    Graph myGraph = createGraph(numVertices);
    addEdge(myGraph, 1,2);
    addEdge(myGraph, 1,3);
    addEdge(myGraph, 2,1);
    addEdge(myGraph, 0,3);
    print(myGraph);

    destroy(myGraph);
    return 0;
}