#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

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
typedef struct
{
	SElemType data[MAXSIZE];
	// Stack top
	int top;
}SqStack;

Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

// Construct an empty stack
Status InitStack(SqStack *S)
{
	S->top = -1;
	return OK;
}

// Clear stack
Status ClearStack(SqStack *S)
{
	S->top = -1;
	return OK;
}

// If stack is empty stack,then return true,otherwise return false
Status StackEmpty(SqStack S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}

// Return number of element,exactly it is length of stack
int StackLength(SqStack S)
{
	return S.top + 1;
}

// If stack is not empty,return top element of stack,then return OK,otherwise return ERROR
Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}

// Insert new element
Status Push(SqStack *S, SElemType e)
{
	// If stack is full
	if (S->top == MAXSIZE - 1)
	{
		return ERROR;
	}
	// Stack top plus 1
	S->top++;
	// Assign value to element of stack top
	S->data[S->top] = e;
	return OK;
}

// If Stack is not empty,then delete element of stack top,return deleted element and OK,otherwise return ERROR
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	// Assign element of stack top to e
	*e = S->data[S->top];
	// Stack top minus 1
	S->top--;
	return OK;
}

// Traverse element from bottom of stack to top of stack
Status StackTraverse(SqStack S)
{
	int i;
	i = 0;
	while (i <= S.top)
	{
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;
}

int main()
{
	int j;
	SqStack s;
	int e;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 10; j++)
			Push(&s, j);
	printf("Elements of stack are:");
	StackTraverse(s);
	Pop(&s, &e);
	printf("Popped element of stack top is e=%d\n", e);
	printf("If Stack is empty:%d(1:Empty 0:Not empty)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("Element of stack top is e=%d Length of stack is%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("After Clearing stack,If Stack is empty:%d(1:Empty 0:Not empty)\n", StackEmpty(s));

	system("pause");
	return 0;
}