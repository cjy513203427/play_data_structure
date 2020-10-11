#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;


class Node {
public:
	char data;
	int weight;
	Node* leftChild;
	Node* rightChild;
};

#endif
