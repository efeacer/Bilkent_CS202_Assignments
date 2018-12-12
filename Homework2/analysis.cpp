/**
 * Title: Binary Search Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 2
 * Description: The following code implements the global heightAnalysis function, the formal
 *              comment of the function can be found in the header file.
 */

#include "PbBST.h"
#include <iostream> //cout
#include <stdlib.h> //rand
#include <iomanip> //setw (table formatting)

using namespace std;

//Constants
const int ARRAY_SIZE = 20000;
const int INSERTION_INTERVAL = 1000;

void heightAnalysis() {
    PbBST bst; //create a binary search tree as a method variable
    srand((int) time(NULL)); //initialize the random seed
    //create a random array of ARRAY_SIZE items
    int randomArray[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        randomArray[i] = rand();
    }
    //print the header for the first part
    cout << "\nPart d - Analysis of BST height - part 1" <<
            "\n-----------------------------------------\n" <<
            left << setw(20) << "TreeSize" << setw(20) << "TreeHeight" <<
            "\n-----------------------------------------\n";
    //insert array items to the binary search tree
    for (int i = 1; i <= ARRAY_SIZE; i++) {
        bst.insert(randomArray[i - 1]);
        if (i % INSERTION_INTERVAL == 0) { //display size and height
            cout << left << setw(20) << i << setw(20)<< bst.getHeight() << endl;
        }
    }
    //shuffle the array by swapping each item with a random indexed item up to its index
    for (int i = ARRAY_SIZE - 1; i > 0; i--) { //a common shuffle algorithm
        int randomIndex = rand() % (i + 1);
        int temp = randomArray[i];
        randomArray[i] = randomArray[randomIndex];
        randomArray[randomIndex] = temp;
    }
    //print the header for the second part
    cout << "\n\nPart d - Analysis of BST height - part 2" <<
            "\n-----------------------------------------\n" <<
            left << setw(20) << "TreeSize" << setw(20) << "TreeHeight" <<
            "\n-----------------------------------------\n";
    //delete array items from the binary search tree
    for (int i = 1; i <= ARRAY_SIZE; i++) {
        bst.deleteKey(randomArray[i - 1]);
        if (i % INSERTION_INTERVAL == 0) { //display size and height
            cout << left << setw(20) << ARRAY_SIZE - i << setw(20)<< bst.getHeight() << endl;
        }
    }
}

