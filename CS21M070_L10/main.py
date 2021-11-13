#----------------------------------------------------------------------#
#  $Id$
#  File: main.py
#
#  Purpose: Uses variable length compression to generate efficient codes
#
#  Author: Varun Gumma 
#
#  Date: 08-10-2021
#
#  Bugs: NA
#
#  Change Log: <Date> <Author>
#              <Changes>
#
#----------------------------------------------------------------------#

from HuffManTreeADT import HuffManTree

#----------------------------------------------------------------------#
# GetMin -- finds the minimum probability node from the list and returns it and also removes it
# Input: list of nodes
# Output: node with minimum probability
# Bugs: NA
#----------------------------------------------------------------------#    
def GetMin(huff):
    minIndex, minProb = 0, 1.0    # initialize minIndex and minProb to find the minimum
    for i in range(len(huff)):   # iterate throught the list
        if huff[i].getProbability() < minProb: # if the current node has a lower probability that the previous min
            minProb = huff[i].getProbability()  # it becomes the current min
            minIndex = i    # update the minIndex as well
            
    node = huff.pop(minIndex) # retrieve the min and remove it from the list
    return node # return the node


# main code
characters = "abcdefghijklmnopqrstuvwxyz"   # keep a list of lower case characters to assign to nodes

N = int(input()) # read the number of nodes
huff = [] # initilize the list which will hold all the nodes

for i in range(N):
    prob = float(input()) 
    node = HuffManTree(characters[i], prob)  # create each node
    huff.append(node)   # and add it to the list
    
for i in range(1, N): # iterate N-1 times to build the full tree
    first = GetMin(huff)    # find the first minimum 
    leftNode = HuffManTree(first.getSymbol(), first.getProbability()) # and create a copy of it and set its parameters
    leftNode.setLeftTree(first.getLeftTree())
    leftNode.setRightTree(first.getRightTree())
    
    second = GetMin(huff)   # find the second minimum
    rightNode = HuffManTree(second.getSymbol(), second.getProbability())   # and create a copy of it as well and set its parameters
    rightNode.setLeftTree(second.getLeftTree())
    rightNode.setRightTree(second.getRightTree())
    
    prob = first.getProbability() + second.getProbability() # find the probability of their parent node
    parNode = HuffManTree('I', prob, leftNode, rightNode) # create the parent node and set its parameters 
    huff.append(parNode) # add it to the list to be accessed later
    
root = huff[0] # the only node in the list will be the root of the tree
root.printCodes([]) # call printCodes on the root to recursively print the codes