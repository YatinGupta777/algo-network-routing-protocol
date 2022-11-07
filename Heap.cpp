#include "Heap.h"
#include "Graph.h"
#include <iostream>

using namespace std;
MaxHeap::MaxHeap()
{
    for (int i = 0; i < VERTICES; i++)
    {
        H[i] = -1;
        D[i] = -1;
        P[i] = -1;
    }
    current_size = -1;
}

void MaxHeap::fix_bottom_up(int current_node)
{
    if (current_node <= 0)
        return;

    int parent = (current_node - 1) / 2;

    if (D[H[current_node]] > D[H[parent]])
    {
        int initial_parent = H[parent];
        int initial_node = H[current_node];

        H[parent] = initial_node;
        H[current_node] = initial_parent;

        P[initial_parent] = current_node;
        P[initial_node] = parent;

        fix_bottom_up(parent);
    }
}

void MaxHeap::insert(Node *g)
{
    current_size++;
    int vertex = g->x;
    int weight = g->w;

    H[current_size] = vertex;
    D[vertex] = weight;
    P[vertex] = current_size;
    fix_bottom_up(current_size);
}

int MaxHeap::maximum()
{
    return H[0];
}

void MaxHeap::deleteElement(int vertex)
{
}

void MaxHeap::print()
{
    // for (int i = 0; i < VERTICES; i++)
    //     cout << " H " << H[i] << " D " << D[H[i]] << " P " << P[H[i]] << endl;
}