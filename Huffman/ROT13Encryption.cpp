/*
David Kiernan x00093830
4th April 2016
3rd year Huffman CA Part B
*/
#include "ROT13Encryption.h"
#include<iostream>
#include<fstream>
using namespace std;

/***************************************************************************************
*	 Based on:
*    Title: [C++] ROT-13 string encoder tutorial (beginner to intermediate)
*    Author: Nobel via facepunch.com
*    Date: 31/3/2015
*    Code version: n/a
*    Availability: http://facepunch.com/showthread.php?t=1094693
*
***************************************************************************************/

Rot13::Rot13()
{
}

void Rot13::readPoem(std::string fileIn)
{
	cout << "PLAINTEXT BEFORE ENCRYPTION \n" << endl;
	string temp;
	// reads the txt file. Maybe allow user input?
	ifstream inputFromFile(fileIn);
	// while there is a line available get it.
	if (inputFromFile.is_open()) {
		while (inputFromFile)
		{
			getline(inputFromFile, temp);
			text += temp.append(" \n"); // add a blank line easier to read
			cout << temp; // display in console debugging purpose
		}
	}
	else
	{
		cout << "File Not Found" << endl;
	}
	inputFromFile.close(); // close the ifstream
}

void Rot13::rot13Encode()
{
	cout << "ENCRYPTED TEXT\n" << endl;
	for (unsigned int i = 0; i != text.length(); i++)
	{
		if ((text[i] >= 'a'&& text[i] <= 'm') || (text[i] >= 'A' && text[i] <= 'M'))
		{
			text[i] = text[i] + 13;
		}
		else if ((text[i] >= 'n'&& text[i] <= 'z') || (text[i] >= 'N' && text[i] <= 'Z'))
		{
			text[i] = text[i] - 13;
		}
	}
	cout << text;
}

void Rot13::rot13Decode()
{
	cout << "DECRYPTED TEXT SAME AS ORIGINAL\n" << endl;

	// ROT13 is an inverse cipher (2x13), so to decrypt it, the exact same algorithm is applied
	for (unsigned int i = 0; i != text.length(); i++)
	{
		if ((text[i] >= 'a'&& text[i] <= 'm') || (text[i] >= 'A' && text[i] <= 'M'))
		{
			text[i] = text[i] + 13;
		}
		else if ((text[i] >= 'n'&& text[i] <= 'z') || (text[i] >= 'N' && text[i] <= 'Z'))
		{
			text[i] = text[i] - 13;
		}
	}
	cout << text;
}


