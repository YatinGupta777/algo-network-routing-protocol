#include <iostream>
#include "Graph.h"

using namespace std;
class Graph;

int main()
{
    Graph g;
    g.init();
    g.generateGraph();
    g.print();

    return 0;
}