#pragma once
#include "Graph.h"

class MaxHeap
{
    int H[VERTICES];
    int D[VERTICES];
    int P[VERTICES];
    int current_size;

public:
    MaxHeap();
    void fixBottomUp(int current_node);
    void fixTopDown(int current_node);
    void swap(int x, int y);
    void insert(Node *g);
    void deleteElement(int vertex);
    int maximum();
    void print();
};