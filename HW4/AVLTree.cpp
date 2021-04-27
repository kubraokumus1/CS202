/**
* Title: AVL Trees
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 4
* Description: AVL tree implementation
*/

#include "AVLTree.h"
#include <cmath>
#include <fstream>

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    destruct(root);
}

void AVLTree::destruct(TreeNode *rootPtr) {
    if ( rootPtr != NULL ) {
        destruct( rootPtr->left );
        destruct( rootPtr->right );
        delete rootPtr;
    }
}

void AVLTree::addWordHelper(TreeNode *&rootPtr, const string word) {
    if (rootPtr == NULL) {
        rootPtr = new TreeNode(word, 1, NULL, NULL);
    } else if (rootPtr->word < word)
        addWordHelper(rootPtr->right, word);
    else if (rootPtr->word > word)
        addWordHelper(rootPtr->left, word);
    else if (equals(rootPtr->word, word)) {
        rootPtr->count++;
    }

    if(!balanced(rootPtr)){
        //insertion into left child of rootPtr
        if(rootPtr->left && height(rootPtr->left)>height(rootPtr->right)) {
            //Insertion into left subtree of left child of rootPtr
            if (word < rootPtr->left->word) {
                singleRight(rootPtr);
            }
            //Insertion into right subtree of left child of rootPtr
            else if (word > rootPtr->left->word) {
                doubleLeftRight(rootPtr);
            }
        }
        //insertion into right child of rootPtr
        else if(rootPtr->right && height(rootPtr->right)>height(rootPtr->left) ) {
            // Insertion into left subtree of right child of rootPtr
            if (word < rootPtr->right->word) {
                doubleRightLeft(rootPtr);
            }
            //Insertion into right subtree of right child of rootPtr
            else if (word > rootPtr->right->word) {
                singleLeft(rootPtr);
            }
        }

    }
}

void AVLTree::addWord(string word) {
    addWordHelper(root, word);
}

bool AVLTree::balanced(TreeNode *root) {
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight-rightHeight) > 1) {
        return false;
    } else
        return true;
}

void AVLTree::generateTree(ifstream & filename) {
    char c;
    string word;
    while(filename.get(c)) {
        //if char c is not a punctuation or a space, add it to the word string
        if (!ispunct(c) && !isspace(c)) {
            c = tolower(c);
            word  = word + c;
        }
        else if (!word.empty() ){
            addWord(word);
            word = "";
        }
        if(filename.eof()) {
            break;
        }
    }
}

void AVLTree::printTotalWordCountHelper(TreeNode *root, int &totalCount) {
    if ( root != NULL ) {
        printTotalWordCountHelper( root->left, totalCount );
        printTotalWordCountHelper( root->right,totalCount );
        totalCount++;
    }
}

void AVLTree::printTotalWordCount(ofstream& statistics) {
    int totalCount = 0;
    printTotalWordCountHelper(root,totalCount);
    statistics<< "Total Word Count: "<< totalCount<< endl;
}


int AVLTree::height(TreeNode *node) {
    if(node == NULL)
        return 0;
    else
        return max(height(node->left),height(node->right)) + 1;
}

int AVLTree::max(int a, int b) {
    if( a < b)
        return b;
    else
        return a;
}

void AVLTree::printHeight(ofstream& statistics) {
    statistics<< "Tree Height: " << height(root)<<endl;
}

void AVLTree::printWordFrequencies(ofstream & wordfreqs) {
    printWordFrequenciesHelper(root , wordfreqs);
}

void AVLTree::printWordFrequenciesHelper(TreeNode * root, ofstream & wordfreqs) {
    if ( root != NULL ) {
        if(root->left)
            printWordFrequenciesHelper( root->left ,wordfreqs);
        wordfreqs<<root->word << " " << root->count <<endl;
        if(root->right)
            printWordFrequenciesHelper( root->right ,wordfreqs);
    }
}

void AVLTree::findMostFrequent(TreeNode *root, TreeNode*& mostFrequent) {
    if ( root != NULL ) {
        if(root->count > mostFrequent->count) {
            mostFrequent = root;
        }
        findMostFrequent( root->left,mostFrequent );
        findMostFrequent( root->right,mostFrequent );
    }
}

void AVLTree::printMostFrequent(ofstream& statistics) {
    TreeNode * mostFrequent = root;
    findMostFrequent(root,mostFrequent);
    statistics << "Most Frequent: ";
    statistics << mostFrequent->word;
    statistics << " ";
    statistics << mostFrequent->count;
    statistics <<endl;
}

void AVLTree::findLeastFrequent(TreeNode *root, TreeNode *&leastFrequent) {
    if ( root != NULL ) {
        if(root->count < leastFrequent->count) {
            leastFrequent = root;
        }
        findLeastFrequent( root->left,leastFrequent );
        findLeastFrequent( root->right,leastFrequent );
    }
}

void AVLTree::printLeastFrequent(ofstream& statistics) {
    TreeNode * leastFrequent = root;
    findLeastFrequent(root,leastFrequent);
    statistics<<"Least Frequent: " <<leastFrequent->word << " " <<leastFrequent->count <<endl;
}

void AVLTree::transferToArray(TreeNode *root, int *arr, int &index) {
   if(root != NULL) {
       arr[index] = root->count;
       index++;
       transferToArray(root->left, arr, index );
       transferToArray(root->right, arr, index );
   }
}

void AVLTree::printStandartDeviation(ofstream& statistics) {
    // find the size of the array
    int N = 0;
    printTotalWordCountHelper(root,N);

    // create the array with the counts of the AVLTree nodes
    int* array = new int [N];
    int index = 0;
    transferToArray(root, array, index);

    //find the average of the numbers
    double mean = calculateMean(array,N);

    //find the variance
    double variance = calculateVariance(array,mean,N);

    // standard deviation is the square root of the variance
    double sd = sqrt(variance);
    statistics<< "Standard deviation: "<< sd <<endl;

    delete [] array;
}

double AVLTree::calculateMean(int *arr, int N) {
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += arr[i];
    }
    double mean = sum / N;
    return mean;
}

double AVLTree::calculateVariance(int *arr, int mean, int N) {
    double sum = 0;
    for (int j = 0; j <N ; ++j) {
        sum += (arr[j]-mean)*(arr[j]-mean);
    }
    double variance = sum/N;
    return variance;
}


void AVLTree::singleLeft(TreeNode*& n) {
    TreeNode* p;
    p = n->right;
    n->right = p->left;
    p->left = n;
    n = p;
}

void AVLTree::singleRight(TreeNode *&n) {
    TreeNode* p;
    p = n->left;
    n->left = p->right;
    p->right = n;
    n = p;
}
void AVLTree::doubleRightLeft(TreeNode *&n) {
    singleRight(n->right);
    singleLeft(n);
}

void AVLTree::doubleLeftRight(TreeNode *&n) {
    singleLeft(n->left);
    singleRight(n);
}


bool AVLTree::equals(string s1, string s2) {
    if (s1.length() == s2.length())
        for (int i = 0; i < s1.length(); ++i) {
            if (toupper(s1[i]) != toupper(s2[i]))
                return false;
        }
    else
        return false;
    return true;
}

TreeNode *AVLTree::find(TreeNode *&nodePtr, string word) {
    if (nodePtr== NULL)
        return NULL;
    else if ( nodePtr->word < word )
        return find( nodePtr->right, word);
    else if ( nodePtr->word > word )
        return find( nodePtr->left, word);
    else if (equals(nodePtr->word, word))
        return nodePtr;
}

TreeNode *AVLTree::retrieveNode(const string word) {
    return find(root,word);
}




