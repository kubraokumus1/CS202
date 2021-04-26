/**
* Title: Algorithm Efficiency and Sorting
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 1
* Description: main function
*/
#include "sorting.h"
#include <iostream>
#include "time.h"
using namespace std;

int main() {
    unsigned long long compCount;
    unsigned long long moveCount;
    const int size = 32567;

    cout<< "WITH RANDOM INTEGERS" <<endl;
    int * arrIns = new int [size];
    int * arrM= new int [size];
    int * arrQ= new int [size];
    for (int j = 0; j < size; ++j) {
        arrIns[j] = rand() % size ;
        arrM [j] = arrIns[j];
        arrQ [j] =arrIns[j];
    }

    //insertion sort
    cout << "----Insertion Sort----"<<endl;
    double duration1;
    clock_t startTime1 = clock();
    insertionSort( arrIns, size,  compCount,  moveCount );
    // Compute the number of seconds that passed since the starting time
    duration1 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration1 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;


    cout << "----Merge Sort----" << endl;
    double duration2;
    clock_t startTime2 = clock();
    mergeSort( arrM, size,  compCount,  moveCount );
    // Compute the number of seconds that passed since the starting time
    duration2 = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration2 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;


    cout << "----Quick Sort----" << endl;
    double duration3;
    clock_t startTime3 = clock();
    quickSort( arrQ, size,  compCount,  moveCount );
    // Compute the number of seconds that passed since the starting time
    duration3 = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration3 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;

    cout<<endl;

    cout<< "WITH INTEGERS THAT ARE SORTED IN DESCENDING ORDER"<<endl;
    int * arrIns2 = new int [size];
    int * arrM2= new int [size];
    int * arrQ2= new int [size];
    //reverse the sorted array
    for (int j = size-1 ; j >=0; --j) {
        arrIns2[size - j - 1] = arrIns[j]; ;
        arrM2 [size - j - 1] = arrIns[j];
        arrQ2 [size - j - 1] =arrIns[j];
    }

    cout << "----Insertion Sort----"<<endl;
    double duration4;
    clock_t startTime4 = clock();
    insertionSort( arrIns2, size,  compCount,  moveCount );
    // Compute the number of seconds that passed since the starting time
    duration4 = 1000 * double( clock() - startTime4 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration4 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;


    cout << "----Merge Sort----" << endl;
    double duration5;
    clock_t startTime5 = clock();
    mergeSort( arrM2, size,  compCount,  moveCount );
    // Compute the number of seconds that passed since the starting time
    duration5 = 1000 * double( clock() - startTime5 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration5 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;


    cout << "----Quick Sort----" << endl;
    double duration6;
    clock_t startTime6 = clock();
    quickSort( arrQ2, size,  compCount,  moveCount );
    // Compute the number of seconds that passed since the starting time
    duration6 = 1000 * double( clock() - startTime6 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration6 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;

    cout<<endl;

    cout<<"WITH INTEGERS THAT ARE SORTED IN ASCENDING ORDER"<<endl;

    cout << "----Insertion Sort----"<<endl;
    double duration7;
    clock_t startTime7 = clock();
    for (int i = 0; i < 1000; ++i) { //to see the time less than 1 ms
        insertionSort( arrIns, size,  compCount,  moveCount );
    }
    // Compute the number of seconds that passed since the starting time
    duration7 = 1000 * double( clock() - startTime7 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration7 / 1000 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;


    cout << "----Merge Sort----" << endl;
    double duration8;
    clock_t startTime8 = clock();
    mergeSort( arrM, size,  compCount,  moveCount );
    // Compute the number of seconds that passed since the starting time
    duration8 = 1000 * double( clock() - startTime8 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration8 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;


    cout << "----Quick Sort----" << endl;
    double duration9;
    clock_t startTime9 = clock();
    quickSort( arrQ, size,  compCount,  moveCount );
    // Compute the number of seconds that passed since the starting time
    duration9 = 1000 * double( clock() - startTime9 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration9 << " milliseconds." << endl;
    cout << "compCount is " << compCount << endl;
    cout << "moveCount is " << moveCount << endl;


    delete []arrIns;
    delete []arrM;
    delete []arrQ;
    delete []arrIns2;
    delete []arrM2;
    delete []arrQ2;

}
