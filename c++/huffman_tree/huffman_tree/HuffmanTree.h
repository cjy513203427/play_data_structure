#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include<iostream>
using namespace std;
#define MAX_TREE_SIZE 6
typedef bool Status;

class HuffmanTree {
public:
	// Construct huffman tree
	Node createTree(Node Nodes[], int len);
	// Swap element, whose index is i, and element, whose index is j
	Status swap(Node Nodes[], int i, int j);
	// Implement quicksort, in order to sort the nodes
	void subSort(Node Nodes[], int start, int end);
	Status quickSort(Node Nodes[], int len);
	// Breadth first traversal
	Node* breadthFirst(Node* root);
};

#endif
