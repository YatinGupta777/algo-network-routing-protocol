#include "Graph.h"
#include <iostream>
using namespace std;

Node::Node()
{
}

Edge::Edge()
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
    v1 = a;
    v2 = b;
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

void Graph::addEdge(int source, int destination, int weight = rand() % MAX_WEIGHT)
{
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
        int number_of_neighbors = (degree) / 2;

        if (degree > 10)
        {
            // Average degree : 1000
            // number_of_neighbors between 950 to 1050
            number_of_neighbors = (number_of_neighbors - 50) + rand() % 100;
        }

        for (int j = 0; j < number_of_neighbors; j++)
        {
            int x = rand() % VERTICES;

            // To ensure one edge between 2 unique pair of vertices
            if (!isEdgePresent(i, x))
            {
                addEdge(i, x);
            }
            else
                j--;
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