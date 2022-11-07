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

Edge::Edge(int a, int b, int c)
{
    source = a;
    destination = b;
    weight = c;
}

void Graph::init()
{
    for (int i = 0; i < VERTICES; i++)
    {
        nodes[i] = new Node(i, 0);
    }
}

bool Graph::isEdgePresent(int source, int destination)
{
    Node *temp = nodes[source];
    while (temp != NULL)
    {
        if (temp->x == destination)
            return true;

        temp = temp->next;
    }
    return false;
}

void Graph::addEdge(int source, int destination)
{
    int weight = rand() % MAX_WEIGHT;
    Node *s = new Node(source, weight);
    Node *d = new Node(destination, weight);

    Node *temp = nodes[source];
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = d;

    temp = nodes[destination];

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = s;

    Edge e(source, destination, weight);
    edges.push_back(e);
}

void Graph::generateGraph(int degree)
{
    // add cycle to ensure connectedness
    for (int i = 0; i < VERTICES - 1; i++)
    {
        addEdge(i, i + 1);
    }
    addEdge(VERTICES - 1, 0);

    for (int i = 0; i < VERTICES; i++)
    {
        for (int j = 0; j < (degree) / 2; j++)
        {
            int x = rand() % VERTICES;

            // To ensure one edge between 2 unique pair of vertices
            if (!isEdgePresent(i, x))
            {
                addEdge(i, x);
            }
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
    cout << "Number of edges : " << edges.size() << endl;
}