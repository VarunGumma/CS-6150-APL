#include "../include/ElementType.h"
#include "../include/ListADT.h"
#include <iostream>
using namespace std;

void List::makeNull() 
{
    list = new CellNode[101]; 
    lastNode = 0;
}

bool List::isEmpty()
{
    if(lastNode == 0)
        return true;
    return false;
}

void List::insert(elementType x, Position p) 
{
    int i;
    for (i = lastNode+1; i > p; i--)
        list[i] = list[i-1];
    list[p].value = x;
    lastNode++;
}

elementType List::retrieve(Position p) 
{
    return(list[p].value);
}

void List::printList() 
{
    Position p;
    p = 1;
    while (p <= lastNode) 
    {
        cout << list[p].value;
        p++;
    }
    cout << "\n";
}

Position List::end() 
{
    Position p;
    p = lastNode + 1;
    return (p);
}

void List::delItem(Position p) 
{
    int i;
    for (i = p; i < lastNode; i++)
        list[i] = list[i+1];
    lastNode = lastNode - 1;
}

Position List::first() 
{
    return (1);
}

Position List::next(Position p) 
{
    return (p+1);
}
