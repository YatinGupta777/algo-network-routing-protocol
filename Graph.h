#pragma once
#define VERTICES 6
#define MAX_WEIGHT 100
#define MAX_EDGES (5000 * 5000)
#include <vector>

using namespace std;
class Node
{
public:
    int x;
    int w;
    Node *next;
    Node();
    Node(int a, int b);
};
class Edge
{
public:
    int v1;
    int v2;
    int weight;
    Edge();
    Edge(int a, int b, int c);
};
class Graph
{
public:
    Node *nodes[VERTICES];
    void init();
    void generateGraph(int degree);
    void print();
    void addEdge(int source, int destination, int weight);
    bool isEdgePresent(int source, int destination);
};