#define VERTICES 10
#define MAX_WEIGHT 100
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
    void generateGraph(int degree);
    void print();
};