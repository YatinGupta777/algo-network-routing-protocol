#include "Graph.h"
#include "Kruskal.h"
#include "Set.h"
#include <iostream>

using namespace std;

bool cmp(Edge e1, Edge e2)
{
    return e1.weight > e2.weight;
}

void Kruskal::createMST(Graph G)
{
    Graph MST;
    MST.init();

    int number_of_edges = G.edges.size();

    sort(G.edges.begin(), G.edges.end(), cmp); // TODO REPLACE WITH HEAP SORT

    // cout << endl;
    // for (int i = 0; i < number_of_edges; i++)
    //     cout << G.edges[i].weight << " ";
    // cout << endl;

    MUF kruskal_muf;

    for (int i = 0; i < VERTICES; i++)
        kruskal_muf.makeSet(i);

    for (int i = 0; i < number_of_edges; i++)
    {
        Edge e = G.edges[i];
        int v1 = e.v1;
        int v2 = e.v2;

        if (kruskal_muf.find(v1) != kruskal_muf.find(v2))
        {
            MST.addEdge(v1, v2, e.weight);
            kruskal_muf.union_vertices(v1, v2);
        }
    }

    MST.print();
}
