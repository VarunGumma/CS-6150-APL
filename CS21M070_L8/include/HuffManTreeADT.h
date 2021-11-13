#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

class HuffManTree 
{
    char symbol;
    float probability;
    HuffManTree *lChild, *rChild;
  
public:
    HuffManTree();
    HuffManTree(float prob, char letter);
    HuffManTree (float prob, char letter, HuffManTree *lChild, HuffManTree *rChild);

    void createBinaryTree(float prob, char letter);
    void makeBinaryTree(HuffManTree *ltree, HuffManTree *rtree);
    char getSymbol();
    float getProbability();
    void setSymbol(char sym);
    void setProbability(float prob);
    HuffManTree *getLeftTree();
    HuffManTree *getRightTree();
    void setLeftTree(HuffManTree *ltree);
    void setRightTree(HuffManTree *rtree);
    void printCodes(HuffManTree *tree);
};

#endif
