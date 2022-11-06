#define VERTICES 5

class Node
{
public:
    int x;
    int w;
    Node *next;
    Node();
    Node(int a, int b);
};
class Graph
{
    Node *nodes[5000];

public:
    void init();
    void generateGraph();
    void print();
};