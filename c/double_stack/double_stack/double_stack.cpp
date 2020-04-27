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

// define data type
typedef int SElemType;

typedef struct
{
	SElemType data[MAXSIZE];
	// Top of stack1
	int top1;
	// Top of stack2
	int top2;
}SqDoubleStack;


Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

// Construct an empty stack
Status InitStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

// Set S empty stack
Status ClearStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

// If s is an empty stack,return true,otherwise return false
Status StackEmpty(SqDoubleStack S)
{
	if (S.top1 == -1 && S.top2 == MAXSIZE)
		return TRUE;
	else
		return FALSE;
}

// return number of element,exactly is length of stack
int StackLength(SqDoubleStack S)
{
	return (S.top1 + 1) + (MAXSIZE - S.top2);
}

// Insert e as new top element
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
	// If stack is full
	if (S->top1 + 1 == S->top2)
		return ERROR;
	// Push element to stack1
	if (stackNumber == 1)
		S->data[++S->top1] = e;
	// Push element to stack2
	else if (stackNumber == 2)
		S->data[--S->top2] = e;
	return OK;
}

// If stack is not empty,then delete top element of S,return deleted element and OK,otherwise return ERROR
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		// If stack1 is empty
		if (S->top1 == -1)
			return ERROR;
		// Pop element from stack1
		*e = S->data[S->top1--];
	}
	else if (stackNumber == 2)
	{
		// If stack2 is empty
		if (S->top2 == MAXSIZE)
			return ERROR;
		// Pop element from stack2
		*e = S->data[S->top2++];
	}
	return OK;
}

Status StackTraverse(SqDoubleStack S)
{
	int i;
	i = 0;
	while (i <= S.top1)
	{
		visit(S.data[i++]);
	}
	i = S.top2;
	while (i<MAXSIZE)
	{
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;
}

int main()
{
	int j;
	SqDoubleStack s;
	int e;
	if (InitStack(&s) == OK)
	{
		for (j = 1; j <= 5; j++)
			Push(&s, j, 1);
		for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
			Push(&s, j, 2);
	}

	printf("Elements of stack are in turn:");
	StackTraverse(s);

	printf("Length of stack is:%d \n", StackLength(s));

	Pop(&s, &e, 2);
	printf("Popped element is e=%d\n", e);
	printf("If stack is empty:%d(1:Empty 0:Not empty)\n", StackEmpty(s));

	for (j = 6; j <= MAXSIZE - 2; j++)
		Push(&s, j, 1);

	printf("Elements of stack are in turn:");
	StackTraverse(s);

	Push(&s, 100, 1);


	ClearStack(&s);
	printf("After clearing stack,if stack is empty:%d(1:Empty 0:Not Empty)\n", StackEmpty(s));

	system("pause");
	return 0;
}