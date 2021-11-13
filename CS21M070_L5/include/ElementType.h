#ifndef ELEMENTTYPE_H
#define ELEMENTTYPE_H

typedef int elementType;
typedef int Position;
typedef struct CellType 
{
    elementType value;
    Position next;
}CellNode;

#endif