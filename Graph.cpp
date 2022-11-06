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
    next = NULL;
}

void Graph::init()
{
    for (int i = 0; i < VERTICES; i++)
    {
        nodes[i] = new Node(i, i);
        // cout << nodes[i]->x << " W: " << nodes[i]->w << endl;
    }
}

void Graph::generateGraph()
{
    // add cycle to ensure connectedness
    for (int i = 0; i < VERTICES; i++)
    {
        Node *neighbor = new Node(i + 1, i + 1);
        nodes[i]->next = neighbor;
    }
}

void Graph::print()
{
    for (int i = 0; i < VERTICES; i++)
    {
        cout << i << " -> ";
        Node *t = nodes[i]->next;
        while (t != NULL)
        {
            cout << t->x << " - ";
            t = t->next;
        }
        cout << endl;
    }
}