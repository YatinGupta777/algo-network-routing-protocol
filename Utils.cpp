#include <iostream>
#include "Graph.h"

using namespace std;

void printPath(int dad[], int source, int destination)
{
    int path[VERTICES];
    int x = destination;
    int count = 0;
    while (dad[x] != -1)
    {
        path[count] = x;
        x = dad[x];
        count++;
    }
    path[count] = source;
    for (int i = count; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
            cout << " -> ";
    }
    cout << endl;
}