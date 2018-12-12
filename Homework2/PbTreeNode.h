/**
 * Title: Binary Search Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 2
 * Description: This header file declares the PbTreeNode class consting of a private
 *              interface only.
 */

class PbTreeNode {
private:
    /**
     * The default constructor for a PbTreeNode
     */
    PbTreeNode();
    
    /**
     * The constructor of the PbTreeNode with three parameters to initialize node's
     * item, the left pointer and the right pointer.
     * @param item The integer data that the node contains.
     * @param leftPtr The address of the node pointed by the left pointer of this node.
     * @param rightPtr The address of the node pointed by the right pointer of this node.
     */
    PbTreeNode(const int &item, PbTreeNode* leftPtr, PbTreeNode* rightPtr);
    
    //instance variables
    int item;
    PbTreeNode* leftPtr;
    PbTreeNode* rightPtr;
    
    //PbBST is rightfully a friend class, since it consists of PbTreeNodes
    friend class PbBST; //(as it is in the lecture slides)
};
