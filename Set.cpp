#include "Set.h"
#include <iostream>

using namespace std;

MUF::MUF()
{
    for (int i = 0; i < VERTICES; i++)
    {
        rank[i] = -1;
        dad[i] = -1;
    }
}

void MUF::makeSet(int vertex)
{
    dad[vertex] = -1;
    rank[vertex] = 0;
}
void MUF::unionVertices(int v1, int v2)
{
    int r1 = find(v1);
    int r2 = find(v2);

    if (rank[r1] > rank[r2])
        dad[r2] = r1;
    else if (rank[r1] < rank[r2])
        dad[r1] = r2;
    else
    {
        dad[r1] = r2;
        rank[r2]++;
    }
}
int MUF::find(int vertex)
{
    int r = vertex;
    while (dad[r] != -1)
        r = dad[r];
    return r;
}