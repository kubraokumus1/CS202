/**
* Title: Heaps
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 3
* Description: heapsort funtion: which take a heap and returns a sorted array
*              main function :  read input from an input file , and write sorted
*              output to an output file
*/

#include <iostream>
#include "fstream"
#include <sstream>
#include "heap.h"

using namespace std;

int * heapSort(Heap h, int n) {
    // create an initial array with the size of the heap
    int * sorted = new int [n];

    for (int last = n-1  ;last >= 0;  last--) {
        // take the max item in the heap and write it to the sorted array
        sorted[last] = h.popMaximum();
    }
    cout<< "Number of comparisons: " << h.getNumOfComparisons() << endl;
    return sorted;
}

int main(int argc, char **argv) {
    Heap h;
    string line;
    ifstream filename( argv[1] );
    int tmp;
    //insert each integer of the input file to the heap
    while(getline(filename,line)){
        istringstream(line) >> tmp;
        h.insert(tmp);
    }
    filename.close();
    cout<< "Number of data points: "<< h.getsize()<<endl;

    //create a new sorted array with heapsort function
    int * sorted = heapSort(h, h.getsize());

    // write the data in the sorted array in a new file.
    ofstream outputFile(argv[2]);
    for (int i = 0; i < h.getsize() ; ++i) {
        outputFile<< sorted[i]<<endl;
    }
    outputFile.close();

    delete [] sorted;
    return 0;
}


