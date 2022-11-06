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
        nodes[i] = new Node(i, 0);
    }
}

void Graph::generateGraph(int degree)
{
    // add cycle to ensure connectedness
    for (int i = 0; i < VERTICES; i++)
    {
        int w = rand() % MAX_WEIGHT;
        Node *neighbor = new Node(i + 1, w);
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
            int w = rand() % MAX_WEIGHT;

            // To ensure one edge between 2 unique pair of vertices
            if (visited[x] == 1)
            {
                j--;
                continue;
            }

            Node *t = nodes[i];

            while (t->next != NULL)
                t = t->next;

            Node *neighbor = new Node(x, w);
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
            cout << "(" << t->x << ": " << t->w << ")";
            if (t->next != NULL)
                cout << " - ";
            t = t->next;
        }
        cout << endl;
    }
}