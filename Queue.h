#pragma once
#include "Graph.h"

class CUSTOM_QUEUE
{
    int arr[VERTICES];
    int f_index;
    int r_index;

public:
    CUSTOM_QUEUE();
    void push(int x);
    void pop();
    int front();
    bool empty();
};