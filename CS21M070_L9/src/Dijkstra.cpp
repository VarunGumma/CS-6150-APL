#include "../include/GraphADT.h"
#include "../include/MinHeapADT.h"
#include <iostream>
#include <climits>
using namespace std;

/************************************************************************************************************
 * Dijkstra -- runs Dijkstra's SSSP (from source always as 0) to compute shortest paths in the give Graph
 * Input: Graph object
 * Returns: NA, just prints the shortest paths
 * Bugs: NA
 ***********************************************************************************************************/
void Dijkstra(Graph gph)
{
    int n = gph.getVertices(); /*count the number of vertices the graph*/
    WeightType distances[n]; /*make a distances array to store the shortest paths*/

    for(int i = 0; i < n; i++) /*initialize the distances to all vertices (expect source) as INT_MAX or INF*/
        distances[i] = ((i == 0) ? 0 : INT_MAX); /*make sure source has 0 distance*/
    
    MinHeap heap = MinHeap(2*n); /*initialize a minheap with a max capacity of twice the number or vertices*/
    heap.insert(0, 0); /*insert the source into the heap*/
    while(not heap.isEmpty()) /*loop till all nodes are processed or heap becomes empty*/
    {
        MinHeap::HeapNode* heapNode = heap.deleteRoot(); /*get the heap root, i.e. the vertex with minimum distance among the all the vertices to be analysed*/
        NodeType u = heapNode -> node; /*get its ID*/
        AdjNode* headPtr = gph.getList(u); /*get its neighbors (adj_list)*/
        
        while(headPtr) /*linearly traverse the list*/
        {
            NodeType v = headPtr -> node; /*get one neighbor vertex*/
            NodeType w = headPtr -> weight; /*and edge-weight to that vertex*/
            if(heap.inHeap(v)) /*if the required vertex is already in the heap, dont add it again*/
            {
                if(distances[u] + w < distances[v]) /*check if a shorter path of the vertex v is available now upon relaxation*/
                {
                    distances[v] = distances[u] + w; /*if yes, assign it the relaxed distance*/
                    heap.decreaseKey(v, distances[v]); /*alter its value in the heap as well*/
                }
            }
            else if(distances[v] == INT_MAX) /*if the heap is not the heap, that means either it has been completely relaxed or not yet touched. If it is already relaxed, don't relax it again, else add it to the heap with relaxed distance*/
            {
                distances[v] = distances[u] + w;
                heap.insert(v, distances[v]);
            }
            headPtr = headPtr -> next; /*increment the headPtr to analyse the next neighbor*/
        }
    }
    
    /*once this loop is done, it guaranteed all edges have been relaxed and the shortest paths have been computed, provided no negative weight edges are present. If negative weight edges are given, this loop may never terminate*/
    for(int i = 0; i < n; i++)
        cout << i << ' ' << distances[i] << '\n'; /*print the shortest paths of the all vertices from 0*/
    return;
}


/*driver program*/
int main()
{
    int n, m;
    cin >> n >> m; /*read the number of vertices and edges*/
    
    Graph gph = Graph(n); /*create the graph object*/
    
    for(int i = 0, u, v, w; i < m; i++) 
    {
        cin >> u >> v >> w; /*read the edges*/
        gph.setEdge(u, v, w);   /*add them to the graph*/
    }
    
    Dijkstra(gph); /*call Dijkstra function to compute all shortest paths in the graph from 0*/
    return 0;
}
