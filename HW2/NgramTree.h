/**
* Title: Trees
* Author: Kübra Okumuş
* ID: 21600980
* Assignment: 2
* Description: TreeNode and NgramTree classes
*/


#ifndef HW2_NGRAMTREE_H
#define HW2_NGRAMTREE_H

#include <iostream>
using namespace std;

class TreeNode { 	// a node in the tree
private:
    TreeNode() { }
    TreeNode(const string& nodeItem, int count = 1, TreeNode *left = NULL, TreeNode *right = NULL)
            : ngram(nodeItem), count(count),left(left), right(right){ }


    string ngram;   // a data item in the tree
    int count;      // count of the ngram in the node

    // pointers to children
    TreeNode *left;
    TreeNode *right;

    // friend class - can access private parts
    friend class NgramTree;
};

class NgramTree {
public:
    NgramTree();
    ~NgramTree();
    void addNgram( string ngram );
    int getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree( string fileName, int n );


    //this function retrieves the count of the given ngram
    void retrieveCount( const string ngram,int & count );

   /*  this function removes a ngram,
    it decreases the count of the ngram if it is more than 1
    else it deletes the node*/
    void removeNgram(const string ngram);

    //this function removes the node with the node item "ngram"
    void removeNode( const string ngram );

private:
// ...
    TreeNode * root;

    void destruct(TreeNode* rootPtr);
    TreeNode* find(TreeNode *& nodePtr,string ngram);
    void addNgramHelper( TreeNode *& nodePtr, const string ngram );
    void getTotalNgramCountHelper(TreeNode * root, int & totalCount);
    bool isFullHelper(TreeNode* root);
    bool isCompleteHelper ( TreeNode* root, int index, int totalNgramCount);
    void retrieveHelper(TreeNode*& rootPtr, const string ngram,int & count);

    //functions to delete a node int the tree
    void removeHelper( TreeNode *& nodePtr, const string ngram );
    void deleteNodeItem(TreeNode * &nodePtr);
    void processLeftmost(TreeNode *&nodePtr, string & treeItem, int & count);


    //functions to display the tree
    friend ostream& operator<<( ostream& out, const NgramTree& tree );
    ostream& displayHelper( ostream&, TreeNode* ) const;
    ostream& display( ostream& out ) const;

    //functions to use in the generateTree and addNgram functions
    bool equals(string s1, string s2);
    bool withoutSpace(string s);


};

#endif //HW2_NGRAMTREE_H
