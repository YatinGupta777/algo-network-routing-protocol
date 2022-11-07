#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "Heap.h"
#include "Kruskal.h"

using namespace std;
class Graph;

int main()
{
    Graph sparse_graph, dense_graph;
    sparse_graph.init();
    sparse_graph.generateGraph(3);
    sparse_graph.print();

    // Dijkstra::maxBandwidthPath(sparse_graph, 0, VERTICES - 1);
    // Dijkstra::maxBandwidthPathWithHeap(sparse_graph, 0, VERTICES - 1);
    //   dense_graph.init();
    //   dense_graph.generateGraph(VERTICES / 5);
    //   dense_graph.print();

    // MaxHeap fringer_heap;
    // for (int i = 0; i < 5; i++)
    //     fringer_heap.insert(i, i);

    // fringer_heap.deleteElement(4);
    // fringer_heap.insert(4, 4);
    // fringer_heap.print();
    cout << "KRUSKAL " << endl;
    Kruskal::createMST(sparse_graph);

    return 0;
}