#include "../include/HuffManTreeADT.h"
#include <iostream>
using namespace std;

HuffManTree::HuffManTree() {}

HuffManTree::HuffManTree(float prob, char letter)
{
    symbol = 'I';
    probability = 0;
    lChild = NULL;
    rChild = NULL;
}

HuffManTree::HuffManTree (float prob, char letter, HuffManTree *lChild, HuffManTree *rChild)
{
    probability = prob;
    symbol = letter;
    lChild = NULL;
    rChild = NULL;
}

void HuffManTree::createBinaryTree(float prob, char letter)
{
    symbol = letter;
    probability = prob;
}

char HuffManTree::getSymbol()
{
    return symbol;
}

float HuffManTree::getProbability()
{
    return probability;
}

void HuffManTree::setSymbol(char sym)
{
    symbol = sym;
}

void HuffManTree::setProbability(float prob)
{
    probability = prob;   
}

HuffManTree* HuffManTree::getLeftTree()
{
    return lChild;
}

HuffManTree* HuffManTree::getRightTree()
{
    return rChild;
}

void HuffManTree::setLeftTree(HuffManTree *ltree)
{
    lChild = ltree;
}

void HuffManTree::setRightTree(HuffManTree *rtree)
{
    rChild = rtree;
}

void HuffManTree::makeBinaryTree(HuffManTree *ltree, HuffManTree *rtree)
{
    setLeftTree(ltree);
    setRightTree(rtree);
}

/*********************************************************************
 * printCodes -- printes the formed binary tree in pre-order manner
 * Input: The subtree root as a pointer
 * Output: NA, just prints the tree in pre-order manner
 * Bugs: NA
 *********************************************************************/
void HuffManTree::printCodes(HuffManTree *tree)
{
    static char code[50];   /*Helps as a stack to keep track of movement, i.e. left or right*/
    static int index = 0;   /*Helps keep track of the stack top*/
    
    HuffManTree* left = tree -> getLeftTree();  /*Store the left subtree, right subtree pointers to access later*/
    HuffManTree* right = tree -> getRightTree();
    char data = tree -> getSymbol();    /*Store the character in the node to print later*/
    
    if(data != 'I') /*If the node is not an internal node, i.e. it is a leaf node*/
    {
        cout << data << ' ';    /*print the node character*/
        for(int i = 0; i < index; i++)
            cout << code[i];    /*print the stack which is in the form of an array, i.e. the path to get this leaf*/
        cout << '\n';
    }
    if(left)    /*if the left node is available*/
    {
        code[index++] = '1';    /*put a 1 on top of the stack*/
        printCodes(left);       /*and move to the left*/
        index--;                /*decrease the stack top, to pop-off the previous element*/
    }
    if(right)   /*if the right node is also available*/
    {
        code[index++] = '0';    /*put a 0 on top of the stack*/
        printCodes(right);      /*and move to the right*/
        index--;                /*decrease the stack top, to pop-off the previous element*/
    }
}