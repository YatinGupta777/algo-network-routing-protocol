#include <iostream>
#include "Graph.h"
#include "Dijkstra.h"
#include "Heap.h"
#include "Kruskal.h"
#include <chrono>
#include <iomanip>
#define NUMBER_OF_ITERATIONS 5

using namespace std;
using namespace std::chrono;

class Graph;

int main()
{
    srand((unsigned int)time(NULL));
    auto start = high_resolution_clock::now();

    double sparse_report[NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS][4] = {0};

    for (int i = 0; i < NUMBER_OF_ITERATIONS; i++)
    {
        cout << "Sparse Graph : " << endl;
        Graph sparse_graph, dense_graph;
        sparse_graph.init();
        sparse_graph.generateGraph(6);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Generation : " << (double)duration.count() / 1000.0 << endl;
        sparse_report[i * 5][0] = (double)duration.count() / 1000.0;
        for (int j = 0; j < NUMBER_OF_ITERATIONS; j++)
        {
            int source = rand() % VERTICES;
            int destination = rand() % VERTICES;

            cout << "Source : " << source << endl
                 << "dest " << destination << endl;

            start = high_resolution_clock::now();
            Dijkstra::maxBandwidthPath(sparse_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "maxBandwidthPath : " << (double)duration.count() / 1000.0 << endl;
            sparse_report[j + (i * 5)][1] = (double)duration.count() / 1000.0;

            start = high_resolution_clock::now();
            Dijkstra::maxBandwidthPathWithHeap(sparse_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "maxBandwidthPathWithHeap : " << (double)duration.count() / 1000.0 << endl;
            sparse_report[j + (i * 5)][2] = (double)duration.count() / 1000.0;

            start = high_resolution_clock::now();
            Kruskal::maxBandwidthPath(sparse_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Kruskal : " << (double)duration.count() / 1000.0 << endl;
            sparse_report[j + (i * 5)][3] = (double)duration.count() / 1000.0;
        }
    }

    start = high_resolution_clock::now();

    for (int i = 0; i < NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << " | ";
            cout << setw(6) << sparse_report[i][j];
        }
        cout << " | " << endl;
    }

    // cout << "Dense Graph : " << endl;
    // dense_graph.init();
    // dense_graph.generateGraph(VERTICES / 5);
    // stop = high_resolution_clock::now();
    // duration = duration_cast<microseconds>(stop - start);
    // cout << "Generation : " << (double)duration.count() / 1000.0 << endl;

    // start = high_resolution_clock::now();
    // Dijkstra::maxBandwidthPath(dense_graph, source, destination);
    // stop = high_resolution_clock::now();
    // duration = duration_cast<microseconds>(stop - start);
    // cout << "maxBandwidthPath : " << (double)duration.count() / 1000.0 << endl;

    // start = high_resolution_clock::now();
    // Dijkstra::maxBandwidthPathWithHeap(dense_graph, source, destination);
    // stop = high_resolution_clock::now();
    // duration = duration_cast<microseconds>(stop - start);
    // cout << "maxBandwidthPathWithHeap : " << (double)duration.count() / 1000.0 << endl;

    // start = high_resolution_clock::now();
    // Kruskal::maxBandwidthPath(dense_graph, source, destination);
    // stop = high_resolution_clock::now();
    // duration = duration_cast<microseconds>(stop - start);
    // cout << "Kruskal : " << (double)duration.count() / 1000.0 << endl;

    return 0;
}