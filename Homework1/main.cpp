/*
 * Title: Algorithm Efficiency and Sorting
 * Author: EFE ACER
 * ID: 21602217
 * Section: 3
 * Assignment: 1
 * Description: The following source file contains a main method that
 *              calls the performanceAnalysis function of the sorting
 *              interface for 4 different array sizes.
 */

#include "sorting.h"

int main() {
    //Constants
    const int EXPERIMENT_SIZE1 = 1000;
    const int EXPERIMENT_SIZE2 = 6000;
    const int EXPERIMENT_SIZE3 = 12000;
    const int EXPERIMENT_SIZE4 = 18000;

    performanceAnalysis(EXPERIMENT_SIZE1);
    performanceAnalysis(EXPERIMENT_SIZE2);
    performanceAnalysis(EXPERIMENT_SIZE3);
    performanceAnalysis(EXPERIMENT_SIZE4);
    
    return 0;
}
