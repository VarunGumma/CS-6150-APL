/**************************************************************************
 *  $Id$
 *  File: HuffManTreeApplication.c
 *
 *  Purpose: Builds a variable length character code for the given set of lowercase characters
 *
 *  Author: Varun Gumma 
 *
 *  Date: 11-10-2021
 *
 *  Bugs: NA
 *
 *  Change Log:	<Date> <Author>
 *  		    <Changes>
 *
 **************************************************************************/

#include "../include/HuffManTreeADT.h"
#include <iostream>
using namespace std;

/*********************************************************************
 * GetMin -- finds the huffmantree node with minimum probability
 * Input: The array containing the huffmantree nodes and its length
 * Output: A copy of the huffmantree node with minimum probability
 * Bugs: NA
 *********************************************************************/
HuffManTree GetMin(HuffManTree huff[], int size)
{
    int minIndex = 0;   /*temporary variable to store the position where minimum index occurs*/
    float minProb = 1e5;    /*initialize minimum probability to a large number*/
    for(int i = 0; i < size; i++)
        if(huff[i].getProbability() < minProb) /*if the curr node has a lower probability, it becomes the curr min*/
        {
            minIndex = i;   /*update the minIndex and minProb variables accordingly*/
            minProb = huff[i].getProbability();
        }
    
    HuffManTree node = huff[minIndex];  /*make a copy of the minimum probability node so that it can be returned*/
    huff[minIndex].setProbability(1e5); /*set the probability of the minimum probability node to a very high value, as in a way to "delete" it. This high probability ensures it won't be selected as the minimum again*/
    return node;    /*return the copy*/
}

/*********************************************************************
 * main -- driver program for the code
 * Input: NA
 * Output: NA, just creates the huffman tree and prints it
 * Uses: GetMin to retrieve minimum probability node
 * Bugs: NA
 *********************************************************************/
int main() 
{
    HuffManTree huff[50];
  
    int num;
    int i;
    float prob[30];
  
    cin >> num;
 
    for (i = 0; i < num; i++) 
    {
        cin >> prob[i];
        huff[i].setProbability(prob[i]);
        huff[i].setSymbol((char)('a'+i));
        huff[i].setLeftTree(NULL);
        huff[i].setRightTree(NULL);
    }
    
    int size = num; /*initlialize size variable to number of array elements*/
    for(int i = 1; i < num; i++)    /*We need to find the mins and merge n-1 times, hence run the loop*/
    {
        /* the following code creates the tree and its structure in the heap but maintains the nodes 
         * (whose pointers point into the heap) in the array given for finding the minimum efficiently. 
         * The nodes in the heap are created as copies of the nodes in the array.
         */
        HuffManTree* leftNode = new HuffManTree();  /*create a node in the heap (copy of the min prob node)*/
        HuffManTree firstMin = GetMin(huff, size);  /*Find the min prob node*/
        leftNode -> setSymbol(firstMin.getSymbol()); /*Assign the values of the min prob to its copy*/
        leftNode -> setProbability(firstMin.getProbability());
        leftNode -> setLeftTree(firstMin.getLeftTree());
        leftNode -> setRightTree(firstMin.getRightTree());
        
        HuffManTree* rightNode = new HuffManTree(); /*create a node in the heap (copy of the second min prob node)*/
        HuffManTree secondMin = GetMin(huff, size); /*Find the second min prob node*/
        rightNode -> setSymbol(secondMin.getSymbol());  /*Assign the values of the min prob to its copy*/
        rightNode -> setProbability(secondMin.getProbability());
        rightNode -> setLeftTree(secondMin.getLeftTree());
        rightNode -> setRightTree(secondMin.getRightTree());
        
        float prob = firstMin.getProbability() + secondMin.getProbability(); /*prob of parent node will be sum of the probabilities of this left and right subtrees*/
        
        HuffManTree parNode = HuffManTree();    /*create the parent node for these two nodes*/
        parNode.createBinaryTree(prob, 'I');    /*mark it as an internal node and assign its probability*/
        parNode.makeBinaryTree(leftNode, rightNode); /*attach the left and right nodes appropriately*/
        huff[size++] = parNode; /*add the newly created parent node to the array to be retrieved when needed*/
    }

    HuffManTree* root = huff + size - 1;    /*the root node for this tree will be last element of the array*/
    root -> printCodes(root);   /*use preorder traversal to print the tree and codes*/

    return 0; /*end of main*/
}