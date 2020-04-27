#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Initialize capacity
#define MAXSIZE 20

typedef int Status;

// define data type
typedef int SElemType;

class SqDoubleStack {
public:
	SElemType data[MAXSIZE];
	// Top of stack1
	int top1;
	// Top of stack2
	int top2;
	Status visit(SElemType c);
	// Construct an empty stack
	Status InitStack();
	// Set S empty stack
	Status ClearStack();
	// If s is an empty stack,return true,otherwise return false
	Status StackEmpty();
	// return number of element,exactly is length of stack
	int StackLength();
	// Insert e as new top element
	Status Push(SElemType e, int stackNumber);
	// If stack is not empty,then delete top element of S,return deleted element and OK,otherwise return ERROR
	Status Pop(SElemType *e, int stackNumber);
	Status StackTraverse();
};

#endif
