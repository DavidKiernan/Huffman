#include "HuffmanTree.h"
#include<string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
	// Maybe put all this into a single method. could be neater.
	BinaryTree test;
	test.getSourceMessage("HuffmanOriginal.txt"); // This works.
	test.frequencyTable(); // This works. Can improve?
	test.displayFreqTable(); // This works. Can improve?
	test.buildHeap(); // Think it works
	test.huffmanEncoding(); // Empty table get help to fix.
	test.displayHuffmanTable();

	system("pause");
	return 0;
}