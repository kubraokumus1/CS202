/**
* Title: Trees
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 2
* Description: Source code of NgramTree
*/

#include "NgramTree.h"

NgramTree::NgramTree() {
    root = NULL;
}

NgramTree::~NgramTree() {
    destruct(root);
}

void NgramTree::destruct( TreeNode* rootPtr ) {
    if ( rootPtr != NULL ) {
        destruct( rootPtr->left );
        destruct( rootPtr->right );
        delete rootPtr;
    }
}

void NgramTree::generateTree(string fileName, int n) {
    for (int i = 0; i <= fileName.length()-n; ++i) {
        if (withoutSpace(fileName.substr(i,n)))
            addNgram(fileName.substr(i,n) );
    }
}

//checks wether a string has a space or not
bool NgramTree::withoutSpace(string s){
    for (int j = 0; j < s.length() ; ++j) {
        if(s[j] ==  ' ')
            return false;
    }
    return true;
}


void NgramTree::addNgram(string ngram) {
    addNgramHelper(root, ngram);
}

void NgramTree::addNgramHelper(TreeNode *& rootPtr, const string ngram) {
       if (rootPtr == NULL) {
           rootPtr = new TreeNode(ngram, 1, NULL, NULL);
       } else if (rootPtr->ngram < ngram)
           addNgramHelper(rootPtr->right, ngram);
       else if (rootPtr->ngram > ngram)
           addNgramHelper(rootPtr->left, ngram);
       else if (equals(rootPtr->ngram, ngram))
           rootPtr->count++;
}

//checks whether two strings are case insensitively equal or not
bool NgramTree::equals(string s1, string s2) {
    if (s1.length() == s2.length())
        for (int i = 0; i < s1.length(); ++i) {
            if (toupper(s1[i]) != toupper(s2[i]))
                return false;
        }
    else
        return false;
    return true;
}

int NgramTree::getTotalNgramCount() {
    int totalCount = 0;
    getTotalNgramCountHelper(root,totalCount);
    return totalCount;
}

void NgramTree::getTotalNgramCountHelper(TreeNode * root, int & totalCount) {
    if ( root != NULL ) {
        getTotalNgramCountHelper( root->left, totalCount );
        getTotalNgramCountHelper( root->right,totalCount );
        totalCount++;
    }
}

bool NgramTree::isComplete() {
    int totalNgramCount = getTotalNgramCount();
    return isCompleteHelper(root,0,totalNgramCount);
}

bool NgramTree::isCompleteHelper(TreeNode *root, int index, int totalNgramCount) {
    if (root == NULL)
        return true;

    // If the index of the TreeNode is more than the totalNgramCount, then tree is not complete
    if (index >= totalNgramCount)
        return false;

    if (isCompleteHelper(root->left, 2*index + 1, totalNgramCount) &&
            isCompleteHelper(root->right, 2*index + 2, totalNgramCount))
        return true;
}

bool NgramTree::isFull() {
    return isFullHelper(root);
}

bool NgramTree::isFullHelper(TreeNode *rootPtr) {
    if (rootPtr == NULL)
        return true;
    if (rootPtr->right == NULL && rootPtr->left == NULL)
        return true;
    if ((rootPtr->right) && (rootPtr->left))
        if (isFullHelper(rootPtr->right) && isFullHelper(rootPtr->left))
            return true;
    return false;
}

ostream &operator<<(ostream &out, const NgramTree& tree) {
    return tree.display(out);
}

ostream &NgramTree::display(ostream &out) const {
    displayHelper(out,root) ;
}

ostream &NgramTree::displayHelper(ostream & out, TreeNode * root) const {
    if ( root != NULL ) {
        displayHelper( out, root->left );
        out <<"\"" << root->ngram <<"\" appears " << root->count<< " time(s)" << endl;
        displayHelper( out, root->right );
    }
    return out;
}


//retrieves the number of a ngram in the tree
void NgramTree::retrieveCount(const string ngram,int & count) {
    retrieveHelper(root,ngram,count);
}
//
void NgramTree::retrieveHelper(TreeNode *&rootPtr, const string ngram,int & count) {
    if (rootPtr == NULL)
        count = 0;
    else if (ngram == rootPtr->ngram)
        count = rootPtr->count;
    else if (ngram < rootPtr->ngram)
        retrieveHelper(rootPtr->left, ngram, count);
    else
        retrieveHelper(rootPtr->right, ngram, count);
}

void NgramTree::removeNode(const string ngram) {
    removeHelper(root,ngram);
}
void NgramTree::removeHelper(TreeNode *&rootPtr, const string ngram) {
    if (rootPtr == NULL) // Empty tree
        cout<<"Delete failed"<<endl;
        // Position of deletion found
    else if (ngram == rootPtr->ngram) {
        deleteNodeItem(rootPtr);
        cout<< "the \""<< ngram<< "\" node has been deleted"<<endl;
    }

        // Else search for the deletion position
    else if (ngram < rootPtr->ngram)
        removeHelper(rootPtr->left, ngram);
    else
        removeHelper(rootPtr->right, ngram);
}

void NgramTree::deleteNodeItem(TreeNode *&nodePtr) {
    TreeNode *delPtr;
    string replacementItem;
    int replacementCount;

    // (1)  Test for a leaf
    if ( (nodePtr->left == NULL) && (nodePtr->right == NULL) ) {
        delete nodePtr;
        nodePtr = NULL;
    }

    // (2)  Test for no left child
    else if (nodePtr->left == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->right;
        delPtr->right = NULL;
        delete delPtr;
    }

    // (3)  Test for no right child
    else if (nodePtr->right == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->left;
        delPtr->left = NULL;
        delete delPtr;
    }

    // (4)  There are two children:
    //      Retrieve and delete the inorder successor
    else {
        processLeftmost(nodePtr->right, replacementItem, replacementCount);
        nodePtr->ngram = replacementItem;
        nodePtr->count = replacementCount;
    }

}

void NgramTree::processLeftmost(TreeNode *&nodePtr, string &treeItem, int & count) {
    if (nodePtr->left == NULL) {
        treeItem = nodePtr->ngram;
        count = nodePtr->count;
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->right;
        delPtr->right = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->left, treeItem,count);
}

void NgramTree::removeNgram(const string ngram) {
    int count;
    retrieveCount(ngram,count);
    if (count == 1)
        removeNode(ngram);
    else if(count>1) {
        ((find(root, ngram))->count)--;
        cout<< "One \""<< ngram << "\" has been removed" << endl;
    }
    else
        cout<<"There is no \""<<ngram<<"\" in the NgramTree"<<endl;
}

TreeNode *NgramTree::find(TreeNode *& nodePtr,string ngram)  {
    if (nodePtr== NULL)
        return NULL;
    else if ( nodePtr->ngram < ngram )
        return find( nodePtr->right, ngram);
    else if ( nodePtr->ngram > ngram )
        return find( nodePtr->left, ngram);
    else if (equals(nodePtr->ngram, ngram))
        return nodePtr;
}







