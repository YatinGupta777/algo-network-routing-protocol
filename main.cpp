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

    double sparse_report[NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS][5] = {0};
    double dense_report[NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS][5] = {0};

    cout << "Sparse Graph : " << endl;
    for (int i = 0; i < NUMBER_OF_ITERATIONS; i++)
    {
        Graph sparse_graph;
        sparse_graph.init();
        sparse_graph.generateGraph(6);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for (int j = 0; j < NUMBER_OF_ITERATIONS; j++)
        {
            int source = rand() % VERTICES;
            int destination = rand() % VERTICES;

            sparse_report[j + (i * 5)][0] = source;
            sparse_report[j + (i * 5)][1] = destination;

            start = high_resolution_clock::now();
            Dijkstra::maxBandwidthPath(sparse_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            sparse_report[j + (i * 5)][2] = (double)duration.count() / 1000.0;

            start = high_resolution_clock::now();
            Dijkstra::maxBandwidthPathWithHeap(sparse_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            sparse_report[j + (i * 5)][3] = (double)duration.count() / 1000.0;

            start = high_resolution_clock::now();
            Kruskal::maxBandwidthPath(sparse_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            sparse_report[j + (i * 5)][4] = (double)duration.count() / 1000.0;
        }
    }

    cout << "SPARSE REPORT: Running time in milliseconds" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << " | " << setw(10) << "GRAPH #";
    cout << " | " << setw(10) << "SOURCE";
    cout << " | " << setw(12) << "DESTINATION";
    cout << " | " << setw(10) << "DIJKSTRA";
    cout << " | " << setw(18) << "DIJKSTRA WITH HEAP";
    cout << " | " << setw(10) << "KRUSKAL";
    cout << " | " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS; i++)
    {
        cout << " | ";
        cout << setw(9) << "G" << i / 5;
        for (int j = 0; j < 5; j++)
        {
            cout << " | ";
            int w = 10;
            if (j == 3)
                w = 18;
            else if (j == 1)
                w = 12;
            cout << setw(w) << sparse_report[i][j];
        }
        cout << " | " << endl;
    }

    double avg_dijkstra = 0, avg_dijkstra_with_heap = 0, avg_kruskal = 0;
    for (int i = 0; i < NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS; i++)
    {
        avg_dijkstra += sparse_report[i][2];
        avg_dijkstra_with_heap += sparse_report[i][3];
        avg_kruskal += sparse_report[i][4];
    }

    avg_dijkstra /= (NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS);
    avg_dijkstra_with_heap /= (NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS);
    avg_kruskal /= (NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS);

    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Average running time of Dikstra without heap : " << avg_dijkstra << "ms" << endl;
    cout << "Average running time of Dikstra with heap : " << avg_dijkstra_with_heap << "ms" << endl;
    cout << "Average running time of Kruskal : " << avg_kruskal << "ms" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

    start = high_resolution_clock::now();
    cout << "Dense Graph : " << endl;
    for (int i = 0; i < NUMBER_OF_ITERATIONS; i++)
    {
        Graph dense_graph;
        dense_graph.init();
        dense_graph.generateGraph(VERTICES / 5);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        for (int j = 0; j < NUMBER_OF_ITERATIONS; j++)
        {
            int source = rand() % VERTICES;
            int destination = rand() % VERTICES;

            dense_report[j + (i * 5)][0] = source;
            dense_report[j + (i * 5)][1] = destination;

            start = high_resolution_clock::now();
            Dijkstra::maxBandwidthPath(dense_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            dense_report[j + (i * 5)][2] = (double)duration.count() / 1000.0;

            start = high_resolution_clock::now();
            Dijkstra::maxBandwidthPathWithHeap(dense_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            dense_report[j + (i * 5)][3] = (double)duration.count() / 1000.0;

            start = high_resolution_clock::now();
            Kruskal::maxBandwidthPath(dense_graph, source, destination);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            dense_report[j + (i * 5)][4] = (double)duration.count() / 1000.0;
        }
    }

    cout << "DENSE REPORT: Running time in milliseconds" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << " | " << setw(10) << "GRAPH #";
    cout << " | " << setw(10) << "SOURCE";
    cout << " | " << setw(12) << "DESTINATION";
    cout << " | " << setw(10) << "DIJKSTRA";
    cout << " | " << setw(18) << "DIJKSTRA WITH HEAP";
    cout << " | " << setw(10) << "KRUSKAL";
    cout << " | " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS; i++)
    {
        cout << " | ";
        cout << setw(9) << "G" << i / 5;
        for (int j = 0; j < 5; j++)
        {
            cout << " | ";
            int w = 10;
            if (j == 3)
                w = 18;
            else if (j == 1)
                w = 12;
            cout << setw(w) << dense_report[i][j];
        }
        cout << " | " << endl;
    }

    avg_dijkstra = 0, avg_dijkstra_with_heap = 0, avg_kruskal = 0;
    for (int i = 0; i < NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS; i++)
    {
        avg_dijkstra += dense_report[i][2];
        avg_dijkstra_with_heap += dense_report[i][3];
        avg_kruskal += dense_report[i][4];
    }

    avg_dijkstra /= (NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS);
    avg_dijkstra_with_heap /= (NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS);
    avg_kruskal /= (NUMBER_OF_ITERATIONS * NUMBER_OF_ITERATIONS);

    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Average running time of Dikstra without heap : " << avg_dijkstra << "ms" << endl;
    cout << "Average running time of Dikstra with heap : " << avg_dijkstra_with_heap << "ms" << endl;
    cout << "Average running time of Kruskal : " << avg_kruskal << "ms" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

    return 0;
}