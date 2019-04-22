#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000

// for queue ds
int queue[MAXV];

// front and tail
int front = -1, end = -1, is_empty = 1;

void enqueue(int );

int dequeue();

// for graph ds.
typedef struct {
    int y; /* adjacency info */
    int weight; /* edge weight, if any */
    struct edgenode *next; /* next edge in list */
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1]; /* adjacency info */
    int degree[MAXV+1]; /* outdegree of each vertex */
    int nvertices; /* number of vertices in graph */
    int nedges; /* number of edges in graph */
    bool directed; /* is the graph directed? */
} graph;

// prototype
void initialize_graph(graph *, bool );

// prototype
void read_graph(graph *, bool );

// prototype
void insert_edge(graph *, int , int , bool );

// prototype
void print_graph(graph *);

// void BFS.
void BFS(graph *, int );

int main(int argc, char const *argv[]) {
    graph *G = malloc(sizeof(graph));
    int option;
    do {
        printf("1. Init Graph\n");
        printf("2. Insert Edge\n");
        printf("3. Print Graph\n");
        printf("4. BFS\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
            initialize_graph(G, FALSE);
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            default:
            break;
        }
    } while (option != 5);

    return 0;
}


/* below functions are for queue operations. */
void enqueue(int num) {
    if ((front == end) && is_empty == 1) {
        front++; end++;
        queue[end] = num;
        is_empty = 0;
    }
    else {
        end++;
        queue[end] = num;
    }
}

int dequeue() {
    int temp;
    if (is_empty == 1) {
        return -1;
    }
    else {
        temp = queue[front];
        front++;
    }

    if (front > end) {
        front = end = -1;
        is_empty = 1;
    }
    return temp;
}


/* below functions are for graph operations. */
void initialize_graph(graph *g, bool directed) {
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (int i = 1; i <= MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void read_graph(graph *g, bool directed) {
    int m; /* number of edges */
    int x, y; /* vertices in edge (x,y) */

    initialize_graph(g, directed);
    scanf("%d %d",&(g->nvertices),&m);

    for (int i=1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g,x,y,directed);
    }
}

void insert_edge(graph *g, int x, int y, bool directed) {
    edgenode *p; /* temporary pointer */
    p = malloc(sizeof(edgenode)); /* allocate edgenode storage */
    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p; /* insert at head of list */
    g->degree[x]++;

    if (directed == FALSE)
        insert_edge(g,y,x,TRUE);
    else
        g->nedges++;
}

print_graph(graph *g) {
    edgenode *p; /* temporary pointer */

    for (int i = 1; i <= g->nvertices; i++) {
        printf("%d: ",i);
        p = g->edges[i];
        while (p != NULL) {
            printf(" %d", p->y);
            p = p->next;
        }
        printf("\n");
    }

}

// -1 - Undiscoverd, 0 - discovered, 1 processed.
void BFS(graph *g, int source) {
    int state[g->nvertices];
    int parent[g->nvertices];

    for (int i = 0; i < g->nvertices; i++) {
        state[i] = -1;
        parent[i] = -1;
    }

    state[source] = 0;
    parent[source] = -1;

    enqueue(source);

    while (is_empty != 0) {
        int u = dequeue();
        edgenode *p = g->edges[u];

        while (p != NULL) {
            if (state[p->y] == -1) {
                state[p->y] = 0;
                parent[p->y] = u;
                enqueue(p->y);
            }
            p = p->next;
        }
        state[u] = 1;
    }

}
