/*
 * Title: Heaps and AVL Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 3
 * Description: This file contains a main method that reads a file in a certain
 *              format, constructs a max heap using the file contents and displays
 *              the solution of the assignment problem.
 */

#include "MaxHeap.h"
#include <iostream> //cout
#include <fstream> //read txt file

using namespace std;

int main() {
    MaxHeap maxHeap; 
    ifstream inFile("input.txt");
    if (!inFile) {
        cout << "Open failed: Cannot open input.txt" << endl; //if failed to open the file
    } else {
        int heapSize;
        inFile >> heapSize; //read heap size
        for (int i = 0; i < heapSize; i++) { //read heap size items
            int heapItem;
            inFile >> heapItem;
            maxHeap.heapInsert(heapItem);
        }
        inFile.close();
    }
    maxHeap.permutation(); //solve the assignment problem
    return 0;
}
