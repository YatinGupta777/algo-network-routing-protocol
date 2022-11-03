#include "Graph.h"
#include <iostream>
using namespace std;

Node::Node()
{
}

Node::Node(int a, int b)
{
    x = a;
    w = b;
}

void Graph::init()
{
    for (int i = 0; i < 5000; i++)
    {
        nodes[i] = Node(i, i);
        cout << nodes[i].x << " W: " << nodes[i].w << endl;
    }
}