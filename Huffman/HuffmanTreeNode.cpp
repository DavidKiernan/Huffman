/*
David Kiernan x00093830
4th April 2016
3rd year Huffman CA
*/
#include "HuffmanTreeNode.h"
#include<sstream>
#include <bitset>


TreeNode::TreeNode()
{
	data = ' ';
	frequency = 0;
	leftPtr = rightPtr = root = NULL;
}

TreeNode::TreeNode(char letter, int times)
{
	data = letter;
	frequency = times;
	leftPtr = rightPtr = NULL;
}

TreeNode::TreeNode(TreeNode * lft, TreeNode * rgt)
{
	data = NULL;
	leftPtr = lft;
	rightPtr = rgt;
	frequency = lft->frequency + rgt->frequency;
}

TreeNode::TreeNode(TreeNode * node)
{
	data = node->data;
	frequency = node->frequency;
	if (node->leftPtr != nullptr) {
		leftPtr = node->leftPtr;
	}
	if (node->rightPtr != nullptr) {
		rightPtr = node->rightPtr;
	}
}


TreeNode::~TreeNode()
{
	while (root) {
		if (leftPtr != NULL) delete leftPtr;
		if (rightPtr != NULL) delete rightPtr;
	}

	delete root;
}


// Using & instead of a pointer 
bool CompareTreeNode::operator()(TreeNode *node1, TreeNode *node2)
{
	if (node1->frequency > node2->frequency)
	{
		return true;
	}
	else {
		return false;
	}
}
