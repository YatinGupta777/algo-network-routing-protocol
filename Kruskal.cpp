#include "Graph.h"
#include "Kruskal.h"
#include "Set.h"
#include <iostream>

using namespace std;

bool cmp(Edge e1, Edge e2)
{
    return e1.weight > e2.weight;
}

void Kruskal::extractEdges(Graph G, vector<Edge> &edges)
{
    for (int i = 0; i < VERTICES; i++)
    {
        Node *t = G.nodes[i]->next;
        while (t != NULL)
        {
            if (i < t->x)
            {
                Edge e(i, t->x, t->w);
                edges.push_back(e);
            }
            t = t->next;
        }
    }
}

void Kruskal::createMST(Graph G)
{
    Graph MST;
    MST.init();
    vector<Edge> edges; // TODO

    extractEdges(G, edges);
    int number_of_edges = edges.size();
    sort(edges.begin(), edges.end(), cmp); // TODO REPLACE WITH HEAP SORT

    MUF kruskal_muf;

    for (int i = 0; i < VERTICES; i++)
        kruskal_muf.makeSet(i);

    for (int i = 0; i < number_of_edges; i++)
    {
        Edge e = edges[i];
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
