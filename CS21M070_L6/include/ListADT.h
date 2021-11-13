#ifndef LIST_ADT_H
#define LIST_ADT_H
#include "ElementType.h"

class List 
{
public:
    void insert(elementType x, Position p);
    void delItem(Position p);
    void makeNull();
    void printList();
    elementType retrieve (Position p);
    Position end();
    Position first();
    Position next(Position p);
    bool isEmpty();
private:
    Position lastNode;
    CellNode*  list;
};

#endif