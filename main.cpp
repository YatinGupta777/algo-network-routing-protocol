#include <iostream>
#include "Graph.h"

using namespace std;
class Graph;

int main()
{
    Graph sparse_graph, dense_graph;
    sparse_graph.init();
    sparse_graph.generateGraph(6);
    sparse_graph.print();

    // dense_graph.init();
    // dense_graph.generateGraph(VERTICES / 5);
    // dense_graph.print();

    return 0;
}