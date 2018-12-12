/*
 * Title: Heaps and AVL Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 3
 * Description: This file contains the implementations of the methods declared in the AVLNode
 *              header file. The proper comments of the functions can be found in the header file.
 */

#include "AVLTree.h"
#include <algorithm> //max
#include <iostream> //cout

using namespace std;

AVLTree::AVLTree() { //the default constructor
    root = NULL;
    numberOfRotations = 0;
}

AVLTree::~AVLTree() { //the destructor to avoid a possible memory leak
    destroyAVLTree(root);
}

void AVLTree::destroyAVLTree(AVLNode* &node) { //frees all memory, traversing the tree in postorder
    if (node != NULL) {
        destroyAVLTree(node->left);
        destroyAVLTree(node->right);
        delete node;
        node = NULL;
    }
}

void AVLTree::insert(int value) {
    insertHelper(root, value);
}

int AVLTree::getNumberOfRotations() {
    return numberOfRotations;
}

void AVLTree::insertHelper(AVLNode* &node, int value) {
    if (node == NULL) {
        node = new AVLNode(value);
    } else { //the recursion backtracks from bottom to top naturally
        if (value < node->value) {
            insertHelper(node->left, value);
            if (getBalanceFactor(node) > 1) { //check for any imbalance
                if (value < node->left->value) { //perform rotations if necessary
                    singleRightRotation(node);
                    numberOfRotations++;
                } else {
                    doubleLeftRightRotation(node);
                    numberOfRotations += 2;
                }
            }
        } else {
            insertHelper(node->right, value);
            if (getBalanceFactor(node) < -1) {
                if (value >= node->right->value) {
                    singleLeftRotation(node);
                    numberOfRotations++;
                } else {
                    doubleRightLeftRotation(node);
                    numberOfRotations += 2;
                } 
            }
        }
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

int AVLTree::getHeight(AVLNode* &node) { //accessor for height
    if (node == NULL) { //the root of an empty subtree has a height of 0
        return 0;
    } else {
        return node->height;
    }
}

int AVLTree::getBalanceFactor(AVLNode* &node) {
    return getHeight(node->left) - getHeight(node->right);
}

void AVLTree::singleRightRotation(AVLNode* &node) {
    AVLNode* temp = node;
    node = node->left;
    temp->left = node->right;
    node->right = temp;
    temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right)); //height updates after rotation
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

void AVLTree::singleLeftRotation(AVLNode* &node) {
    AVLNode* temp = node;
    node = node->right;
    temp->right = node->left;
    node->left = temp;
    temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right)); //height updates after rotation
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

void AVLTree::doubleLeftRightRotation(AVLNode* &node) {
    singleLeftRotation(node->left);
    singleRightRotation(node); //no height updates needed, since updates are performed by the called methods
}

void AVLTree::doubleRightLeftRotation(AVLNode* &node) {
    singleRightRotation(node->right);
    singleLeftRotation(node); //no height updates needed, since updates are performed by the called methods
}



