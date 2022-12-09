#include <stdio.h>
#include <string.h>

// C Implementation
#define MAX_NODES 5

struct adjacentListTable {
    int adjacent_list[MAX_NODES];
};

struct graph {
    int num_nodes;
    struct adjacentListTable adjacent_list_table[MAX_NODES];
};

void graphInit(struct graph *graph) {
    graph->num_nodes = 0;
    for(int i = 0; i < MAX_NODES; i++) {
        graph->adjacent_list_table[i].adjacent_list[0] = -1;
    }
}

void graphAddVertex(struct graph *graph, int value) {
    memset(graph->adjacent_list_table[value].adjacent_list, 0, MAX_NODES);
    graph->num_nodes++;
}

void graphAddEdge(struct graph *graph, int from, int to) {
    graph->adjacent_list_table[from].adjacent_list[to] = 1;
    graph->adjacent_list_table[to].adjacent_list[from] = 1;
}

void graphPrint(struct graph *graph) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if(graph->adjacent_list_table[i].adjacent_list[0] != -1) {
            printf("%d: ", i);
            for (int j = 0; j < MAX_NODES; j++) {
                printf("%d ", graph->adjacent_list_table[i].adjacent_list[j]);
            }
            printf("\n");
        }
    }
}

void main() {
    static struct graph graph;
    graphInit(&graph);

    graphAddVertex(&graph, 0);
    graphAddVertex(&graph, 1);
    graphAddVertex(&graph, 2);
    graphAddVertex(&graph, 3);
    graphAddVertex(&graph, 4);

    graphAddEdge(&graph, 0, 1);
    graphAddEdge(&graph, 1, 2);
    graphAddEdge(&graph, 1, 3);
    graphAddEdge(&graph, 4, 3);

    graphPrint(&graph);
}