#include "lists.h"


LISTS::CLL::CLL(vector<tortoise> &t)
{
    animals = t; 
    list = new array<int,animals.size()>;
    list->fill(0);
    
    
}

LISTS::CLL::CLL(vector<hare> &h)
{
}

LISTS::CLL::CLL(vector<pigeon> &p)
{
}

LISTS::CLL::~CLL()
{
}

LISTS::CLL::build()
{
}

LISTS::CLL::obstacle1()
{ //wall with gap

    if (


}
LISTS::CLL::obstacle2()
{
}
LISTS::CLL::obstacle3()
{
}

LISTS::CLL::node(int count, int max);
{
    obstacle = rand() % 3;
    node_num = count;
    if (count == max)
        next == CLL::rear;
    else
        next = new node(++count,max);
}

