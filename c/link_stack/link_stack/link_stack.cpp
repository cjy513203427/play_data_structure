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
typedef int SElemType;


// Link Stack Structure
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;


typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

// Construct an empty stack
Status InitStack(LinkStack *S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->top = NULL;
	S->count = 0;
	return OK;
}

// Set S an empty stack
Status ClearStack(LinkStack *S)
{
	LinkStackPtr p, q;
	p = S->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	S->count = 0;
	return OK;
}

// If stack is empty,return TRUE,otherwise return FALSE
Status StackEmpty(LinkStack S)
{
	if (S.count == 0)
		return TRUE;
	else
		return FALSE;
}

// Return number of element,exactly is length of stack
int StackLength(LinkStack S)
{
	return S.count;
}

// If stack is not empty,return top element of stack,then return OK,otherwise return FALSE
Status GetTop(LinkStack S, SElemType *e)
{
	if (S.top == NULL)
		return ERROR;
	else
		*e = S.top->data;
	return OK;
}

// Insert element as new top element of stack
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	// Assign top element to next of new node
	s->next = S->top;
	// Assign new node to the top pointer
	S->top = s;
	S->count++;
	return OK;
}

// If stack is not empty,delete top element of S,return deleted element,then return OK,otherwise return ERROR
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	// Assign top node to p
	p = S->top;
	// Let top pointer minus 1,it points to next node
	S->top = S->top->next;
	// Release node p
	free(p);
	S->count--;
	return OK;
}

Status StackTraverse(LinkStack S)
{
	LinkStackPtr p;
	p = S.top;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main()
{
	int j;
	LinkStack s;
	int e;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 10; j++)
			Push(&s, j);
	printf("Elements of stack are in turn£º");
	StackTraverse(s);
	Pop(&s, &e);
	printf("Popped top element is e=%d\n", e);
	printf("If stack is empty:%d(1:Empty 0:Not Empty)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("Top element is e=%d Length of stack is %d\n", e, StackLength(s));
	ClearStack(&s);
	printf("After clearing stack,if stack is empty:%d(1:Empty 0:Not Empty)\n", StackEmpty(s));
	system("pause");
	return 0;
}