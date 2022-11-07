#include "Graph.h"
#include "Kruskal.h"
#include <iostream>

using namespace std;

bool cmp(Edge e1, Edge e2)
{
    return e1.weight > e2.weight;
}

void Kruskal::createMST(Graph G)
{
    int number_of_edges = G.edges.size();

    cout << endl;
    for (int i = 0; i < number_of_edges; i++)
        cout << G.edges[i].weight << " ";
    cout << endl;

    sort(G.edges.begin(), G.edges.end(), cmp); // TODO REPLACE WITH HEAP SORT

    cout << endl;
    for (int i = 0; i < number_of_edges; i++)
        cout << G.edges[i].weight << " ";
    cout << endl;
}
