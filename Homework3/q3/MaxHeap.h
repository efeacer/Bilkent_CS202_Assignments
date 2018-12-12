/*
 * Title: Heaps and AVL Trees
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 3
 * Description: This header file declares the public and private interface of the
 *              MaxHeap class, which contains methods to manipulate the heap.
 */

//Constants
const int MAX_HEAP_SIZE = 1000; //can be changed for testing purposes
const int OFFER_FOR_SWAPS = 10;
const int OFFER_FOR_ALL = 20;

class MaxHeap {
public: //the public interface
    /*
     * Default constructor for the MaxHeap class, simply initializes the size to 0.
     */
    MaxHeap();
    
    /*
     * Checks whether the MaxHeap is empty or not, returns true if the heap is empty,
     * returns false otherwise. Basically checks for size equals zero.
     * @return true for an empty heap, false for a non-empty one.
     */
    bool isEmpty();
    
    /*
     * Checks whether the number of items in the MaxHeap reached MAX_HEAP_SIZE or not,
     * does that with a simple size comparison. Returns true if MAX_HEAP_SIZE is
     * reached, return false otherwise.
     * @return true for a full heap, false otherwise. (full in terms of allowed size)
     */
    bool isFull();
    
    /*
     * Inserts an item to the MaxHeap. The insertion starts by placing the new item to
     * the first available spot in the heap and continues by bubbling it up (trickle-up)
     * to its correct spot.
     * @param newItem A reference to the new item that will be inserted to the heap.
     */
    void heapInsert(int &newItem);
    
    /*
     * Deletes the root (largest item) of the MaxHeap. The deletion starts by swapping the
     * root with the last indexed leaf, then the root is deleted in the position of the last
     * indexed leaf and the new root is bubbled down (heapRebuild function is called for that).
     * @param rootItem A reference to the root item that will be saved after the deletion.
     */
    void heapDelete(int &rootItem);
    
    /*
     * Calls the permutationHelper function. The algorithm for the solution of tbe assignment
     * problem is implemented in the helper method and an explanation is commented on top of the
     * helper method's decleration.
     */
    void permutation();
    
private: //the private interface
    //properties
    int items[MAX_HEAP_SIZE];
    int size;
    
    /*
     * Swaps to items using their references.
     * @param first The item that will get swapped with the other (second).
     * @param second The item that will get swapped with the other (first).
     */
    void swap(int &first, int &second);
    
    /*
     * Given the index of a particular item in the MaxHeap, returns the index
     * of its parent.
     * @param child The index of the node, whose parent will be returned.
     * @return The index of the parent of the specified parameter node.
     */
    int getParent(int child);
    
    /*
     * Given the index of a particular item in the MaxHeap, returns the index
     * of its left child.
     * @param child The index of the node, whose left child will be returned.
     * @return The index of the left child of the specified parameter node.
     */
    int getLeftChild(int parent);
    
    /*
     * Given the index of a particular item in the MaxHeap, returns the index
     * of its right child.
     * @param child The index of the node, whose right child will be returned.
     * @return The index of the right child of the specified parameter node.
     */
    int getRightChild(int parent);
    
    /*
     * Starting from the root itself, applies the bubble down algorithm recursively
     * until the root is in its correct spot. At the end of a call to this method, a
     * semiheap becomes a proper heap.
     * @root The root index of the subtree, where the algorithm works on.
     */
    void heapRebuild(int root);
    
    /*
     * The bubble up algorithm that compares an item in the heap with its parent
     * and swaps it with its parent until it reaches its correct spot. This method
     * is being called by the permutationHelper, not the heapInsert, because it
     * additionaly counts for the number of swap operations performed.
     * @param index The index of the item that will be bubbled up.
     * @param swapCount A reference to the variable holding the number of swaps.
     */
    void bubbleUp(int index, int &swapCount);
    
    /**
     * Helper function that is called by the permutation function. The function selects
     * an item from the leaf nodes and recursively selects another item from the unselected
     * leaf nodes. In each level of recursion, a recursive call is generated for each of the
     * unselected leaf nodes. This way all permutations are safely covered. In the base case
     * of the recursion (there are no leaves to select), the bubble up function is called
     * for each leaf node. The swap count and permutation count are updated when necessary.
     * @param toPermute The heap to permute (pass by value is needed since the heap cahnges
     *                  in every swap)
     * @param cursor An integer indicating the selected item.
     * @param swapCount A reference to a variable holding the number of swaps.
     * @param permutationCount A reference to a variable holding the number of permutations.
     */
    void permutationHelper(MaxHeap toPermute, int cursor, int &swapCount, int &permutationCount);
    
};
