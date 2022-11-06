#pragma once
#include "Graph.h"

class Dijkstra
{
public:
    static bool isFringerPresent(int status[]);
    static int largestBandwidthFringer(int status[], int bwidth[]);
    static void maxBandwidthPath(Graph g, int source, int dest);
};