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

void Graph::generateSparseGraph()
{
    int degree[VERTICES] = {0};
    // add cycle to ensure connectedness
    for (int i = 0; i < VERTICES; i++)
    {
        addEdge(i, (i + 1) % VERTICES);
        degree[i]++;
        degree[(i + 1) % VERTICES]++;
    }

    // Perform VERTICES Number of retires on each vertex to find a random neighbor which has degree < 6
    for (int i = 0; i < VERTICES; i++)
    {
        int retries = VERTICES;
        for (int j = 0; j < retries; j++)
        {
            if (degree[i] == 6)
                break;
            int x = rand() % VERTICES;
            // To ensure one edge between 2 unique pair of vertices and respective degree == 6
            if (!isEdgePresent(i, x) && degree[i] < 6 && degree[x] < 6)
            {
                addEdge(i, x);
                degree[i]++;
                degree[x]++;
            }
        }
    }

    // Additional check to add vertices manually if their degree is still less than 6
    for (int i = 0; i < VERTICES; i++)
    {
        if (degree[i] < 6)
        {
            int diff = 6 - degree[i];
            for (int j = 0; j < diff; j++)
            {
                for (int k = i + 1; k < VERTICES; k++)
                {
                    if (!isEdgePresent(i, k) && degree[k] < 6)
                    {
                        addEdge(i, k);
                        degree[i]++;
                        degree[k]++;
                    }
                }
            }
        }
    }
}

void Graph::generateDenseGraph()
{
    // add cycle to ensure connectedness
    for (int i = 0; i < VERTICES; i++)
    {
        addEdge(i, (i + 1) % VERTICES);
    }

    for (int i = 0; i < VERTICES; i++)
    {
        int number_of_neighbors = (((VERTICES / 5) / 2) - 50) + rand() % 100;
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
    int number_of_edges = 0;
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
            number_of_edges++;
        }
        cout << endl;
    }
    cout << "Edges : " << number_of_edges << endl;
}