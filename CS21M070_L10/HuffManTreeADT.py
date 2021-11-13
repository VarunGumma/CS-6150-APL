# ADT of huffman tree
class HuffManTree:
    
    # constructor
    def __init__(self, symbol=None, probability=None, lChild=None, rChild=None):
        self.symbol = symbol    # set all required parameters
        self.probability = probability
        self.lChild = lChild
        self.rChild = rChild
    
    # overload str method to print the class using 'print' 
    def __str__(self):
        return f"({self.symbol} | {self.probability})" # f-strings are faster and more efficient
        
    def getSymbol(self):
        return self.symbol

    def getProbability(self):
        return self.probability
    
    def setSymbol(self, symbol):
        self.symbol = symbol
    
    def setProbability(self, probability):
        self.probability = probability
        
    def setLeftTree(self, lChild):
        self.lChild = lChild
        
    def setRightTree(self, rChild):
        self.rChild = rChild
        
    def getLeftTree(self):
        return self.lChild

    def getRightTree(self):
        return self.rChild
    
    #---------------------------------------------------------------------------#
    # printCodes -- does a pre-order traversal to print the codes from the tree
    # Input: an auxillary stack to keep track of the path followed to reach a node
    # Output: NA, just prints the codes
    # Bugs: NA
    #---------------------------------------------------------------------------#
    def printCodes(self, auxStack):       
        if self.symbol != 'I':  # if we have hit a leaf node, not intermediate one
            print(self.symbol, end=' ')  # print the node content
            print(''.join(auxStack))   # print the stack which contains the path we have followed to reach here

        if self.lChild is not None: # if we are at an intermediate node, check if left subtree is present, if yes
            auxStack.append('1')    # push a 1 to the top of the stack to indicate going left
            self.lChild.printCodes(auxStack) # now recurse on the left substree
            temp = auxStack.pop()   # once back, pop the stack top
            
        if self.rChild is not None:     # if we are at an intermediate node, check if right subtree is present, if yes#
            auxStack.append('0') # push a 0 to the top of the stack to indicate going right
            self.rChild.printCodes(auxStack) # now recurse on the right substree
            temp = auxStack.pop()   # once back, pop the stack top