#pragma once
#include "HuffmanTreeNode.h"
#include <string>
#include <queue>
#include <map>
#include <fstream>
class HuffmanTree
{
private:
	int padding; // this for padding the huffman code with 0s to make up equal sized chunks of 8 bits
	string message, code;
	//ofstream decodedMessage; // May not need?
	map<char, int> frequencyMap; // char is letter, int is frequency
	map<char, string> huffMap; // contains codes for each letter in tree
	TreeNode *root = nullptr;// the tree "hangs" off of this root  http://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
	priority_queue<TreeNode, vector<TreeNode*>, CompareTreeNode> heap; // http://stackoverflow.com/questions/15646780/priority-queue-of-nodes
	void huffmanEncoding(TreeNode *ptr, string direction);

public:

	string readFile(string fileIn); // reading the txt file. re named as used for different reads thus changes type from void to return a string
	void writeToFile(string textInput, string fileToWrite); // write to different files
	void frequencyTable(); // get the frequency of the letter
	void displayFreqTable();  // Displays letter & frequency
	void buildHeap(); //  put letter & freq in PriortyQueue & Builds tree
	void huffmanEncoding();
	void displayHuffmanTable(); // Display letters as 0s & 1s
	void writeHuffCodeToFile();
	void decodeHuffFile();
	string huffDecode(string codeIn);

};
