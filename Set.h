#pragma once
#include "Graph.h"

class MUF
{
    int rank[VERTICES];
    int dad[VERTICES];

public:
    MUF();
    void MakeSet(int vertex);
    void Union(int r1, int r2);
    int Find(int vertex);
};