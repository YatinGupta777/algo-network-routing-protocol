#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "Heap.h"
#include "Kruskal.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

class Graph;

int main()
{
    auto start = high_resolution_clock::now();
    Graph sparse_graph, dense_graph;
    cout << "Sparse Graph : " << endl;

    sparse_graph.init();
    sparse_graph.generateGraph(6);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Generation : " << duration.count() << endl;
    start = high_resolution_clock::now();
    Dijkstra::maxBandwidthPath(sparse_graph, 0, VERTICES - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "maxBandwidthPath : " << duration.count() << endl;
    start = high_resolution_clock::now();
    Dijkstra::maxBandwidthPathWithHeap(sparse_graph, 0, VERTICES - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "maxBandwidthPathWithHeap : " << duration.count() << endl;
    start = high_resolution_clock::now();
    Graph mst = Kruskal::createMST(sparse_graph);
    Kruskal::maxBandwidthPath(mst, 0, VERTICES - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Kruskal : " << duration.count() << endl;
    // cout << "Kruskal : " << clock() - start << endl;
    // start = clock();

    start = high_resolution_clock::now();
    cout << "Dense Graph : " << endl;
    dense_graph.init();
    dense_graph.generateGraph(VERTICES / 5);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Generation : " << duration.count() << endl;

    start = high_resolution_clock::now();
    Dijkstra::maxBandwidthPath(dense_graph, 0, VERTICES - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "maxBandwidthPath : " << duration.count() << endl;

    start = high_resolution_clock::now();
    Dijkstra::maxBandwidthPathWithHeap(dense_graph, 0, VERTICES - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "maxBandwidthPathWithHeap : " << duration.count() << endl;
    start = high_resolution_clock::now();

    Graph dense_mst = Kruskal::createMST(dense_graph);
    Kruskal::maxBandwidthPath(dense_mst, 0, VERTICES - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Kruskal : " << duration.count() << endl;

    return 0;
}