#include "Heap.h"
#include "Graph.h"
#include <iostream>

using namespace std;
MaxHeap::MaxHeap()
{
    current_size = -1;
}

void MaxHeap::fix_bottom_up(int current_node)
{
    if (current_node <= 0)
        return;

    int parent = (current_node - 1) / 2;

    if (D[H[current_node]] > D[H[parent]])
    {
        int temp = H[parent];
        H[parent] = H[current_node];
        H[current_node] = temp;
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

void MaxHeap::maximum()
{
}

void MaxHeap::deleteElement()
{
}

void MaxHeap::print()
{
    for (int i = 0; i < current_size; i++)
        cout << H[i] << " ";
}