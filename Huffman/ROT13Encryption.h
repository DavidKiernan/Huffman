/*
David Kiernan x00093830
4th April 2016
3rd year Huffman CA Part B
*/
#pragma once
#include<string>
class Rot13
{
public:
	Rot13();
	void readPoem(std::string fileIn);
	void rot13Encode();
	void rot13Decode();


private:
	std::string text;

};

