#include "../include/GraphADT.h"
#include <climits>
using namespace std;

/************************************************************************************************************
 * Init -- Helper function for the constructor
 * Input: number of vertices
 * Returns: NA, just sets the number of vertices and initializes the array of linked lists
 * Bugs: NA
 ***********************************************************************************************************/
void Graph::Init(int numVertex)
{
    this -> numVertex = numVertex;  /*set the number of vertices*/
    adj = new AdjList[numVertex];   /*to keep it clean, initialize all pointers to null*/
    for(int i = 0; i < numVertex; i++)
        adj[i].head = nullptr;      /*use nullptr rather than NULL, as it is a recommended C++ std*/
}

/************************************************************************************************************
 * getVertices -- returns the number of vertices
 * Input: NA
 * Returns: number of vertices
 * Bugs: NA
 ***********************************************************************************************************/
int Graph::getVertices()
{
    return numVertex;
}

/************************************************************************************************************
 * getEdges -- returns the number of edges
 * Input: NA
 * Returns: number of edges
 * Bugs: NA
 ***********************************************************************************************************/
int Graph::getEdges()
{
    return numEdge;
}

NodeType Graph::first(NodeType v)
{
    return -1;
}

NodeType Graph::next(NodeType v, NodeType w)
{
    return -1;
}

/************************************************************************************************************
 * setEdge -- adds an undirected weighted edge to the graph and increments number of edges
 * Input: ID of vertex1, ID of vertex2, weight of the edge
 * Returns: NA, just adds v1 to the edge-list of v2 and v2 to the edge-list of v1 (inserts at the beginning)
 * Bugs: NA
 ***********************************************************************************************************/
void Graph::setEdge(NodeType v1, NodeType v2, WeightType wt)
{
    struct AdjNode *tuple = new AdjNode(); /*create a new AdjNode for v1*/
    tuple -> node = v1; /*set its parameters*/
    tuple -> weight = wt;
    tuple -> next = nullptr;
    if(adj[v2].head)    /*if the list of v2 is null, this node becomes the head*/
        tuple -> next = adj[v2].head;   /*else, point the 'next' of this node to the current head*/
    adj[v2].head = tuple;   /*now make the node the head of the list*/
    
    tuple = new AdjNode();  /*create a new AdjNode for v2*/
    tuple -> node = v2; /*set its parameters*/
    tuple -> weight = wt;
    tuple -> next = nullptr;
    if(adj[v1].head)    /*if the list of v1 is null, this node becomes the head*/
        tuple -> next = adj[v1].head;   /*else, point the 'next' of this node to the current head*/
    adj[v1].head = tuple;   /*now make the node the head of the list*/

    numEdge++;  /*increment number of edges*/
}

/************************************************************************************************************
 * delEdge -- deletes an undirected edge between two vertices
 * Input: ID of vertex1, ID of vertex2
 * Returns: NA, deletes v1 from edge-list of v2 and deletes v2 from edge-list of v1
 * Bugs: NA
 ***********************************************************************************************************/
void Graph::delEdge(NodeType v1, NodeType v2)
{
    struct AdjNode *ptrCurr = adj[v1].head -> next; /*keep a current pointer, the node pointing to this will be deleted at the end*/
    struct AdjNode *ptrPrev = adj[v1].head; /*keep a trailing pointer which helps with deletion*/
    if(ptrPrev -> node == v2)   /*if the node to be deleted is the head*/
        adj[v1].head = ptrCurr; /*make the next node the head and delete the previous head node*/
    else
    {
        while(ptrCurr -> node != v2)    /*or else, find the node to be deleted by linearly traversing*/
        {
            ptrPrev = ptrPrev -> next;  /*make sure the trailing pointer is right behind*/
            ptrCurr = ptrCurr -> next;  
        }
        ptrPrev -> next = ptrCurr -> next; /*to delete the node in question, point the 'next' of the trailing pointer to to its 'next-next'. This skips the node to the deleted and it is lost. This deleted v2 from edge-list of v1*/
    }
    
    ptrCurr = adj[v2].head -> next; /*repeat the same to delete v1 from the edge-list of v1*/
    ptrPrev = adj[v2].head;
    if(ptrPrev -> node == v1)
        adj[v2].head = ptrCurr;
    else
    {
        while(ptrCurr -> node != v1)
        {
            ptrPrev = ptrPrev -> next;
            ptrCurr = ptrCurr -> next;
        }
        ptrPrev -> next = ptrCurr -> next;
    }
}

/************************************************************************************************************
 * isEdge -- Checks if an edge exists between two vertices
 * Input: ID of vertex1, ID of vertex2
 * Returns: true, if an edge exists, else false
 * Bugs: NA
 ***********************************************************************************************************/
bool Graph::isEdge(NodeType v1, NodeType v2)
{
    struct AdjNode *headPtr = adj[v1].head; /*start from the head*/
    while(headPtr)  /*linearly traverse the edge-list till the end*/
    {
        if(headPtr -> node == v2)   /*if the vertex is found in the list*/
            return true;    /*if vertex is found, return true*/
        headPtr = headPtr -> next;
    }
    return false;   /*if this statement is reached, the required node was never found, hence return false*/
}


/************************************************************************************************************
 * weight -- finds weight of the edge between two vertices
 * Input: ID of vertex1, ID of vertex2
 * Returns: the weight of the required edge
 * Bugs: NA
 ***********************************************************************************************************/
WeightType Graph::weight(NodeType v1, NodeType v2)
{
    struct AdjNode *headPtr = adj[v1].head; /*start from the head*/
    while(headPtr)  /*linearly traverse the edge-list till the end*/
    {
        if(headPtr -> node == v2)   /*if the vertex is found in the list*/
            return headPtr -> weight; /*return the corresponding weight*/
        headPtr = headPtr -> next;
    }
    return INT_MAX; /*if this statement is reached, the required edge is not present in the graph, hence return a large value, preferably INT_MAX*/
}

/************************************************************************************************************
 * getList -- returns the adjacency list of a particular vertex
 * Input: ID of the vertex whose neighbors are required
 * Returns: pointer to the head of the adjacency list
 * Bugs: NA
 ***********************************************************************************************************/
struct AdjNode* Graph::getList(NodeType v)
{
    return adj[v].head;
}