/**
 * Title: Binary Search Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 2
 * Description: This piece of code creates a binary search tree, tests certain public
 *              interface methods and calls the glabal height analysis function to
 *              demonstrate the relation between the size and the height of the tree.
 */

#include "PbBST.h"
#include "analysis.h"
#include <iostream>

using namespace std;

int main() {
    const int EXPERIMENT_ARR[10] = {40, 50, 45, 30, 60, 55, 20, 35, 10, 25}; //the constants experiment array
    PbBST bst; //create a binary search tree for test purposes
    cout << "Inserting items..."; //insert items of the experiment array to the tree
    for (int i = 0; i < 10; i++) {
        bst.insert(EXPERIMENT_ARR[i]);
    }
    cout << "... insertion done." << endl;
    cout << "Height of the tree: " << bst.getHeight() << endl; //print tree's height
    cout << "Deleting items..."; //delete certain items from the tree
    bst.deleteKey(45);
    bst.deleteKey(50);
    cout << "... deletion done." << endl;
    cout << "Median of the BST: " << bst.medianOfBST() << endl; //find and display the median of tree items
    cout << "Numbers between 15 and 53: "; //print numbers between 15 and 53 using rangeSearch method
    bst.rangeSearch(15, 53);
    cout << endl;
    heightAnalysis(); //call the global heightAnalysis function
    return 0;
}
