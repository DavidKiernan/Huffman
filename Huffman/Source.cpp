#include "HuffmanTree.h"
#include<string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
	BinaryTree test;
	test.getSourceMessage(); // This works.
	test.frequencyTable(); // This works. Can improve?
	test.displayFreqTable(); // This works. Can improve?
	test.buildHeap();
	test.huffmanEncoding();
	test.displayHuffmanTable();
	system("pause");
	return 0;
}