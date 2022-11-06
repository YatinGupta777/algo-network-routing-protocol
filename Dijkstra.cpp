#include <iostream>
#include "Graph.h"

using namespace std;

bool isFringerPresent(int status[])
{
    for (int i = 0; i < VERTICES; i++)
    {
        if (status[i] == 1)
            return true;
    }
    return false;
}

int largestBandwidthFringer(int status[], int bwidth[])
{
    int ans = 0;
    int max_w = 0;
    for (int i = 0; i < VERTICES; i++)
    {
        if (status[i] == 1)
        {
            if (bwidth[i] > max_w)
            {
                max_w = bwidth[i];
                ans = i;
            }
        }
    }
    return ans;
}

void maxBandwidthPath(Graph g, int source, int dest)
{
    int status[VERTICES]; // 0 unseen 1 fringer 2 in-tree
    int bwidth[VERTICES];
    int dad[VERTICES];

    for (int i = 0; i < VERTICES; i++)
    {
        status[i] = 0;
        bwidth[i] = 0;
        dad[i] = -1;
    }

    status[source] = 2;
    bwidth[source] = INT_MAX;
    dad[source] = -1;

    Node *iterator = g.nodes[source]->next;

    while (iterator != NULL)
    {
        Node *neighbor_vertex = iterator;
        status[neighbor_vertex->x] = 1;
        bwidth[neighbor_vertex->x] = neighbor_vertex->w;
        dad[neighbor_vertex->x] = source;
        iterator = iterator->next;
    }

    while (isFringerPresent(status))
    {
        int vertex_largest_bwidth = largestBandwidthFringer(status, bwidth);
        status[vertex_largest_bwidth] = 2;
        Node *iterator = g.nodes[vertex_largest_bwidth]->next;

        while (iterator != NULL)
        {
            Node *neighbor_vertex = iterator;
            if (status[neighbor_vertex->x] == 0)
            {
                status[neighbor_vertex->x] = 1;
                dad[neighbor_vertex->x] = vertex_largest_bwidth;
                bwidth[neighbor_vertex->x] = min(bwidth[vertex_largest_bwidth], neighbor_vertex->w);
            }
            else if (status[neighbor_vertex->x] == 1 && bwidth[neighbor_vertex->x] < min(bwidth[vertex_largest_bwidth], neighbor_vertex->w))
            {
                dad[neighbor_vertex->x] = vertex_largest_bwidth;
                bwidth[neighbor_vertex->x] = min(bwidth[vertex_largest_bwidth], neighbor_vertex->w);
            }
            iterator = iterator->next;
        }
    }

    cout << endl;
    for (int i = 0; i < VERTICES; i++)
    {
        cout << dad[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < VERTICES; i++)
    {
        cout << bwidth[i] << " ";
    }
}