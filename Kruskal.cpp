#include "Graph.h"
#include "Kruskal.h"
#include "Set.h"
#include "Heap.h"
#include "Queue.h"
#include <iostream>

using namespace std;
Edge edges[MAX_EDGES];
class CUSTOM_QUEUE;

void printPath(int dad[], int source, int destination);
void printBandwidth(int dad[], int bwidth[], int source, int destination);

void Kruskal::extractEdges(Graph G, Edge edges[], int &number_of_edges)
{
    for (int i = 0; i < VERTICES; i++)
    {
        Node *t = G.nodes[i]->next;
        while (t != NULL)
        {
            if (i < t->x)
            {
                Edge e(i, t->x, t->w);
                edges[number_of_edges] = e;
                number_of_edges++;
            }
            t = t->next;
        }
    }
}

void Kruskal::BFS(Graph G, int source, int destination)
{
    int visited[VERTICES] = {0}, dad[VERTICES] = {0}, bwidth[VERTICES] = {0};
    CUSTOM_QUEUE q;
    q.push(source);
    visited[source] = 1;
    dad[source] = -1;
    bwidth[source] = INT_MAX;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        Node *t = G.nodes[x]->next;
        while (t != NULL)
        {
            int v = t->x;
            if (visited[v] == 0)
            {
                visited[v] = 1;
                q.push(v);
                dad[v] = x;
                bwidth[v] = t->w;
            }
            t = t->next;
        }
    }

    cout << "----------------------------------------------------------------- KRUSKAL -----------------------------------------------------------------" << endl;
    printPath(dad, source, destination);
    printBandwidth(dad, bwidth, source, destination);
}

Graph Kruskal::createMST(Graph G)
{
    Graph MST;
    MST.init();

    int number_of_edges = 0;

    extractEdges(G, edges, number_of_edges);

    EdgeHeap::heapSort(edges, number_of_edges);

    MUF kruskal_muf;

    for (int i = 0; i < VERTICES; i++)
        kruskal_muf.makeSet(i);

    for (int i = 0; i < number_of_edges; i++)
    {
        Edge e = edges[i];
        int v1 = e.v1;
        int v2 = e.v2;

        int r1 = kruskal_muf.find(v1);
        int r2 = kruskal_muf.find(v2);

        if (r1 != r2)
        {
            MST.addEdge(v1, v2, e.weight);
            kruskal_muf.unionVertices(r1, r2);
        }
    }

    return MST;
}

void Kruskal::maxBandwidthPath(Graph g, int source, int destination)
{
    Graph mst = Kruskal::createMST(g);
    BFS(mst, source, destination);
}
