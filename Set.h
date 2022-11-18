#pragma once
#include "Graph.h"

class MUF
{
    int rank[VERTICES];
    int dad[VERTICES];

public:
    MUF();
    void makeSet(int vertex);
    void unionVertices(int r1, int r2);
    int find(int vertex);
};