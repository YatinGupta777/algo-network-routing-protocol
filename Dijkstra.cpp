#include <iostream>
#include "Dijkstra.h"
#include "Heap.h"

using namespace std;

bool Dijkstra::isFringerPresent(int status[])
{
    for (int i = 0; i < VERTICES; i++)
    {
        if (status[i] == 1)
            return true;
    }
    return false;
}

int Dijkstra::largestBandwidthFringer(int status[], int bwidth[])
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

void Dijkstra::maxBandwidthPath(Graph g, int source, int dest)
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

    // cout << endl;
    // for (int i = 0; i < VERTICES; i++)
    // {
    //     cout << dad[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < VERTICES; i++)
    // {
    //     cout << bwidth[i] << " ";
    // }
}

void Dijkstra::maxBandwidthPathWithHeap(Graph g, int source, int dest)
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
    MaxHeap fringer_heap;

    while (iterator != NULL)
    {
        Node *neighbor_vertex = iterator;
        int vertex = neighbor_vertex->x;
        int weight = neighbor_vertex->w;
        status[vertex] = 1;
        bwidth[vertex] = weight;
        dad[vertex] = source;
        iterator = iterator->next;
        fringer_heap.insert(vertex, weight);
    }

    while (fringer_heap.currentSize() > 0)
    {
        int vertex_largest_bwidth = fringer_heap.maximum();
        fringer_heap.deleteElement(vertex_largest_bwidth);

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
                fringer_heap.insert(neighbor_vertex->x, bwidth[neighbor_vertex->x]);
            }
            else if (status[neighbor_vertex->x] == 1 && bwidth[neighbor_vertex->x] < min(bwidth[vertex_largest_bwidth], neighbor_vertex->w))
            {
                fringer_heap.deleteElement(neighbor_vertex->x);
                dad[neighbor_vertex->x] = vertex_largest_bwidth;
                bwidth[neighbor_vertex->x] = min(bwidth[vertex_largest_bwidth], neighbor_vertex->w);
                fringer_heap.insert(neighbor_vertex->x, bwidth[neighbor_vertex->x]);
            }
            iterator = iterator->next;
        }
    }

    // cout << endl;
    // for (int i = 0; i < VERTICES; i++)
    // {
    //     cout << dad[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < VERTICES; i++)
    // {
    //     cout << bwidth[i] << " ";
    // }
}