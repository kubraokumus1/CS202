/**
* Title: Heaps
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 3
* Description: heap implementation
*/

#include "heap.h"

Heap::Heap() {
    size = 0;
    numOfComparisons = 0;
}

Heap::~Heap() {
}

bool Heap::heapIsEmpty() const {
    return (size == 0);
}

void Heap::insert(const int newItem) {
    if (size >= MAX_HEAP)
        cout<< "HeapException: Heap full" <<endl;

    // Place the new item at the end of the heap
    items[size] = newItem;

    // Trickle new item up to its proper position
    int place = size;
    int parent = (place - 1)/2;
    while ( (place > 0) && (items[place] > items[parent]) ) {
        ++ numOfComparisons;
        //swap parent and the new item
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}

void Heap::heapRebuild(int root,int size) {
    int child = 2 * root + 1;    // index of root's left child, if any
    if (child < size) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;    // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < size) && (items[rightChild] > items[child])) {
            child = rightChild;    // index of larger child
            ++ numOfComparisons;
        }
        // If root’s item is smaller than larger child, swap values

        if (items[root] < items[child]) {
            ++ numOfComparisons;
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child,size);
        }
    }
}

int Heap::maximum() {
    return items[0];
}

int Heap::popMaximum() {
    int max;
    if (heapIsEmpty())
        cout<<"Heap empty"<<endl;
    else {
        max = maximum();
        items[0] = items[--size];
        heapRebuild(0,size);
    }
   return max;
}

int Heap::getsize() const {
    return size;
}

int Heap::getItem(int index)const {
    return items[index];
}

int Heap::getNumOfComparisons() const {
    return numOfComparisons;
}

ostream &operator<<(ostream &out, const Heap & h) {
    for (int i = 0; i < h.getsize() ; ++i) {
        out<< h.getItem(i) <<"  ";
    }
    return out;
}





