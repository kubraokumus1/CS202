/**
* Title: AVL Trees
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 4
* Description: main function that counts the frequency of unique words in a text file.
*/

#include <iostream>
using namespace std;

#include <fstream>
#include "AVLTree.h"

int main(int argc, char **argv) {
    AVLTree tree;
    ifstream filename;
    filename.open(argv[1]);
    if(filename.is_open())
        tree.generateTree(filename);
    filename.close();

    ofstream wordFreqs("wordfreqs");
    tree.printWordFrequencies(wordFreqs);

    ofstream statistics("statistics");

    tree.printTotalWordCount(statistics);
    tree.printHeight(statistics);
    tree.printMostFrequent(statistics);
    tree.printLeastFrequent(statistics);
    tree.printStandartDeviation(statistics);
    statistics.close();

    return 0;
}
