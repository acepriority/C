#include <stdio.h> 
#include <stdlib.h> 

#define MAXN 10 /* Maximum number of vertices in graph / / this tells us vertex state... */ 
#define NOTVISITED 0 /* not yet encountered */ 
#define VISITED    1 /* already seen and dealt with */ 
#define TOUCHED    2 /* currently on stack but not yet 'visited' */  
struct Vertex { /* How we store the data... */     
    int visited;        /* current status of this vertex */     
    int adjacent[MAXN]; /* adjacent[j] is 0 if there is no                          
* edge between this vertex and vertex j                          */ 
}; 
typedef struct Vertex Vertex; 
Vertex vlist[MAXN]; /* the list of vertices */ 

int N = 0; /* actual number of vertices in your graph */ 
int start = 0; /* which vertex we start with */ 
void read_data(void) {     
    /* A note on data format:      
    * We expect the first line of data to consist of a single number;      
    * the number (N) of vertices in your graph.      
    * After that we expect N lines of N numbers each.      
    * These lines tell us, for each vertex, whether it is      
    * connected to any of the other vertices by an edge. The last line      
    * in the file tells us which vertex we start traversing from      
    * e.g if N = 3, then we could have a file containing the lines:      
    * --      
    * 3      
    * 0 1 0      
    * 1 0 1      
    * 0 1 0      
    * 0      
    * --      
    * This means that we have 3 vertices numbered 0, 1, 2 of which:      
    * vertex 0 has no edge going from itself back to itself or to      
    * vertex 2, but has an edge to vertex 1. Vertex 1 has an edge      
    * back to itself, and another to 2. Vertex 2 has only one edge      
    * to vertex 1. We start traversing from vertex 0.      
    * (Try drawing this graph.)      */     
    int i, j;     
    scanf("%d", &N);     
    if (N >= MAXN) 
    {  
    printf("Too many vertices (%d) max allowed: %d\n", N, MAXN);  
    return;     
    }     
    for (i = 0; i < N; i++)  
        for (j = 0; j < N; j++)      
            scanf("%d", &vlist[i].adjacent[j]); 

    scanf("%d", &start); 
} 

/* Start stack functions and data... */ 
#define STACKSIZE MAXN * MAXN 
int stack[STACKSIZE], p = 0; 
void push(int v) {     
    if (p >= STACKSIZE) 
    {  
        printf("Stack overflow!\n");  
        return;     
    }     
    stack[p++] = v; 
} 
int pop(void) {     
    if (p <= 0) 
    {  
        printf("Stack underflow!\n");  
        return -1;     
    }     
    return stack[--p]; 
} 
int stackempty(void) {     
    return (p == 0); 
} 
/* End stack functions and data... */ 

void visit(int start) /* Start your bit... */ 
{     
    /* implement this: starting at vertex start, visit all      
    * vertices that can be reached from vertex k through any      
    * other vertices that are connected.      */ 
    push(start);
    int current, i ;
    current = pop();
    vlist[current].visited = VISITED;
    for(i=0; i<N; i++){
        if(vlist[current].adjacent[i] == 1 && vlist[i].visited == NOTVISITED){
            vlist[i].visited = TOUCHED;
            visit(i);
            }
        }
} 

/* prints out all vertices that cannot be reached */ 
void unreachable(void) {     
    int i;     
    for (i = 0; i < N; i++)  
        if (vlist[i].visited == NOTVISITED)      
            printf("vertex %d is unreachable from %d\n", i, start); 
} 
/* End your bit... */ 
void main(void) {     
    /* main() coordinates everything: It reads in the data      
    * by calling read_data(), calls visit(), then calls unreachable()      
    * You need not add anything here...      */     
    int i;          
    read_data(); 

    /* mark all vertices as visited */     
    for (i = 0; i < N; i++)  
        vlist[i].visited = NOTVISITED; 

    visit(start);     
    unreachable();
}