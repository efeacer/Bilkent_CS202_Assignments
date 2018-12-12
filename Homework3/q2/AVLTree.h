/*
 * Title: Heaps and AVL Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 3
 * Description: This header file contains the declerations of AVLTree class' public
 *              and private interface together with the struct representing an AVLNode.
 */

#include <stddef.h> //NULL

class AVLTree {
private: //the private interface
    //AVLNode is represented as a struct with 4 properties
    struct AVLNode {
        int value; //the value of the node's item
        int height; //the height of the node considering its position in the tree
        AVLNode* right; //a pointer to the right child of the node
        AVLNode* left; //a pointer to the left child of the node
        AVLNode(int value) { //a constructor for the node (it is initialized as a leaf by default)
            this->value = value;
            height = 1;
            right = NULL;
            left = NULL;
        }
    };
    
    //Properties
    AVLNode* root; //The AVLTree is referenced by a pointer to its root
    int numberOfRotations; //A variable holding the total number of rotations performed
    
    /*
     * A recursive method that inserts a value to its corresponding place in the AVLTree.
     * It traverses the tree from top to bottom to find the place of insertion, then it checks
     * for any imbalance in a node and fixes it with the correct type of rotations when the
     * recursion backtracks from bottom to top.
     * @param node The root node of the recursed subtree.
     * @param value The value to be inserted.
     */
    void insertHelper(AVLNode* &node, int value);
    
    /*
     * Performs a single right rotation on the node passed as the parameter uses pointer updates.
     * @param node The node that the rotation takes place on.
     */
    void singleRightRotation(AVLNode* &node);
    
    /*
     * Performs a single left rotation on the node passed as the parameter, uses pointer updates.
     * @param node The node that the rotation takes place on.
     */
    void singleLeftRotation(AVLNode* &node);
    
    /*
     * Performs a double left-right rotation on the node passed as the parameter, uses pointer updates.
     * @param node The node that the rotation takes place on.
     */
    void doubleLeftRightRotation(AVLNode* &node);
    
    /*
     * Performs a double right-left rotation on the node passed as the parameter, uses pointer updates.
     * @param node The node that the rotation takes place on.
     */
    void doubleRightLeftRotation(AVLNode* &node);
    
    /*
     * A recursive method that traverses the tree in post order freeing the memory occupied by the nodes.
     * @param node The root node of the recursed subtree.
     */
    void destroyAVLTree(AVLNode* &node);
    
    /*
     * Accessor method for a specified node of the AVLTree.
     * @param node The specific node whose height is requested.
     * @return The height of the specified node.
     */
    int getHeight(AVLNode* &node);
    
    /*
     * Returns the balance factor of the specified node of the AVLTree.
     * @param node The specific node whose balance factor is requested.
     * @return The balance factor of the specified node. (height(leftSubtree) - height(rightSubtree))
     */
    int getBalanceFactor(AVLNode* &node);
    
public: //the public interface
    /*
     * The default constructor of the AVLTree. Assigns root to NULL and rotationNumber to 0.
     */
    AVLTree();
    
    /*
     * The destructor of the AVLTree. Frees the memory occupied by the tree using destroyAVLTree method.
     */
    ~AVLTree();
    
    /*
     * Inserts a value to its correct place in the AVLTree, performs the needed rotations to keep
     * the tree balanced. Uses insertHelper method.
     * @param value The value to be inserted.
     */
    void insert(int value);
    
    /*
     * Accessor method to get the number of rotations performed in building the tree.
     */
    int getNumberOfRotations();
};
