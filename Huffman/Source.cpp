#include "HuffmanTree.h"
#include<string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{

	// Maybe put all this into a single method. could be neater.
	HuffmanTree test;
	//test.readFile("HuffmanOriginal.txt"); // This works.
	cout << test.readFile("HuffmanOriginal.txt") << "\n" << endl;
	test.frequencyTable(); // This works. Can improve?
	test.displayFreqTable(); // This works. Can improve?
	test.buildHeap(); // Works 
	test.huffmanEncoding(); // Empty table get help to fix.
	test.writeHuffCodeToFile();
	test.decodeHuffFile();
	system("pause");
	return 0;
}