/**
* Title: AVL Trees
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 4
* Description: AVL tree header file
*/

#ifndef HW4_AVLTREE_H
#define HW4_AVLTREE_H

#include <iostream>
using namespace std;
#include <sstream>

class TreeNode { 	// a node in the tree
private:
    TreeNode() { }
    TreeNode(const string& nodeItem, int count = 1, TreeNode *left = NULL, TreeNode *right = NULL)
            : word(nodeItem), count(count),left(left), right(right){ }

    string word;   // a data item in the tree
    int count;      // count of the word in the node

    // pointers to children
    TreeNode *left;
    TreeNode *right;

    // friend class - can access private parts
    friend class AVLTree;
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void addWord( string word );
    void generateTree( ifstream &fileName);
    void printTotalWordCount(ofstream& statistics);
    void printHeight(ofstream& statistics);
    void printWordFrequencies(ofstream& statistics);
    void printMostFrequent (ofstream& statistics);
    void printLeastFrequent(ofstream& statistics);
    void printStandartDeviation(ofstream& statistics);


    //this function retrieves the node of the given word
    TreeNode* retrieveNode( const string word);
private:
// ...
    TreeNode * root;

    void destruct(TreeNode* rootPtr);
    TreeNode* find(TreeNode *& nodePtr,string word);
    void addWordHelper( TreeNode *& nodePtr, const string word );
    void printTotalWordCountHelper (TreeNode * root, int & totalCount);
    void printWordFrequenciesHelper(TreeNode * root, ofstream & wordfreqs);
    void findMostFrequent (TreeNode * root, TreeNode *&mostFrequent);
    void findLeastFrequent (TreeNode * root, TreeNode *&leastFrequent);

    //helper functions to calculate the standard deviation
    double calculateMean(int* arr, int N);
    double calculateVariance(int* arr, int mean, int N);
    void transferToArray(TreeNode * root, int * arr,int &index);

    //rotation functions
    void singleLeft(TreeNode*& n);
    void singleRight(TreeNode*& n);
    void doubleRightLeft(TreeNode*& n);
    void doubleLeftRight(TreeNode*& n);

    int height(TreeNode* node); //returns the height of the tree
    int max(int a,int b); // returns the maximum of the given integers
    bool balanced(TreeNode * root); //checks whether the tree is balanced or not

    bool equals(string s1, string s2);
};

#endif //HW4_AVLTREE_H
