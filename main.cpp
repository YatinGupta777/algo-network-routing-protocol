#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"

using namespace std;
class Graph;

int main()
{
    Graph sparse_graph, dense_graph;
    sparse_graph.init();
    sparse_graph.generateGraph(3);
    sparse_graph.print();

    Dijkstra::maxBandwidthPathWithHeap(sparse_graph, 0, VERTICES - 1);
    // dense_graph.init();
    // dense_graph.generateGraph(VERTICES / 5);
    // dense_graph.print();

    return 0;
}