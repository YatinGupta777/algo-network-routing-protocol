#pragma once
#include "Graph.h"

class MaxHeap
{
    int H[VERTICES];
    int D[VERTICES];
    int P[VERTICES];
    int last_element_index;

public:
    MaxHeap();
    void fixBottomUp(int current_node);
    void fixTopDown(int current_node);
    void swap(int x, int y);
    void insert(int vertex, int weight);
    void deleteElement(int vertex);
    int maximum();
    void print();
    int currentSize();
};

// Min Heap so that sort is descending order
class EdgeHeap
{
public:
    static void heapify(vector<Edge> &edges, int n, int i);
    static void heapSort(vector<Edge> &edges, int n);
};