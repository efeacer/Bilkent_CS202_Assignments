/*
 * Title: Algorithm Efficiency and Sorting
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 1
 * Description: The following source file implemts the methods declared
 *              in the sorting.h file. The formal comments of the functions
 *              can be found in the header file.
 */

#include <stdlib.h>  //rand
#include <iostream>  //cout
#include <iomanip>   //setw (table formatting)
#include <time.h>    //clock_t
#include "sorting.h" //sorting class' interface

using namespace std;

void selectionSort(int *arr, int size, int &compCount, int &moveCount) {
    for (int cursor = size; cursor > 1; cursor--) {
        swap(arr[findIndexOfSmallest(arr, cursor, compCount)], arr[cursor - 1], moveCount);
    } //finds the largest and performs swap for (n - 1) times
}

void mergeSort(int *arr, int size, int &compCount, int &moveCount) {
    mergeSort(arr, 0, size - 1, compCount, moveCount); //calling the helper function
}

void mergeSort(int array[], int first, int last, int &compCount, int &moveCount) {
    if (first < last) { //doing the work after recursion
        int mid = (first + last) / 2;
        mergeSort(array, first, mid, compCount, moveCount);
        mergeSort(array, mid + 1, last, compCount, moveCount);
        merge(array, first, mid, last, compCount, moveCount);
    }
}

void merge(int array[], int first, int mid, int last, int &compCount, int &moveCount) {
    int tempArray[last + 1];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first1;
    while ((first1 <= last1) && (first2 <= last2)) {
        if (array[first1] >= array[first2]) { //selecting from the first half
            tempArray[index] = array[first1];
            first1++;
        } else { //selecting from the second half
            tempArray[index] = array[first2];
            first2++;
        }
        compCount++;
        moveCount++;
        index++;
    }

    while (first1 <= last1) { //copying whats left in the first half
        tempArray[index] = array[first1];
        moveCount++;
        first1++;
        index++;
    }

    while (first2 <= last2) { //copying whats left in the second half
        tempArray[index] = array[first2];
        moveCount++;
        first2++;
        index++;
    }

    for (index = first; index <= last; index++) { //copying the auxilary array to the main one
        array[index] = tempArray[index];
        moveCount++;
    }
}

void quickSort(int *arr, int size, int &compCount, int &moveCount) {
    quickSort(arr, 0, size - 1, compCount, moveCount); //calling the helper function
}

void quickSort(int array[], int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;
    if (first < last) { //doing the work before the recursion
        partition(array, first, last, pivotIndex, compCount, moveCount);
        quickSort(array, first, pivotIndex - 1, compCount, moveCount);
        quickSort(array, pivotIndex + 1, last, compCount, moveCount);
    }
}

void partition(int array[], int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int pivot = array[first]; //Pivot index is conventionally chosen as the first item.
    moveCount++;
    int lastSublist1 = first; //First sublist is initially empty.
    int firstUnknown = first + 1; //All elements other than the pivot is an unknown at this point.

    while (firstUnknown <= last) {
        if (array[firstUnknown] > pivot) { //places the larger item to the first sublist
            lastSublist1++;
            swap(array[firstUnknown], array[lastSublist1], moveCount);
        }
        firstUnknown++;
        compCount++;
    }

    swap(array[first], array[lastSublist1], moveCount); //restores the position of the pivot item
    pivotIndex = lastSublist1;
}

void performanceAnalysis(int size) { //decomposes the problem using helper functions
    int arr1[size], arr2[size], arr3[size];
    cout << "Performance analysis for arrays of size " << size << endl;
    for (int i = 1; i <= 4; i++) {
        if (i == 1) {
            generateThreeRandomArrays(arr1, arr2, arr3, size);
        } else if (i == 2) {
            generateThreeSortedArrays(arr1, arr2, arr3, size, true);
        } else if (i == 3) {
            generateThreeSortedArrays(arr1, arr2, arr3, size, false);
        } else {
            generateThreeSpecialOrderedArrays(arr1, arr2, arr3, size);
        }
        generateTableHeader(i);
        for (int j = 1; j <= 3; j++) {
            if (j == 1) {
                generateTableRow(arr1, size, j);
            } else if (j == 2) {
                generateTableRow(arr2, size, j);
            } else {
                generateTableRow(arr3, size, j);
            }
        }
    }
    cout << endl;
}

void generateThreeRandomArrays(int array1[], int array2[], int array3[], int size) {
    srand((int) time(NULL));
    for (int i = 0; i < size; i++) { //three identical arrays of random integers are formed
        int randomNumber = rand() % size;
        array1[i] = randomNumber;
        array2[i] = randomNumber;
        array3[i] = randomNumber;
    }
}

void generateThreeSortedArrays(int array1[], int array2[], int array3[], int size, int ascending) {
    for (int i = 0; i < size; i++) {
        int item;
        if (ascending) {
            item = i;
        } else {
            item = size - i;
        }
        array1[i] = item;
        array2[i] = item;
        array3[i] = item;
    } //three identical arrays of ascending/descending order are formed
}

void generateThreeSpecialOrderedArrays(int array1[], int array2[], int array3[], int size) {
    int mid = size / 2;
    for (int i = 0; i < size; i++) {
        int item;
        if (i <= mid) {
            item = i;
        } else {
            item = size - i;
        }
        array1[i] = item;
        array2[i] = item;
        array3[i] = item;
    } //three half ascending half descending arrays are formed
}

void generateTableHeader(int option) {
    cout << "----------------------------------------------------------------------------" << endl;
    string arrayType;
    if (option == 1) {
        arrayType = "Random";
    } else if (option == 2) {
        arrayType = "Ascending";
    } else if (option == 3) {
        arrayType = "Descending";
    } else {
        arrayType = "Special-ordered";
    }
    cout << left << setw(26) << arrayType + " integers" << setw(20) << "Elapsed time(msec)"
    << setw(15) << "compCount" << setw(18) << "moveCount" << endl; //formatting the output
}

void generateTableRow(int array[], int size, int option) {
    clock_t timer; //counts the elapsed time
    string sortingType;
    int compCount = 0;
    int moveCount = 0;
    if (option == 1) {
        timer = clock();
        selectionSort(array, size, compCount, moveCount);
        timer = clock() - timer;
        sortingType = "Selection sort";
    } else if (option == 2) {
        timer = clock();
        mergeSort(array, size, compCount, moveCount);
        timer = clock() - timer;
        sortingType = "Merge sort";
    } else {
        timer = clock();
        quickSort(array, size, compCount, moveCount);
        timer = clock() - timer;
        sortingType = "Quick sort";
    }
    double timePassed = (double) timer * 1000 / CLOCKS_PER_SEC;
    cout << left << setw(26) << sortingType << setw(20) << (double) timePassed
    << setw(15) << compCount << setw(18) << moveCount << endl; //formatting the output
}

int findIndexOfSmallest(const int array[], int size, int &compCount) {
    int indexOfLargest = 0;
    for (int currentIndex = 1; currentIndex < size; currentIndex++) {
        if (array[currentIndex] < array[indexOfLargest]) { //checks for a smaller item
            indexOfLargest = currentIndex;
        }
        compCount++;
    }
    return indexOfLargest;
}

void swap(int &first, int &second, int &moveCount) { //swap using references
    int temp = first;
    first = second;
    second = temp;
    moveCount += 3;
}


