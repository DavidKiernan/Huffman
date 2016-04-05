#include "HuffmanTree.h"
#include "ROT13Encryption.h"
#include<string>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{

	// Maybe put all this into a single method. could be neater.
	/*HuffmanTree test;
	cout << test.readFile("HuffmanOriginal.txt") << "\n"<<endl;
	test.frequencyTable(); // This works. Can improve?
	test.displayFreqTable(); // This works. Can improve?
	test.buildHeap(); // Works
	test.huffmanEncoding(); // Empty table get help to fix.
	test.writeHuffCodeToFile();
	test.decodeHuffFile();
	test.compressHuffFile();
	test.decompressHuffFile();
	*/
	//cout << "\n\n\n" << endl;
	cout << "ROT13 \n" << endl;

	Rot13 rot13Test;
	rot13Test.readPoem("Poem.txt");
	rot13Test.rot13Encode();
	rot13Test.rot13Encode();
	system("pause");
	return 0;
}