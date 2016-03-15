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

private:
	TreeNode *rightPtr, *leftPtr;
	char data; // This will a letter 
	int freqency; // the freqency of the letter.
};


class BinaryTree
{
private:
	TreeNode *root;
	ofstream decodeMessage;
	map<char, int>frequencyMap; // Letters(char) are key & count (int) is how often it happens
	map<char, string>huffmanMap; // Letters(char) are key & positon(string) is where in tree is'
	void preOrderTraversal(TreeNode *subtree, string huffmanCode); // recursive method. huffmanCode is direction
	//void inOrderTraversal(TreeNode *subtree); // recursive method
	//void postOrderTraversal(TreeNode *subtree);


public:
	void preOrderTraversal();
};