#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

typedef char TElemType;

class Node {
public:
	TElemType data;
	Node *lchild, *rchild;
};

#endif