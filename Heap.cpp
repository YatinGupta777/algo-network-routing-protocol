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
    last_element_index = -1;
}

int MaxHeap::currentSize()
{
    return last_element_index + 1;
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

    if (left_element <= last_element_index && D[H[left_element]] > D[H[largest]])
        largest = left_element;

    if (right_element <= last_element_index && D[H[right_element]] > D[H[largest]])
        largest = right_element;

    if (largest != current_node)
    {
        swap(largest, current_node);
        fixTopDown(largest);
    }
}

void MaxHeap::insert(int vertex, int weight)
{
    last_element_index++;

    H[last_element_index] = vertex;
    D[vertex] = weight;
    P[vertex] = last_element_index;
    fixBottomUp(last_element_index);
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
    swap(0, last_element_index);

    last_element_index--;
    fixTopDown(0);
}

void EdgeHeap::heapify(Edge edges[], int n, int i)
{
    int smallest = i;
    int left_element = 2 * i + 1;
    int right_element = 2 * i + 2;

    if (left_element < n && edges[left_element].weight < edges[smallest].weight)
        smallest = left_element;

    if (right_element < n && edges[right_element].weight < edges[smallest].weight)
        smallest = right_element;

    if (smallest != i)
    {
        Edge temp = edges[smallest];
        edges[smallest] = edges[i];
        edges[i] = temp;
        heapify(edges, n, smallest);
    }
}

void EdgeHeap::heapSort(Edge edges[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(edges, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        Edge temp = edges[i];
        edges[i] = edges[0];
        edges[0] = temp;
        heapify(edges, i, 0);
    }
}