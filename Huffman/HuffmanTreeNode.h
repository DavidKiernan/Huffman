/*
David Kiernan x00093830
4th April 2016
3rd year Huffman CA
*/
#pragma once
using namespace std;

// Node to store the letter and it's frequency
class TreeNode
{
	friend class HuffmanTree;
	friend class CompareTreeNode;
private:
	TreeNode *rightPtr, *leftPtr;
	TreeNode *root; // pointer to the root
	char data; // This will a letter 
	int frequency; // the frequency of the letter.

public:
	TreeNode();
	TreeNode(char letter, int times);
	TreeNode(TreeNode *lft, TreeNode *rgt); // Maybe Taking the Parent out will allow it to work
	TreeNode(TreeNode *node); 
	~TreeNode(); //Destructor

};

class CompareTreeNode {
	friend class HuffmanTree;
public:
	bool operator()(TreeNode *node1, TreeNode *node2);
};
