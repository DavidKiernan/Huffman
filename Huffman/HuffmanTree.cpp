#include "HuffmanTree.h"
#include<sstream>


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
	leftPtr = rightPtr = root = NULL;
}

TreeNode::TreeNode(TreeNode * lft, TreeNode * rgt, TreeNode * parent)
{
	data = NULL;
	root = parent;
	leftPtr = lft;
	rightPtr = rgt;
	frequency = lft->frequency + rgt->frequency;
}

TreeNode::TreeNode(const TreeNode &rhs)
{
	if (rhs.leftPtr != NULL) {
		leftPtr = new TreeNode();
		leftPtr = rhs.leftPtr;
	}
	if (rhs.rightPtr != NULL) {
		rightPtr = new TreeNode();
		rightPtr = rhs.rightPtr;
	}
	data = rhs.data;
	frequency = rhs.frequency;
	root = rhs.root;
}

TreeNode::~TreeNode()
{
	while (root) {
		if (leftPtr != NULL) delete leftPtr;
		if (rightPtr != NULL) delete rightPtr;
	}

	delete root;
}

// May Not need.Will see when finished
ostream& operator<<(ostream& os, const TreeNode& rhs) {
	os << "\'" << rhs.data << " " << rhs.frequency << "\' ";
	return os;
}

bool CompareTreeNode::operator()(TreeNode & node1, TreeNode & node2)
{
	if (node1.frequency > node2.frequency)
	{
		return true;
	}
	else {
		return false;
	}
}



void BinaryTree::huffmanEncoding(TreeNode * ptr, string direction)
{
	// PreOrderTraversal
	if (ptr != NULL)
	{
		if (ptr->data == NULL) {

			huffmanEncoding(ptr->leftPtr, direction + "0");
			huffmanEncoding(ptr->rightPtr, direction + "1");
		}
		else
		{
			huffMap.insert(pair<char, string>(ptr->data, direction));
		}

	}

}

void BinaryTree::getSourceMessage()
{
	// reads the txt file. Maybe allow user input?
	ifstream originalMessage("HuffmanOriginal.txt");
	// while there is a line available get it.
	while (getline(originalMessage, message)) {
		cout << "Original Message " << endl << "-----------------------" << endl << message << endl << endl;
	}
	originalMessage.close(); // close the ifstream
}

void BinaryTree::frequencyTable()
{
	for ( int i = 0; i < message.length(); i++)
	{
		// letter not found add it with frequency of one
		if (frequencyMap.find(message[i]) == frequencyMap.end())
		{
			frequencyMap.insert(pair<char, int>(message[i], 1));
		}
		// letter exists then its frequency +1
		else
		{
			frequencyMap.find(message[i])->second++; // NOTE : "second is the number value"
		}
	}
}

void BinaryTree::displayFreqTable()
{
	// test data went into freq map
	map<char, int> ::iterator p;

	cout << "Test Freq Map" << endl << "----------------------- " << endl;
	for (p = frequencyMap.begin(); p != frequencyMap.end(); p++)
	{
		cout << p->first << "  " << p->second << endl;
	}
	cout << endl;
}

void BinaryTree::buildHeap()
{
	// takes everything from frequency table to priority queue
	map<char, int> ::iterator p;
	for (p = frequencyMap.begin(); p != frequencyMap.end(); p++)
	{
		TreeNode *newNode = new TreeNode(p->first, p->second);
		heap.push(*newNode);
	}
	// Pop off 2 at a time until 1 left

	while (heap.size() != 0)
	{
		if (heap.size() == 1) break;
		TreeNode *lft = new TreeNode(heap.top());
		heap.pop();
		TreeNode *rgt = new TreeNode(heap.top());
		heap.pop();
		TreeNode *newInsert = new TreeNode(lft, rgt, root);
		heap.push(*newInsert);
	}
}

void BinaryTree::huffmanEncoding()
{
	if (!root) {
		cout << "Tree is empty" << endl;
	}
	else {
		huffmanEncoding(root, "");
		//displayHuffmanTable();
	}
}

void BinaryTree::displayHuffmanTable()
{
	cout << "Huffman Table:" << endl;
	for (map<char, string>::iterator it = huffMap.begin();
	it != huffMap.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
}


