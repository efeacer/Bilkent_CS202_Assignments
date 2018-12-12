/**
 * Title: Binary Search Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 2
 * Description: This header file declares the PbBST class consisting of a
 *              public and a private interface.
 */

#include "PbTreeNode.h"

class PbBST {
    
private: //The private interface, mostly helper functions
    //instance variable
    PbTreeNode* root; //every node in the PbBST can be accessed through a root pointer
    
    /**
     * Recursively, finds the correct place for the insertion of an item using comparisons.
     * Then places the item to its corresponding place.
     * @param treePtr A pointer to the tree that the item will get inserted to.
     * @param item A reference to the item that will be inserted.
     */
    void insertItem(PbTreeNode* &treePtr, const int &item);
    
    /**
     * Recursively searches for a key in the PbBST, deletes that key if it is found, does not
     * change anything if it is not found.
     * @param treePtr A pointer to the current subtree.
     * @param key The specific key to be deleted.
     */
    void deleteItem(PbTreeNode* &treePtr, const int key);
    
    /**
     * Deletes a specified node from the PbBST by manipulating the links between the nodes.
     * @param nodePtr A reference to the node to be deleted.
     */
    void deleteNodeItem(PbTreeNode* &nodePtr);
    
    /**
     * Accesses and saves the item in the inorder successor of a particular node. Then deletes that node.
     * @param nodePtr A reference to the pointer of the right child of the particular node.
     * @param item The reference to the variable, where the value of the inorder successor will be saved.
     */
    void processLeftmost(PbTreeNode* &nodePtr, int &item);
    
    /**
     * Recursively computes the height of the tree using the inductive reasoning that the height
     * of a empty tree is 0 and height of a non-empty tree is 1 + max(leftSubtreeHeight, rightSubtreeHeight).
     * The height is defined as the number of nodes in the longest path from the root to a leaf.
     * @param treePtr A pointer to the current subtree.
     * @return The height of the tree.
     */
    int getHeightHelper(PbTreeNode* &treePtr);
    
    /**
     * Counts the number of items in the PbBST in O(n) linear time complexity.
     * Traverses the list using inorder traversal, increments the itemCount in each visit.
     * @param treePtr A pointer to the current subtree.
     * @param itemCount Current number of items in the tree.
     */
    void countItems(PbTreeNode* &treePtr, int &itemCount);
    
    /**
     * Computes the sum of the middle indexted items in the PbBST in O(n) linear time complexity.
     * Traverses the list using inorder traversal. Increments the sum by the value of the current
     * item if the current item is indexed in the middle indexes (middle index(es) is (n / 2) for
     * an array of odd length n, (n / 2) - 1 and (n / 2) for an array of even length n)
     * @param treePtr A pointer to the current subtree.
     * @param currentPos The inorder position of the current node.
     * @param itemCount The number of items in the tree.
     * @param sum Current sum of the middle indexed items of the tree.
     */
    void medianOfBSTHelper(PbTreeNode* &treePtr, int &currentPos, int &itemCount, int &sum);
    
    /*
     * Traverses the tree using inorder traversal, prints the visited node if it is between the
     * interval [a, b]. The complexity of the method is O(log(n) + m), since it does not perform
     * any unnecessary visits. Meaning that if the current item is already smaller than a, the
     * method does not recurse to its left. Similarly, if the current item is already greater than
     * b, the method does not recurse to its right. Assumes a < b.
     * @param nodePtr A pointer to a node in the tree.
     * @param a The lower bound of the specified interval.
     * @param b The upper bound of the specified interval.
     */
    void rangeSearchHelper(PbTreeNode* &nodePtr, int a, int b);
    
    /**
     * Traverses the tree using postorder traversal, deletes the visited node. Thus, frees all
     * the memory occupied by the tree.
     * @param treePtr A pointer to the tree that will be freed in terms of memory.
     */
    void destroyTree(PbTreeNode* &treePtr);
    
public:
    /**
     * The default constructor for a PbBST.
     */
    PbBST();
    
    /**
     * The destructor of the PbBST class, uses the private destroyTree method under the hood to free the
     * occupied memory.
     */
    ~PbBST();
    
    /**
     * Inserts the given key to the PbBST. Uses the private insertItem method under the hood.
     * @param key The specified value for the item to be inserted.
     */
    void insert(int key);
    
    /**
     * Deletes the given key from the PbBST. Uses the private deleteItem, deleteNodeItem and processLefmost
     * methods.
     * @param key The specified value for the item to be deleted.
     */
    void deleteKey(int key);
    
    /**
     * Computes and returns the height of the PbBST using the private getHeightHelper method. Specifics are
     * commented in that private method.
     * @return The height of the tree.
     */
    int getHeight();
    
    /**
     * Computes and median of the items in the PbBST calling the private countItems and medianOfBSTHelper
     * methods seperately. Each method traverses the tree in inorder, complexity of O(n), so the overall
     * time complexity of this method becomes O(n).
     * @return The median of the items in the PbBST.
     */
    double medianOfBST();
    
    /**
     * Prints the items of the PbBST that are between the interval [a, b]. Uses the rangeSearchHelper
     * function. The specifics are commented in that private function.
     * @param a The lower bound of the interval.
     * @param b The upper bound of the interval.
     */
    void rangeSearch(int a, int b);
};
