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

    cout << "Maximum bandwith path : ";

    for (int i = count; i >= 0; i--)
    {
        cout << path[i];
        if (i != 0)
            cout << " -> ";
    }
    cout << endl;
}

void printBandwidth(int dad[], int bwidth[], int source, int destination)
{
    int x = destination;
    int max_bwidth = INT_MAX;
    while (dad[x] != -1)
    {
        max_bwidth = min(max_bwidth, bwidth[x]);
        x = dad[x];
    }
    cout << "Max Bandwidth : " << max_bwidth << endl;
}
