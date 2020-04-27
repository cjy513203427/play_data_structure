#include "sequence_stack.h"

Status SqStack::visit(SElemType c) {
	cout << c << " ";
	return OK;
}

// Construct an empty stack
Status SqStack::InitStack(SqStack *S) {
	S->top = -1;
	return OK;
}

// Clear stack
Status SqStack::ClearStack(SqStack *S) {
	S->top = -1;
	return OK;
}

// If stack is empty stack,then return true,otherwise return false
Status SqStack::StackEmpty(SqStack S) {
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}

// Return number of element,exactly it is length of stack
int SqStack::StackLength(SqStack S) {
	return S.top + 1;
}

// If stack is not empty,return top element of stack,then return OK,otherwise return ERROR
Status SqStack::GetTop(SqStack S, SElemType *e) {
	if (S.top == -1)
		return FALSE;
	else
		*e = S.data[S.top];
	return OK;
}

// Insert new element
Status SqStack::Push(SqStack *S, SElemType e) {
	// If stack is full
	if (S->top == MAXSIZE - 1)
		return ERROR;

	// Stack top plus 1
	S->top++;
	// Assign value to element of stack top
	S->data[S->top] = e;
	return OK;
}

// If Stack is not empty,then delete element of stack top,return deleted element and OK,otherwise return ERROR
Status SqStack::Pop(SqStack *S, SElemType *e) {
	if (S->top == -1)
		return ERROR;

	// Assign element of stack top to e
	*e = S->data[S->top];
	// Stack top minus 1
	S->top--;
	return OK;
}

// Traverse element from bottom of stack to top of stack
Status SqStack::StackTraverse(SqStack S) {
	int i;
	i = 0;
	while (i<=S.top)
	{
		visit(S.data[i++]);
	}
	cout<<endl;
	return OK;
}

int main() 
{
	int j;
	SqStack s;
	int e;
	if (s.InitStack(&s) == OK)
		for (j = 1; j <= 10; j++)
			s.Push(&s, j);
	
	cout << "Elements of stack are:";
	s.StackTraverse(s);
	s.Pop(&s, &e);

	cout << "Popped element of stack top is e=" << e << endl;
	cout << "If Stack is empty:"<< s.StackEmpty(s) <<"(1:Empty 0:Not empty)" << endl;
	s.GetTop(s, &e);
	cout << "Element of stack top is e=" << s.StackLength(s) << " Length of stack is " << e << endl;
	s.ClearStack(&s);
	cout << "After Clearing stack,If Stack is empty:" << s.StackEmpty(s) << "(1:Empty 0:Not empty)" << endl;
	system("pause");
	return 0;
}