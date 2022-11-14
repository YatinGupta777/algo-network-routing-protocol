#pragma once
#include "Graph.h"

class Kruskal
{
public:
    static Graph createMST(Graph G);
    static void maxBandwidthPath(Graph G, int source, int destination);
    static void extractEdges(Graph G, Edge edges[], int &number_of_edges);
    static void BFS(Graph G, int source, int destination);
};