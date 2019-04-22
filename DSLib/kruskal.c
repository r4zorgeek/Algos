#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 1000

int id[MAXV];

typedef struct {
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV];
    int nvertices;
    int nedges;
    bool directed;
} graph;

void init_graph(graph *, bool );

void read_graph(graph *, bool );

void insert_edge(graph *, int , int , bool );

void print_graph(graph *);

void initialize() {
    for (int i = 0; i < MAXV; i++) {
        id[i] = i;
    }
}

int root(int x) {
    while(id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}


int main(int argc, char const *argv[]) {
    graph *G = malloc(sizeof(graph));
    read_graph(G, false);
    print_graph(G);
    return 0;
}


void init_graph(graph *g, bool directed) {
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (int i = 1; i < g->nvertices; i++) {
        // g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void read_graph(graph *g, bool directed) {
    int m;
    int x, y, weight;

    init_graph(g, directed);
    scanf("%d %d", &g->nvertices, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &x, &y, &weight);
        insert_edge(g, x, y, directed);
    }
}

void insert_edge(graph *g, int x, int y, int weight, bool directed) {
    edgenode *p = malloc(sizeof(edgenode));
    p->weight = weight;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;

    if (directed == false) {
        insert_edge(g, y, x, true);
    }
    else {
        g->nedges++;
    }
}

void print_graph(graph *g) {
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
