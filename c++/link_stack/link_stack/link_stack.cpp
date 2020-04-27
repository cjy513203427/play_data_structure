#include "stack_node.h"
#include "link_stack.h"

// Construct an empty stack
Status LinkStack::InitStack() {
	this->top = new StackNode();
	if (!this->top)
		return ERROR;
	this->top = NULL;
	this->count = 0;
	return OK;
}

// Set S an empty stack
Status LinkStack::ClearStack()
{
	StackNode* p;
	StackNode* q;
	p = this->top;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	this->count = 0;
	return OK;
}

// If stack is empty,return TRUE,otherwise return FALSE
Status LinkStack::StackEmpty()
{
	if (this->count == 0)
		return TRUE;
	else
		return FALSE;
}

// Return number of element,exactly is length of stack
int LinkStack::StackLength()
{
	return this->count;
}

// If stack is not empty,return top element of stack,then return OK,otherwise return FALSE
Status LinkStack::GetTop(SElemType *e)
{
	if (this->top == NULL)
		return ERROR;
	else
		*e = this->top->data;
	return OK;
}

// Insert element as new top element of stack
Status LinkStack::Push(SElemType e)
{
	StackNode* s = new StackNode();
	s->data = e;
	// Assign top element to next of new node
	s->next = this->top;
	// Assign new node to the top pointer
	this->top = s;
	this->count++;
	return OK;
}

// If stack is not empty,delete top element of S,return deleted element,then return OK,otherwise return ERROR
Status LinkStack::Pop(SElemType *e)
{
	StackNode* p;
	if (StackEmpty())
		return ERROR;
	*e = this->top->data;
	// Assign top node to p
	p = this->top;
	// Let top pointer minus 1,it points to next node
	this->top = this->top->next;
	// Release node p
	free(p);
	this->count--;
	return OK;
}

Status LinkStack::visit(SElemType c)
{
	cout<<c<<" ";
	return OK;
}

Status LinkStack::StackTraverse()
{
	StackNode* p;
	p = this->top;
	while (p)
	{
		this->visit(p->data);
		p = p->next;
	}
	cout << endl;
	return OK;
}

int main()
{
	int j;
	LinkStack s;
	int e;
	if (s.InitStack() == OK)
		for (j = 1; j <= 10; j++)
			s.Push(j);
	cout<<"Elements of stack are in turn:";
	s.StackTraverse();
	s.Pop(&e);
	printf("Popped top element is e=%d\n", e);
	printf("If stack is empty:%d(1:Empty 0:Not Empty)\n", s.StackEmpty());
	s.GetTop(&e);
	printf("Top element is e=%d Length of stack is %d\n", e, s.StackLength());
	s.ClearStack();
	printf("After clearing stack,if stack is empty:%d(1:Empty 0:Not Empty)\n", s.StackEmpty());
	system("pause");
	return 0;
}