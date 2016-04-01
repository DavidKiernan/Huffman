#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<deque>
#include<map>
using namespace std;

// Node to store the letter and it's frequency
class TreeNode
{
	friend class BinaryTree;
	friend class CompareTreeNode;
	friend ostream& operator<<(ostream&, const TreeNode&);
private:
	TreeNode *rightPtr, *leftPtr;
	TreeNode *root; // pointer to the root
	char data; // This will a letter 
	int frequency; // the frequency of the letter.

public:
	TreeNode();
	TreeNode(char letter, int times);
	TreeNode(TreeNode *lft, TreeNode *rgt); // Maybe Taking the Parent out will allow it to work
	TreeNode(TreeNode *node); // Missing this to make work? As its not a const
							  //TreeNode(const TreeNode&); // copy Constructor
	~TreeNode(); //Destructor

};

class CompareTreeNode {
	friend class BinaryTree;
public:
	bool operator()(TreeNode *node1, TreeNode *node2);
};


class BinaryTree
{
private:
	int padding;
	string message, code;
	ofstream decodedMessage;
	map<char, int> frequencyMap; // char is letter, int is frequency
	TreeNode *root = nullptr;// the tree "hangs" off of this root  http://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
	priority_queue<TreeNode, vector<TreeNode*>, CompareTreeNode> heap; // http://stackoverflow.com/questions/15646780/priority-queue-of-nodes
	map<char, string> huffMap; // contains codes for each letter in tree
	void huffmanEncoding(TreeNode *ptr, string direction);

public:
	void getSourceMessage(); // reading the txt file
	void frequencyTable(); // get the frequency of the letter
	void displayFreqTable(); // put in a Huffman Class?.
	void buildHeap(); //  FINISHED ?
	void huffmanEncoding();
	void displayHuffmanTable(); // Display letters as 0s & 1s

};

// Putting some of BinaryTree into make sense? Maybe clean it up.

/*
class HuffmanCode
{
friend class BinaryTree;
private:
//int heapSize;
string message, code;
ofstream decodedMessage;
map<char, int> frequencyMap; // char is letter, int is frequency
BinaryTree *root;
priority_queue<TreeNode, vector<TreeNode>, CompareTreeNode> heap;
public:

};
*/