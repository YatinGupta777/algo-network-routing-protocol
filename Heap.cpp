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

void MaxHeap::swap(int x, int y)
{
    int initial_parent = H[x];
    int initial_node = H[y];

    H[x] = initial_node;
    H[y] = initial_parent;

    P[initial_parent] = y;
    P[initial_node] = x;
}

void MaxHeap::fixBottomUp(int current_node)
{
    if (current_node <= 0)
        return;

    int parent = (current_node - 1) / 2;

    if (D[H[current_node]] > D[H[parent]])
    {
        swap(parent, current_node);
        fixBottomUp(parent);
    }
}

void MaxHeap::fixTopDown(int current_node)
{
    int largest = current_node;
    int left_element = 2 * current_node + 1;
    int right_element = 2 * current_node + 2;

    if (left_element < current_size && D[H[left_element]] > D[H[largest]])
        largest = left_element;

    if (right_element < current_size && D[H[right_element]] > D[H[largest]])
        largest = right_element;

    if (largest != current_node)
    {
        swap(largest, current_node);
        fixTopDown(largest);
    }
}

void MaxHeap::insert(int vertex, int weight)
{
    current_size++;

    H[current_size] = vertex;
    D[vertex] = weight;
    P[vertex] = current_size;
    fixBottomUp(current_size);
}

int MaxHeap::maximum()
{
    return H[0];
}

void MaxHeap::deleteElement(int vertex)
{
    int position = P[vertex];

    // assign weight as MAX value to move it up
    D[vertex] = INT_MAX;
    fixBottomUp(position);

    // swap with last element
    swap(0, current_size);
    current_size--;
    fixTopDown(0);
}

void MaxHeap::print()
{
    cout << endl;
    for (int i = 0; i < current_size; i++)
        cout << " H " << H[i] << " D " << D[H[i]] << " P " << P[H[i]] << endl;

    for (int i = 0; i < VERTICES; i++)
        cout << " " << H[i];
    cout << endl
         << "XXXXXXX" << endl;
}