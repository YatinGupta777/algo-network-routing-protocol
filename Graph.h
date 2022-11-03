class Node
{
public:
    int x;
    int w;
    Node();
    Node(int a, int b);
};
class Graph
{
    Node nodes[5000];

public:
    void init();
};