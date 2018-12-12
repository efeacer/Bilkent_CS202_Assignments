/**
 * Title: Binary Search Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 2
 * Description: This header file implements the private interface of the PbTreeNode class,
 *              which consists of constructors only. The formal comments of the interface
 *              can be found in the header file.
 */

#include "PbTreeNode.h"

PbTreeNode::PbTreeNode() {} //there is no initialization made in the default constructor

PbTreeNode::PbTreeNode(const int &item, PbTreeNode* leftPtr, PbTreeNode* rightPtr) {
    this->item = item; //item is set
    this->leftPtr = leftPtr; //left pointer is set
    this->rightPtr = rightPtr; //right pointer is set
}
