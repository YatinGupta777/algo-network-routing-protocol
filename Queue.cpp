#include "Queue.h"

CUSTOM_QUEUE::CUSTOM_QUEUE()
{
    f_index = 0;
    r_index = -1;
}

void CUSTOM_QUEUE::push(int x)
{
    r_index++;
    arr[r_index] = x;
}
void CUSTOM_QUEUE::pop()
{
    f_index++;
}
int CUSTOM_QUEUE::front()
{
    return arr[f_index];
}

bool CUSTOM_QUEUE::empty()
{
    return f_index > r_index;
}