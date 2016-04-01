#include "HuffmanTree.h"
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

/*
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
*/
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



void BinaryTree::huffmanEncoding(TreeNode * ptr, string direction)
{
	// Improved on 
	if (!ptr) // empty tree root is Null
	{
		cout << "Empty Tree" << endl;
	}
	else
	{
		if (ptr->data == NULL)
		{
			huffmanEncoding(ptr->leftPtr, direction + '0');
			huffmanEncoding(ptr->leftPtr, direction + '1');
		}
		else
		{
			huffMap.insert(pair<char, std::string>(ptr->data, direction));

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
	for (int i = 0; i < message.length(); i++)
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
	// Populate the priority queue
	map<char, int> ::iterator pQ;
	for (pQ = frequencyMap.begin(); pQ != frequencyMap.end(); pQ++)
	{
		heap.emplace(new TreeNode(pQ->first, pQ->second)); // push new anonymous node into the priority queue
	}

	// build the Huffman tree
	// Note: George told me about the emplace();
	while (heap.size() != 1)
	{
		TreeNode *leftSide = new TreeNode(heap.top());// store the top node from the heap
		heap.pop(); // pop off the top node from the heap (the one above)
		TreeNode *rightSide = new TreeNode(heap.top());
		heap.pop();
		TreeNode *newNodeInsert = new TreeNode(leftSide, rightSide);
		heap.emplace(newNodeInsert);  // push new node (tree), and add up the frequency (populated in PQ based on frequency)
	}
	root = heap.top(); // ref(set) the last node as the root
	heap.pop(); // pop off the tree from the priority queue
}

void BinaryTree::huffmanEncoding()
{
	huffmanEncoding(root, "");
}

void BinaryTree::displayHuffmanTable()
{
	cout << "Huffman Table:" << endl;
	for (map<char, string>::iterator it = huffMap.begin();
	it != huffMap.end(); it++) {
		cout << it->first << "\t" << it->second << endl;
	}
}


