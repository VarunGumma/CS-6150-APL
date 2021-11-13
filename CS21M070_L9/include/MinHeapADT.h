#ifndef MINHEAP_H
#define MINHEAP_H
typedef int NodeType;
typedef int WeightType;

class MinHeap
{
    public:
        /* Structure to store node of the heap*/
        struct HeapNode
        {
            NodeType node;
            WeightType dist;
        };

    private:
        int size;                  // No of nodes in heap currently
        int capacity;              // Max number of nodes that can be in heap
        int* position;             // Position of vertex in the heap
        struct HeapNode **heap;                             

    public:
        MinHeap(int);
        struct HeapNode* createHeapNode(NodeType node, WeightType dist);
        void swapHeapNode(struct HeapNode** a, struct HeapNode** b);
        void decreaseKey(NodeType, WeightType );
        void insert(NodeType node, WeightType dist);
        void minHeapify(int idx);
        struct HeapNode* deleteRoot();
        void printHeap();
        bool isEmpty();
        bool inHeap(NodeType v);     
};

#endif
