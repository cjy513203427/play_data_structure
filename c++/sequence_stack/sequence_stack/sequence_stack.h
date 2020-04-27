#pragma once
#ifndef SEQUENCE_STACK_H
#define SEQUENCE_STACK_H
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Initialize capacity
#define MAXSIZE 20
typedef int Status;
// Data Type
typedef int SElemType;

// Sequence Stack Structure
class SqStack
{
public:
	SElemType data[MAXSIZE];
	// Stack top
	int top;

	Status visit(SElemType c);
	// Construct an empty stack
	Status InitStack(SqStack *S);
	// Clear stack
	Status ClearStack(SqStack *S);
	// If stack is empty stack,then return true,otherwise return false
	Status StackEmpty(SqStack S);
	// Return number of element,exactly it is length of stack
	int StackLength(SqStack S);
	// If stack is not empty,return top element of stack,then return OK,otherwise return ERROR
	Status GetTop(SqStack S, SElemType *e);
	// Insert new element
	Status Push(SqStack *S, SElemType e);
	// If Stack is not empty,then delete element of stack top,return deleted element and OK,otherwise return ERROR
	Status Pop(SqStack *S, SElemType *e);
	// Traverse element from bottom of stack to top of stack
	Status StackTraverse(SqStack S);

};


#endif // !SEQUENCE_STACK_H
