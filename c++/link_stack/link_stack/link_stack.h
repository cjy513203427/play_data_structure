#ifndef LINK_STACK_H
#define LINK_STACK_H
#include "stack_node.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Initialize capacity
#define MAXSIZE 20
#include<iostream>
using namespace std;

// Define data type
typedef int ElemType;


class LinkStack {
public:
	StackNode* top;
	int count;
	Status visit(SElemType c);
	// Construct an empty stack
	Status InitStack();
	// Set S an empty stack
	Status ClearStack();
	// If stack is empty,return TRUE,otherwise return FALSE
	Status StackEmpty();
	// Return number of element,exactly is length of stack
	int StackLength();
	// If stack is not empty,return top element of stack,then return OK,otherwise return FALSE
	Status GetTop(SElemType *e);
	// Insert element as new top element of stack
	Status Push(SElemType e);
	// If stack is not empty,delete top element of S,return deleted element,then return OK,otherwise return ERROR
	Status Pop(SElemType *e);
	Status visit(SElemType c);
	Status StackTraverse();
};

#endif // !1
