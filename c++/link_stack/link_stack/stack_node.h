#ifndef STACK_NODE_H
#define STACK_NODE_H


#include<iostream>
using namespace std;

// Define data type
typedef int ElemType;
typedef int Status;
typedef int SElemType;

class StackNode 
{
public:
	SElemType data;
	StackNode *next;
};

#endif // !1