#include "double_stack.h"
Status SqDoubleStack::visit(SElemType c) {
	cout << c << " ";
	return OK;
}

// Construct an empty stack
Status SqDoubleStack::InitStack(){
	this->top1 = -1;
	this->top2 = MAXSIZE;
	return OK;
}

// Set S empty stack
Status SqDoubleStack::ClearStack() {
	this->top1 = -1;
	this->top2 = MAXSIZE;
	return OK;
}

// If s is an empty stack,return true,otherwise return false
Status SqDoubleStack::StackEmpty() {
	if (this->top1 == -1 && this->top2 == MAXSIZE)
		return TRUE;
	else
		return FALSE;
}

// return number of element,exactly is length of stack
int SqDoubleStack::StackLength() {
	return (this->top1 + 1) + (MAXSIZE - this->top2);
}

// Insert e as new top element
Status SqDoubleStack::Push(SElemType e, int stackNumber) {
	// If stack is full
	if (this->top1 + 1 == this->top2)
		return ERROR;
	// Push element to stack1
	if (stackNumber == 1)
		this->data[++this->top1] = e;
	// Push element to stack2
	else if (stackNumber == 2)
		this->data[--this->top2] = e;
	return OK;
}

// If stack is not empty,then delete top element of S,return deleted element and OK,otherwise return ERROR
Status SqDoubleStack::Pop(SElemType *e, int stackNumber) {
	if (stackNumber == 1)
	{
		// If stack1 is empty
		if (this->top1 == -1)
			return ERROR;
		// Pop element from stack1
		*e = this->data[this->top1--];
	}
	else if (stackNumber == 2)
	{
		// If stack2 is empty
		if (this->top2 == MAXSIZE)
			return ERROR;
		// Pop element from stack2
		*e = this->data[this->top2++];
	}
	return OK;
}


Status SqDoubleStack::StackTraverse() {
	int i;
	i = 0;
	while (i <= this->top1)
	{
		visit(this->data[i++]);
	}
	i = this->top2;
	while (i<MAXSIZE)
	{
		visit(this->data[i++]);
	}
	printf("\n");
	return OK;
}

int main()
{
	int j;
	SqDoubleStack s;
	int e;
	if (s.InitStack() == OK)
	{
		for (j = 1; j <= 5; j++)
			s.Push(j, 1);
		for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
			s.Push(j, 2);
	}

	cout << "Elements of stack are in turn:";
	s.StackTraverse();

	cout << "Length of stack is:" << s.StackLength() << endl;

	s.Pop(&e, 1);
	cout << "Popped element is e="<<e<< endl;
	cout << "If stack is empty:" << s.StackEmpty() << "(1:Empty 0:Not empty)" << endl;

	for (j = 6; j <= MAXSIZE - 2; j++)
		s.Push(j, 1);

	cout<<"Elements of stack are in turn:";
	s.StackTraverse();

	s.Push(100, 1);


	s.ClearStack();
	cout << "After clearing stack,if stack is empty:" << s.StackEmpty() << "(1:Empty 0:Not Empty)" << endl;

	system("pause");
	return 0;
}