/**
* Title: Trees
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 2
* Description: Main class
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "NgramTree.h"
int main( int argc, char **argv ) {
    NgramTree tree;
    string fileName( argv[1] );
    int n = atoi( argv[2] );
    tree.generateTree( fileName, n );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") <<endl;
    // Before insertion of new n-grams
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    tree.addNgram( "samp" );
    tree.addNgram( "samp" );
    tree.addNgram( "zinc" );
    tree.addNgram( "aatt" );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") <<endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;


    //additional code
    cout<<endl;
    cout<<"------additional part-------"<<endl;
    tree.removeNgram("this");
    cout<<endl;
    cout << tree << endl;
    tree.removeNgram("this");
    cout<<endl;
    cout << tree << endl;

    int count ;
    tree.retrieveCount("samp",count);
    cout<< "the count of \"samp\" is " << count<<endl;

    tree.removeNode("zinc");
    tree.removeNode("text");
    tree.removeNode("mple");
    tree.removeNode("samp");
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") <<endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;

    tree.removeNode("hise");
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") <<endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    return 0;
}
