/*
 * Title: Algorithm Efficiency and Sorting
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 1
 * Description: The following header file contains the interface of methods related with
 *              certain sorting algorithms.
 */

//The methods called by the user
    
/*
 * Sorts an array of integers in descending order using the Selection Sort
 * algorithm. The fundamental idea behind the implementation is to repeatedly
 * chose the smallest item on the list and put it in its place. The time
 * complexity of the algorithm is independent of the given data.
 * Best Case Behavior: O(n^2)
 * Worst Case Behavior: O(n^2)
 * Average Case Behavior: O(n^2)
 * @param arr The array of integers.
 * @param size The length of the given array.
 * @param compCount Reference to the comparison counter.
 * @param moveCount Reference to the item move counter.
 */
void selectionSort(int *arr, int size, int &compCount, int &moveCount);

/*
 * Sorts an array of integers in descending order using the Merge Sort algorithm.
 * The algorithm is based on recursively dividing the array into halves, sorting
 * each half and merging the sorted halves. The algorithm is very efficient in
 * terms of time but it requires extra space for auxilary arrays.
 * Best Case Behavior: O(n*log(n))
 * Worst Case Behavior: O(n*log(n))
 * Average Case Behavior: O(n*log(n))
 * @param arr The array of integers.
 * @param size The length of the given array.
 * @param compCount Reference to the comparison counter.
 * @param moveCount Reference to the item move counter.
 */
void mergeSort(int *arr, int size, int &compCount, int &moveCount);
    
/*
 * Sorts an array of integers in descending order using the Quick Sort algorithm.
 * The algorithm is based on recursively partioning the array about a pivot item
 * and then sorting each partitioned sublist. Selection of the pivot may result in
 * different behavior in terms of time.
 * Best Case Behavior: O(n*log(n))
 * Worst Case Behavior: O(n^2)
 * Average Case Behavior: O(n*log(n))
 * @param arr The array of integers.
 * @param size The length of the given array.
 * @param compCount Reference to the comparison counter.
 * @param moveCount Reference to the item move counter.
 */
void quickSort(int *arr, int size, int &compCount, int &moveCount);
    
/*
 * Generates three identical arrays of the given size in four different ways. Firstly,
 * generates arrays with random integers. Secondly, generates arrays with items in
 * ascending order. Thirdly, generates arrays with items in descending order. Lastly,
 * generates arrays with items in ascending order up to its half size and descending
 * order in the rest. Executes the Selection Sort, Merge Sort, Quick Sort for all
 * generated arrays, then displays the elapsed time, comparison count and item move count
 * in a printed table.
 * @param size The length of the arrays.
 */
void performanceAnalysis(int size);
    
//The helper methods:
    
/*
 * A helper function that sequentially searches for the smallest item in an array and
 * returns its index. The method is called by selectionSort function of the public
 * interface
 * @param array The array of integers.
 * @param size The length of the given array.
 * @param compCount Reference to the comparison counter.
 */
int findIndexOfSmallest(const int array[], int size, int &compCount);
    
/* A helper function that swaps two variables using their references. The function is
 * used in the selectionSort and quickSort functions.
 * @param first Reference to the first variable that will be swapped.
 * @param second Reference to the second variable that will be swapped.
 * @param moveCount Reference to the item move counter.
 */
void swap(int &first, int &second, int &moveCount);
    
/*
 * A helper function implementing the Merge Sort algorithm. It is called by the
 * mergeSort function of the public interface.
 * @param array The array of integers.
 * @param first The index of the first item in the array.
 * @param last The index of the last item in the array.
 * @param compCount Reference to the comparison counter.
 * @param moveCount Reference to the item move counter.
 */
void mergeSort(int array[], int first, int last, int &compCount, int &moveCount);
    
/*
 * A helper function implementing the Merge operation, which combines two sorted
 * halves of an array into a single array that maintains the order.
 * @param array The array of integers.
 * @param first The beginning index of the first half of the array.
 * @param mid The end index of the first half of the array. The second half begins
 *            right after this index.
 * @param last The end index of the second half.
 * @param compCount Reference to the comparison counter.
 * @param moveCount Reference to the item move counter.
 */
void merge(int array[], int first, int mid, int last, int &compCount, int &moveCount);
    
/*
 * A helper function implementing the Quick Sort algorithm. It is called by the
 * quickSort function of the public interface.
 * @param array The array of integers.
 * @param first The index of the first item in the array.
 * @param last The index of the last item in the array.
 * @param compCount Reference to the comparison counter.
 * @param moveCount Reference to the item move counter.
 */
void quickSort(int array[], int first, int last, int &compCount, int &moveCount);
    
/*
 * A helper function implementing the Partition operation, which groups an array
 * into two parts in a way that one half is greater than a pivot item and the other
 * half is smaller than or equal to. The pivot item is conventionally chosen as the
 * first item and it is placed in its proper position at the end of the operation.
 * @param array The array of integers.
 * @param first The index of the first item in the array.
 * @param last The index of the last item in the array.
 * @param pivotIndex Reference to the index of the pivot item.
 * @param compCount Reference to the comparison counter.
 * @param moveCount Reference to the item move counter.
 */
void partition(int array[], int first, int last, int &pivotIndex, int &compCount, int &moveCount);
    
/*
 * Generates three identical arrays with random integer values. The size of these arrays
 * are specified as an argument. Serves as a helper function for the performanceAnalysis
 * function of the public interface.
 * @param array1 One of three identical arrays.
 * @param array2 One of three identical arrays.
 * @param array3 One of three identical arrays.
 * @param size The length of the array.
 */
void generateThreeRandomArrays(int array1[], int array2[], int array3[], int size);
    
/*
 * Generates three identical arrays with sorted items. The size of these arrays
 * are specified as an argument. The order of the sorting is determined by a
 * boolean parameter named ascending. The order of the items is ascending when the
 * parameter is true and descending otherwise. Serves as a helper function for the
 * performanceAnalysis function of the public interface.
 * @param array1 One of three identical arrays.
 * @param array2 One of three identical arrays.
 * @param array3 One of three identical arrays.
 * @param size The length of the array.
 * @param ascending The boolean parameter determining the sorting order.
 */
void generateThreeSortedArrays(int array1[], int array2[], int array3[], int size, int ascending);
    
/*
 * Generates three identical arrays with ascending items up to its half size and
 * descending items in the rest. The size of these arrays are specified as an argument.
 * Serves as a helper function for the performanceAnalysis function of the public interface.
 * @param array1 One of three identical arrays.
 * @param array2 One of three identical arrays.
 * @param array3 One of three identical arrays.
 * @param size The length of the array.
 */
void generateThreeSpecialOrderedArrays(int array1[], int array2[], int array3[], int size);
    
/*
 * Prints a descriptive header for the table displayed by the performanceAnalysis
 * function. The option argument informs the method about the ordering of the array.
 * @param option A parameter that informs the method about the ordering of the array.
 */
void generateTableHeader(int option);
    
/*
 * Prints a row for the table displayed by the performanceAnalysis function. The row contains
 * the elapsed time, comparison count and the item move count belonging to a specific algorithm
 * sorting a specific algorithm. The option argument tells the method which algorithm to use.
 * @param array The array of integers.
 * @param size The length of the given array.
 * @param option A parameter that tells the method which algorithm to use.
 */
void generateTableRow(int array[], int size, int option);

