/**
* Title: Algorithm Efficiency and Sorting
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 1
* Description: Source Code of Sorting Algorithms
*/

#include "sorting.h"

void insertionSort(int *arr, const int size, unsigned long long &compCount, unsigned long long &moveCount) {
    compCount = 0;
    moveCount = 0;
    int key;
    for (int j = 1; j < size; j ++) {
        ++compCount; // j < size
        ++moveCount; // for assigning j at each loop
        key = arr[j];
        int i = j - 1;
        moveCount += 2;

        for(;i >= 0 && arr[i] > key; i--) {
            compCount += 2;// i >= 0 && arr[i] > key
            arr[i + 1] = arr[i];
            ++moveCount;
            ++moveCount;// i--
        }
        compCount += 2; // i >= 0 && arr[i] > key
        arr[i + 1] = key;
        ++moveCount;
    }
    ++compCount; // j < size

}

void merge(int * arr, int first, int mid, int last,unsigned long long &compCount, unsigned long long &moveCount){
    int * temp = new int[last+1];

    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray
    moveCount  += 4;

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount += 2; //(first1 <= last1) && (first2 <= last2)
        ++moveCount; // for assigning index at each loop
        ++compCount; // if
        if (arr[first1] < arr[first2]) {
            temp[index] = arr[first1];
            ++first1;
            moveCount += 2;
        } else {
            temp[index] = arr[first2];
            ++first2;
            moveCount += 2;
        }
    }
    compCount += 2; //(first1 <= last1) && (first2 <= last2)

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index) {
        ++compCount; //first1 <= last1
        temp[index] = arr[first1];
        moveCount += 2; // ++first1, ++index
    }
    moveCount -= 2;
    ++compCount; //first1 <= last1

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        ++compCount;
        temp[index] = arr[first2];
        moveCount += 2;
    }
    moveCount -= 2;
    ++compCount;

    // copy the result back into the original array
    for (index = first; index <= last; ++index) {
        ++compCount;
        arr[index] = temp[index];
        moveCount += 2;
    }
    ++compCount;
    delete [] temp;
}

void mergeSortHelper(int * arr, int first, int last,unsigned long long &compCount, unsigned long long &moveCount){
    ++compCount;
    if (first < last){
        int mid = (first + last)/2;
        ++moveCount;

        mergeSortHelper(arr,first,mid,compCount, moveCount);

        mergeSortHelper(arr, mid+1, last,compCount, moveCount);

        merge(arr,first,mid,last, compCount ,moveCount);
    }
}
void mergeSort(int *arr, const int size, unsigned long long &compCount, unsigned long long &moveCount) {
    compCount = 0;
    moveCount = 0;
    mergeSortHelper(arr,0,size-1,compCount, moveCount);
}

void swap( int& x, int& y ) {
    int temp = x;
    x = y;
    y = temp;
}

void partition(int* arr,int first,int last, int &pivotIndex, unsigned long long &compCount, unsigned long long &moveCount){
    int pivot = arr[first];
    // initially, everything but pivot is in unknown
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown
    moveCount += 3;

    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown) {
        compCount += 2;
        // move item from unknown to proper region
        if (arr[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount += 4; // ++lastS1 and swap
        }	// else belongs to S2
    }
    ++compCount;
    // place pivot in proper position and mark its location
    swap(arr[first], arr[lastS1]);
    pivotIndex = lastS1;
    moveCount += 4;
}

void quickSortHelper(int * arr, int first, int last, unsigned long long &compCount, unsigned long long &moveCount){
    int pivotIndex;
    ++compCount;
    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex,compCount, moveCount);

        // sort regions S1 and S2
        quickSortHelper(arr, first, pivotIndex-1,compCount, moveCount);
        quickSortHelper(arr, pivotIndex+1, last,compCount, moveCount);
    }
}
void quickSort(int *arr, const int size, unsigned long long &compCount, unsigned long long &moveCount) {
    compCount = 0;
    moveCount = 0;
    quickSortHelper(arr,0,size-1,compCount, moveCount);
}





