#pragma once
#define VERTICES 6
#define MAX_WEIGHT 100
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
    int source;
    int destination;
    int weight;
    Edge(int a, int b, int c);
};
class Graph
{
public:
    Node *nodes[5000];
    vector<Edge> edges; // TODO ASK
    void init();
    void generateGraph(int degree);
    void print();
    void addEdge(int source, int destination);
    bool isEdgePresent(int source, int destination);
};