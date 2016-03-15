#include "HuffmanTree.h"

void BinaryTree::preOrderTraversal(TreeNode * subtree, string huffmanCode)
{
	// No Tree
	if (subtree != NULL)
	{
		// No value in tree
		if (subtree->data == NULL)
		{
			preOrderTraversal(subtree->leftPtr, huffmanCode + "0");
			preOrderTraversal(subtree->rightPtr, huffmanCode + "1");
		}
		// there is a value then insert,
		else
		{
			huffmanMap.insert(pair<char, string>(subtree->data, huffmanCode));
		}
	}
}

void BinaryTree::preOrderTraversal()
{
	if (!root) {
		cout << "Empty Tree" << endl;
	}
	else 
	{
		preOrderTraversal(root, " ");

		// test data went into freq map
		map<char, string> ::iterator itor;

		cout << "Test Huff Map" << endl << "-----------------------" << endl;
		for (itor = huffmanMap.begin(); itor != huffmanMap.end(); itor++)
		{
			cout << itor->first << itor->second << endl;
		}
		cout << endl;
	}
}
