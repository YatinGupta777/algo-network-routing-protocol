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
    srand((unsigned int)time(NULL));
    auto start = high_resolution_clock::now();

    int source = rand() % VERTICES;
    int destination = rand() % VERTICES;

    cout << "Source : " << source << endl
         << "dest " << destination << endl;

    Graph sparse_graph, dense_graph;
    cout << "Sparse Graph : " << endl;

    sparse_graph.init();
    sparse_graph.generateGraph(6);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Generation : " << (double)duration.count() / 1000.0 << endl;

    start = high_resolution_clock::now();
    Dijkstra::maxBandwidthPath(sparse_graph, source, destination);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "maxBandwidthPath : " << (double)duration.count() / 1000.0 << endl;

    start = high_resolution_clock::now();
    Dijkstra::maxBandwidthPathWithHeap(sparse_graph, source, destination);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "maxBandwidthPathWithHeap : " << (double)duration.count() / 1000.0 << endl;

    start = high_resolution_clock::now();
    Graph mst = Kruskal::createMST(sparse_graph);
    Kruskal::maxBandwidthPath(mst, source, destination);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Kruskal : " << (double)duration.count() / 1000.0 << endl;
    // cout << "Kruskal : " << clock() - start << endl;
    // start = clock();

    start = high_resolution_clock::now();
    cout << "Dense Graph : " << endl;
    dense_graph.init();
    dense_graph.generateGraph(VERTICES / 5);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Generation : " << (double)duration.count() / 1000.0 << endl;

    start = high_resolution_clock::now();
    Dijkstra::maxBandwidthPath(dense_graph, source, destination);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "maxBandwidthPath : " << (double)duration.count() / 1000.0 << endl;

    start = high_resolution_clock::now();
    Dijkstra::maxBandwidthPathWithHeap(dense_graph, source, destination);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "maxBandwidthPathWithHeap : " << (double)duration.count() / 1000.0 << endl;

    start = high_resolution_clock::now();
    Graph dense_mst = Kruskal::createMST(dense_graph);
    Kruskal::maxBandwidthPath(dense_mst, source, destination);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Kruskal : " << (double)duration.count() / 1000.0 << endl;

    return 0;
}