#include "../include/MinHeapADT.h"
#include <iostream>
#include <climits>
using namespace std;

/*Constructor*/
MinHeap::MinHeap(int cap)
{
    size = 0;   /*initialize the heap to 0 nodes*/
    capacity = cap + 1; /*keep capacity as cap + 1, as we add nodes from 1 instead of 0*/
    heap = new HeapNode* [capacity]; /*create the array to hold the pointers*/
}

/************************************************************************************************************
 * createHeapNode -- creates a heap node
 * Input: parameters for the node
 * Returns: poinnter to the created node
 * Bugs: NA
 * Complexity: O(1)
 ***********************************************************************************************************/
MinHeap::HeapNode* MinHeap::createHeapNode(NodeType node, WeightType dist)
{
    HeapNode* heapNode = new HeapNode(); /*create the node*/
    heapNode -> node = node;    /*set its parameters*/
    heapNode -> dist = dist;
    return heapNode;    /*return pointer to the node*/
}

/************************************************************************************************************
 * swapHeapNode -- swaps two heap node pointers
 * Input: pointers of pointers to the head nodes to be swapped (pass by reference)
 * Returns: NA, just swaps pointers to the two nodes
 * Bugs: NA
 * Complexity: O(1)
 ***********************************************************************************************************/
void MinHeap::swapHeapNode(struct HeapNode** a, struct HeapNode** b)
{
    struct HeapNode* c = *a; /*temporary variable to help in swap*/
    *a = *b;
    *b = c;
}

/************************************************************************************************************
 * decreaseKey -- decreases the dist-value of a particular node in the heap
 * Input: ID of the node whose value has to be decreased, new dist-value
 * Returns: NA, just decreases the dist-value
 * Bugs: NA
 * Complexity: O(n)
 ***********************************************************************************************************/
void MinHeap::decreaseKey(NodeType node, WeightType newDist)
{
    int i = 1;
    while(i <= size and heap[i] -> node != node) /*traverse the heap array to find the node whose ID is given*/
        i++;
    
    heap[i] -> dist = newDist; /*assign it the new dist-value*/
    while(i != 1 and heap[i] -> dist < heap[i/2] -> dist) /*as its value is decreased, it maybe elevated to a new level in the heap*/
    {
        swapHeapNode(heap+i, heap+(i/2)); /*if the pointer has not yet reached the top and the the current node has a larger value than its parent, swap it*/
        i /= 2; /*move to the parent and repeat incase a swap was made*/
    }
    /*if a node has index i, its left child has index 2i and right child has index 2i+1*/
}

/************************************************************************************************************
 * insert -- inserts a new node into the heap
 * Input: node ID and its weight
 * Returns: NA, adds the node to the heap
 * Bugs: NA
 * Complexity: O(log n)
 ***********************************************************************************************************/
void MinHeap::insert(NodeType node, WeightType dist)
{
    HeapNode* heapNode = createHeapNode(node, dist); /*create the node and get its pointer*/
    heap[++size] = heapNode;    /*at it at the end of the array (leftmost leaf of the binary heap tree)*/
    
    int i = size; /*here, bounds on the heap indices are 1 and size*/
    while(i != 1 and (heap[i] -> dist < heap[i/2] -> dist)) /*push it up till it reaches the right level*/
    {
        swapHeapNode(heap+i, heap+(i/2)); /*swap with parent if parent has a higher dist-value*/
        i /= 2; /*move to the parent and repeat incase a swap was made*/
    }
}

/************************************************************************************************************
 * minHeapify -- pushes down a node to its correct level, works opposite of insert
 * Input: index of the node to apply the algorithm
 * Returns: NA, pushes the node one level down and recurses
 * Bugs: NA
 * Complexity: O(log n)
 ***********************************************************************************************************/
void MinHeap::minHeapify(int idx)
{
    int minPos = idx; /*lets assume, current node is the minimum*/
    int left = 2*idx; /*get its left and right childern. Heap starts from 1 for us*/
    int right = 2*idx + 1;
    
    /*if a node is already at the last level, i.e. left and right are out of range, leave it*/
    if(left < size and (heap[left] -> dist < heap[minPos] -> dist)) /*find which out of the root, left and right children has the minimum value*/
        minPos = left;
    if(right < size and (heap[right] -> dist < heap[minPos] -> dist))
        minPos = right;
    if(minPos != idx) /*if the minimum node is not the root (our assumption)*/
    {
        swapHeapNode(heap+minPos, heap+idx); /*push the parent node level down and bring up the least child*/
        minHeapify(minPos); /*now recurse with the pushed down node at a new index*/
    }
}

/************************************************************************************************************
 * minHeapify -- pushes down a node to its correct level, works opposite of insert
 * Input: index of the node to apply the algorithm
 * Returns: NA, pushes the node one level down and recurses
 * Bugs: NA
 * Complexity: O(log n)
 ***********************************************************************************************************/
MinHeap::HeapNode* MinHeap::deleteRoot()
{
    HeapNode* minElement = heap[1]; /*heap[1] is the root and is the minimum, store it to return later*/
    heap[1] = heap[size--]; /*put the last heap node at the root*/
    minHeapify(1); /*use minheapify to sink it to it appropriate level and bring up the next minimum*/
    return minElement; /*return the previously stored minimum*/
}

/************************************************************************************************************
 * printHeap -- prints the heap, in a level-order fashion
 * Input: NA
 * Returns: NA, just prints the heap
 * Bugs: NA
 * Complexity: O(n)
 ***********************************************************************************************************/
void MinHeap::printHeap()
{
    for(int i = 1; i <= size; i++)
        cout << heap[i] -> node << ' ' << heap[i] -> dist << '\n'; /*traverse the array and print it*/
}

/************************************************************************************************************
 * printHeap -- prints the heap, in a level-order fashion
 * Input: NA
 * Returns: NA, just prints the heap
 * Bugs: NA
 * Complexity: O(n)
 ***********************************************************************************************************/
bool MinHeap::isEmpty()
{
    return (size == 0);
}

/************************************************************************************************************
 * inHeap -- finds if a particular node is present in the heap already
 * Input: ID of the node
 * Returns: true if it is present, else false
 * Bugs: NA
 * Complexity: O(n)
 ***********************************************************************************************************/
bool MinHeap::inHeap(NodeType v)
{
    for(int i = 1; i <= size; i++) /*traverse the whole array to find the node*/
        if(heap[i] -> node == v)
            return true; /*if found, return true*/
    return false; /*if not in the heap, return false*/
}