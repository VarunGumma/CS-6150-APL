#ifndef GRAPH_H
#define GRAPH_H
typedef int NodeType;
typedef int WeightType;

/*-------------------------------------------------------------------------
 *  AdjNode: Data type for one node of adj list
 -------------------------------------------------------------------------*/
struct AdjNode 
{
    NodeType node;
    WeightType weight;
    struct AdjNode* next;
};

/*-------------------------------------------------------------------------
 *  AdjList: Data type for adj list
 -------------------------------------------------------------------------*/
struct AdjList
{
    struct AdjNode *head;
};

/*-------------------------------------------------------------------------
 *  Graph: Class for representing Graph
 -------------------------------------------------------------------------*/
class Graph
{
    int numVertex, numEdge;
    struct AdjList *adj;
    
    public:
        Graph(int numVertex)
        {
            Init(numVertex);
        }
     
        void Init(int numVertex);
        int getVertices();
        int getEdges();
        int first(NodeType v);
        int next(NodeType v, NodeType w);
        void setEdge(NodeType v1, NodeType v2, WeightType wt);
        void delEdge(NodeType v1, NodeType v2);
        bool isEdge(NodeType v1, NodeType v2);
        WeightType weight(NodeType v1, NodeType v2);
        struct AdjNode* getList(NodeType);
};

#endif