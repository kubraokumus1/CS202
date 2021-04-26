/**
* Title: Algorithm Efficiency and Sorting
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 1
* Description: Prototypes of Sorting Algorithms
*/
#ifndef HW1_SORTING_H
#define HW1_SORTING_H

void insertionSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );
void mergeSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );
void quickSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );

#endif //HW1_SORTING_H
