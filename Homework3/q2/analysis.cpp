/*
 * Title: Heaps and AVL Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 3
 * Description: This file contains the implementation of the global method rotationAnalysis that
 *              performs the experiment specified in the assignment.
 */

#include "analysis.h"
#include "AVLTree.h"
#include <iostream> //cout
#include <stdlib.h> //rand
#include <iomanip> //setw (table formatting)

using namespace std;

//Constants
const int EXPERIMENT_NUMBER = 10;
const int UNIT_ARRAY_SIZE = 1000;
const int INSERTION_RANGE = 100000;

void rotationAnalysis() { //global function to perform the experiment
    srand((int) time(NULL)); //initialize the random seed
    cout << left << setw(20) << "Tree Size" << setw(20) << "Random" << setw(20) << "Ascending" << setw(20) << "Descending";
    for (int i = 1; i <= EXPERIMENT_NUMBER; i++) {
        cout << endl << left << setw(20) << i * UNIT_ARRAY_SIZE;
        AVLTree randomTree;
        for (int j = 0; j < i * UNIT_ARRAY_SIZE; j++) {
            randomTree.insert(rand() % INSERTION_RANGE + 1);
        }
        cout << left << setw(20) << randomTree.getNumberOfRotations();
        AVLTree ascendingTree;
        for (int j = 1; j <= i * UNIT_ARRAY_SIZE; j++) {
            ascendingTree.insert(j);
        }
        cout << left << setw(20) << ascendingTree.getNumberOfRotations();
        AVLTree descendingTree;
        for (int j = i * UNIT_ARRAY_SIZE; j >= 1; j--) {
            descendingTree.insert(j);
        }
        cout << left << setw(20) << descendingTree.getNumberOfRotations();
    }
}
