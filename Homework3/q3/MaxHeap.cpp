/*
 * Title: Heaps and AVL Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 3
 * Description: This file contains the implementations of the MaxHeap class' public and
 *              private methods. Those method are properly commented on the header file
 *              of the MaxHeap class.
 */

#include "MaxHeap.h"
#include <iostream> //cout

using namespace std;

MaxHeap::MaxHeap() {
    size = 0; //the heap is empty by default
}

bool MaxHeap::isEmpty() {
    return size == 0; //size check for emptiness
}

bool MaxHeap::isFull() {
    return size == MAX_HEAP_SIZE; //size check for fullness
}

void MaxHeap::heapInsert(int &newItem) {
    if (isFull()) { //Insertion fails for a full heap
        cout << "Cannot insert: Reached the maximum number of items allowed in the heap." << endl;
        return;
    }
    int i = size;
    items[i] = newItem; //bubbling the inserted item up
    size++;
    while (i > 0 && items[getParent(i)] < items[i]) {
        swap(items[i], items[getParent(i)]);
        i = getParent(i);
    }
}

void MaxHeap::heapDelete(int &rootItem) {
    if (isEmpty()) { //Deletion fails for an empty heap
        cout << "Cannot delete: The heap is currently empty, there is nothing to delete." << endl;
        return;
    } else {
        size--; //delete the last node
        rootItem = items[0];
        swap(items[0], items[size]); //bubbling the new root down (using heapRebuild)
        heapRebuild(0);
    }
    
}

void MaxHeap::heapRebuild(int root) { //recursive implementation of the bubble down algorithm
    int leftChild = getLeftChild(root);
    int rightChild = getRightChild(root);
    int largest = root; //assumption;
    if (leftChild < size && items[leftChild] < items[largest]) {
        largest = leftChild;
    }
    if (rightChild < size && items[rightChild] < items[largest]) {
        largest = rightChild;
    }
    if (largest != root) { //find the largest of root and its children
        swap(items[root], items[largest]); //swap the largest item so that it is the new root
        heapRebuild(largest); //recurse for the swapped child
    }
}

int MaxHeap::getParent(int child) {
    return (child - 1) / 2; //parent's index
}

int MaxHeap::getLeftChild(int parent) {
    return parent * 2 + 1; //left child's index
}

int MaxHeap::getRightChild(int parent) {
    return parent * 2 + 2; //right child's index
}

void MaxHeap::swap(int &first, int &second) { //swap by reference
    int temp = first;
    first = second;
    second = temp;
}

void MaxHeap::bubbleUp(int index, int &swapCount) { //bubble up algorithm's implementation
    while (index > 0 && items[getParent(index)] < items[index]) {
        swap(items[index], items[getParent(index)]);
        swapCount++; //counts the number of swaps performed
        index = getParent(index);
    }
}

void MaxHeap::permutation() { //provides the solution to the assignment problem calling a helper
    int swapCount = 0;
    int permutationCount = 0;
    permutationHelper(*this, getParent(size - 1) + 1, swapCount, permutationCount);
    cout << "The total number of swaps is " << swapCount << "." << endl;
    double averageSwaps = swapCount / (double) permutationCount;
    cout << "The average number of swaps per permutation is " << averageSwaps << "." << endl;
    if (OFFER_FOR_SWAPS * averageSwaps > OFFER_FOR_ALL) {
        cout << "10 TL per swap is a better option." << endl;
    }
    cout << "Taking 20 TL is a better option." << endl;
}

void MaxHeap::permutationHelper(MaxHeap toPermute, int cursor, int &swapCount, int &permutationCount) {
    if (cursor >= toPermute.size - 1) {
        permutationCount++; //another permutation is completed 
        for (int i = getParent(toPermute.size - 1) + 1; i < toPermute.size; i++) {
            toPermute.bubbleUp(i, swapCount); //form a valid heap again (counting the number of swaps)
        }
    } else {
        for (int i = cursor; i < toPermute.size; i++) {
            swap(toPermute.items[cursor], toPermute.items[i]); //select
            permutationHelper(toPermute, cursor + 1, swapCount, permutationCount); //recursively permute
            swap(toPermute.items[cursor], toPermute.items[i]); //backtrack (de-select to restore the leaves)
        }
    }
}
