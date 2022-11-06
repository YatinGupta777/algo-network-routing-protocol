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
    }
}

void Graph::generateGraph(int degree)
{
    // add cycle to ensure connectedness
    for (int i = 0; i < VERTICES; i++)
    {
        Node *neighbor = new Node(i + 1, i + 1);
        nodes[i]->next = neighbor;
    }
    Node *first_vertex = new Node(0, 0);
    nodes[VERTICES - 1]->next = first_vertex;

    for (int i = 0; i < VERTICES; i++)
    {
        int visited[VERTICES] = {0};
        visited[i] = 1; // To ensure no self loops
        for (int j = 0; j < degree - 1; j++)
        {
            int x = rand() % VERTICES;

            // To ensure one edge between 2 unique pair of vertices
            if (visited[x] == 1)
            {
                j--;
                continue;
            }

            Node *t = nodes[i];

            while (t->next != NULL)
                t = t->next;

            Node *neighbor = new Node(x, x);
            t->next = neighbor;

            visited[x] = 1;
        }
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
            cout << t->x;
            if (t->next != NULL)
                cout << " - ";
            t = t->next;
        }
        cout << endl;
    }
}