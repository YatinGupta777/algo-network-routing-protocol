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
    void fix_bottom_up(int current_node);
    void insert(Node *g);
    void deleteElement();
    void maximum();
    void print();
};