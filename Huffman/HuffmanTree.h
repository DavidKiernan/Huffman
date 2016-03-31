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
	TreeNode(TreeNode *lft, TreeNode *rgt, TreeNode *parent);
	TreeNode(const TreeNode&); // copy Constructor
	~TreeNode(); //Destructor

};

class CompareTreeNode {
public:
	bool operator()(TreeNode &node1, TreeNode &node2);
};


class BinaryTree
{
private:
	int heapSize;
	string message, code;
	ofstream decodedMessage;
	map<char, int> frequencyMap; // char is letter, int is frequency
	TreeNode *root;
	priority_queue<TreeNode, vector<TreeNode>, CompareTreeNode> heap;
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