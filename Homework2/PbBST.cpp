/**
 * Title: Binary Search Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 2
 * Description: The following code implements the public and private
 *              interface of the PbBST class. The proper comments of the
 *              functions can be found in the header file.
 */

#include "PbBST.h"
#include <iostream> //cout
#include <algorithm> //max

using namespace std;

PbBST::PbBST() { //the default constructor initializes the root as null (empty tree)
    root = NULL;
}

PbBST::~PbBST() {
    destroyTree(root); //frees the memory occupied by the tree
}

void PbBST::destroyTree(PbTreeNode* &treePtr) {
    if (treePtr != NULL) { //recursively frees the memory occupied by each node
        destroyTree(treePtr->leftPtr);
        destroyTree(treePtr->rightPtr);
        delete treePtr;
        treePtr = NULL;
    }
}
void PbBST::insert(int key) {
    insertItem(root, key); //inserts an item with the given key to the PbBST
}

void PbBST::insertItem(PbTreeNode* &treePtr, const int &item) {
    if (treePtr == NULL) { //finds and insertes an item to its correct place
        treePtr = new PbTreeNode(item, NULL, NULL);
    } else if (item <= treePtr->item) {
        insertItem(treePtr->leftPtr, item);
    } else {
        insertItem(treePtr->rightPtr, item);
    }
}

void PbBST::deleteKey(int key) {
    deleteItem(root, key); //deletes an item with the given key
}

void PbBST::deleteItem(PbTreeNode* &treePtr, const int key) {
    if (treePtr != NULL) { //searches for the item to be deleted
        if (key == treePtr->item) {
            deleteNodeItem(treePtr); //calls deleteNodeItem if the key is found
        } else if (key < treePtr->item) {
            deleteItem(treePtr->leftPtr, key);
        } else {
            deleteItem(treePtr->rightPtr, key);
        }
    }
}

void PbBST::deleteNodeItem(PbTreeNode* &nodePtr) {
    if (nodePtr->leftPtr == NULL && nodePtr->rightPtr == NULL) {
        delete nodePtr; //simple delete (leaf node)
        nodePtr = NULL;
    } else if (nodePtr->rightPtr == NULL) {
        PbTreeNode* delPtr = nodePtr; //swap with the left child and delete
        nodePtr = nodePtr->leftPtr;
        delPtr->leftPtr = NULL;
        delete delPtr;
    } else if (nodePtr->leftPtr == NULL) {
        PbTreeNode* delPtr = nodePtr; //swap with the right child and delete
        nodePtr = nodePtr->rightPtr;
        delPtr->rightPtr = NULL;
        delete delPtr;
    } else {
        int replacementItem; //swap with the inorder successor and delete
        processLeftmost(nodePtr->rightPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

void PbBST::processLeftmost(PbTreeNode* &nodePtr, int &item) {
    if (nodePtr->leftPtr == NULL) { //save the value of the inorder successor
        item = nodePtr->item;
        deleteNodeItem(nodePtr);
    } else { //search for the inorder successor
        processLeftmost(nodePtr->leftPtr, item);
    }
}

int PbBST::getHeight() {
    return getHeightHelper(root); //get the height of the tree (call to helper)
}

int PbBST::getHeightHelper(PbTreeNode* &treePtr) {
    if (treePtr == NULL) { //empty tree has a height of 0
        return 0;
    } else { //get the height recursively
        return 1 + max(getHeightHelper(treePtr->leftPtr), getHeightHelper(treePtr->rightPtr));
    }
}

double PbBST::medianOfBST() {
    int itemCount = 0; //compute and return the meadian calling two helpers
    int currentPos = 0;
    int sum = 0;
    countItems(root, itemCount);
    medianOfBSTHelper(root, currentPos, itemCount, sum);
    if (itemCount % 2 == 0) {
        return (double) sum / 2.0;
    }
    return (double) sum;
}

void PbBST::countItems(PbTreeNode* &treePtr, int &itemCount) {
    if (treePtr != NULL) { //traverse each node and increment item count (inorder)
        countItems(treePtr->leftPtr, itemCount);
        itemCount++;
        countItems(treePtr->rightPtr, itemCount);
    }
}

void PbBST::medianOfBSTHelper(PbTreeNode* &treePtr, int &currentPos, int &itemCount, int &sum) {
    if (treePtr != NULL) { //traverse each node and increment sum if the node is in the middle index(es) (inorder)
        medianOfBSTHelper(treePtr->leftPtr, currentPos, itemCount, sum);
        sum += treePtr->item * ((currentPos == itemCount / 2) + (itemCount % 2 == 0) * (currentPos == (itemCount / 2) - 1));
        currentPos++;
        medianOfBSTHelper(treePtr->rightPtr, currentPos, itemCount, sum);
    }
}

void PbBST::rangeSearch(int a, int b) {
    rangeSearchHelper(root, a, b); //call to helper, prints items in the range [a, b]
}

void PbBST::rangeSearchHelper(PbTreeNode* &nodePtr, int a, int b) { //assume a < b
    if (nodePtr != NULL) {
        if (nodePtr->item >= a) { //if the item is smaller than a don't recurse, since
            rangeSearchHelper(nodePtr->leftPtr, a, b); //rightChild <= item is guaranteed
        }
        if (nodePtr->item >= a && nodePtr->item <= b) { //if the item is in [a, b], print
            cout << nodePtr->item << " ";
        }
        if (nodePtr->item <= b) { //if the item is greater than b don't recurse, since
            rangeSearchHelper(nodePtr->rightPtr, a, b); //rightChild > item is guaranteed
        }
    } //O(log(n) + m) complexity, since there are no unneccessary visits
}


