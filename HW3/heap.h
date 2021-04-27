/**
* Title: Heaps
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 3
* Description: heap class
*/

#ifndef HOMEWORK3_HEAP_H
#define HOMEWORK3_HEAP_H

#include <iostream>
using namespace std;
const int MAX_HEAP = 100000;

class Heap {
public:
    Heap();		// default constructor
    ~Heap();    // destructor

    bool heapIsEmpty() const;
    void insert(const int newItem) ;
    int maximum();
    int popMaximum(); //deletes the root item(max) and returns it
    int getsize()const;
    int getItem(int index)const;
    void heapRebuild(int root,int size);
    int getNumOfComparisons()const;

private:
    int items [MAX_HEAP] ;	// array of heap items
    int  size;            	// number of heap items
    friend ostream& operator<<( ostream& out, const Heap& tree );
    int numOfComparisons;
};


#endif //HOMEWORK3_HEAP_H

