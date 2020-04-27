#include "linked_list.h"
#include "time.h"

Status LinkedList::visit(ElemType c) {
	cout<<c<<" ";
	return OK;
}

// Init link list	
Status LinkedList::InitList(LinkList *L) {
	// generate head node,L points to head node
	*L = new Node;
	// when memory allocation fails
	if (!(*L))
		return ERROR;
	// pointer field = NULL
	(*L)->next = NULL;
	return OK;
}

// Condition:link list is exist
// Judge if link list is empty
Status LinkedList::ListEmpty(LinkList L) {
	// judge if the first node has value
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

// Condition:link list is exist
// Let link list be a empty link list
Status LinkedList::ClearList(LinkList *L) {
	LinkList p, q;
	// assign p first node
	p = (*L)->next;
	while (p)
	{
		// save next node
		q = p->next;
		free(p);
		p = q;
	}
	// pointer domin of head node is NULL
	(*L)->next = NULL;
	return OK;
}

// Condition:link list is exist
// return length of link list
int LinkedList::ListLength(LinkList L) {
	int i = 0;
	// assign p first node
	LinkList p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

// Condition:link list is exist
// return value of index i
Status LinkedList::GetElem(LinkList L, int i, ElemType *e) {
	int j;
	LinkList p;
	// assign p first node
	p = L->next;
	j = 1;
	// search node according to index i with traverse
	while (p && j < i) {
		p = p->next;
		++j;
	}
	// when the ith element is not exist
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// return index of element
int LinkedList::LocateElem(LinkList L, ElemType e) {
	int i = 0;
	LinkList p = L->next;
	while (p) {
		i++;
		if (p->data == e)
			return i;
		p = p->next;
	}
	return 0;
}

// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// Insert element in index i,length plus 1
Status LinkedList::ListInsert(LinkList L, int i, ElemType e) {
	int j;
	LinkList p, s;
	p = L;
	j = 1;
	// search node according to index i with traverse
	while (p&&j < i) {
		p = p->next;
		++j;
	}
	// when the ith element is not exist
	if (!p || j > i)
		return ERROR;
	// generate new node
	s = new Node;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// Delete element according to index i,return deleted value,length minus 1
Status LinkedList::ListDelete(LinkList L, int i, ElemType *e) {
	int j;
	LinkList p, q;
	p = L;
	j = 1;
	//search node according to index i with traverse
	while (p->next && j < i) {
		p = p->next;
		++j;
	}
	// when the ith element is not exist
	if (!(p->next) || j > i)
		return ERROR;
	
	q = p->next;
	p->next = q->next;
	*e = q->data;
	delete q;
	return OK;
}

// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// Traverse every element
Status LinkedList::ListTraverse(LinkList L) {
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

// Randomly generate values for n elements
// Build a single linked list with head node,insert from head
void LinkedList::CreateListHead(LinkList *L, int n) {
	LinkList p;
	int i;
	// initialize random seed
	srand(time(0));
	*L = new Node;
	// build a single linked list with head node
	(*L)->next = NULL;
	for (i = 0; i < n; i++) {
		// generate new node
		p = new Node;
		// generate random number within 100
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

// Randomly generate values for n elements
// Build a single linked list with head node,insert from tail
void LinkedList::CreateListTail(LinkList *L, int n) {
	LinkList p, r;
	int i;
	// initialize random seed
	srand(time(0));
	// L is whole linked list
	*L = new Node;
	// r points to tail
	r = *L;
	for (int i = 0; i < n; i++) {
		// generate new node
		p = new Node;
		// generate random number within 100
		p->data = rand() % 100 + 1;
		r->next = p;
		// then r is last element
		r = p;
	}
	r->next = NULL;
}

int main() {
	LinkList L;
	ElemType e;
	Status i;
	int j, k;
	LinkedList ll;
	i = ll.InitList(&L);
	cout << "After L initialized £ºListLength(L) =" <<  ll.ListLength(L)<<endl;
	for (j = 1; j <= 5; j++)
		i = ll.ListInsert(L, 1, j);
	cout << "After we insert 1~5 in head of L in order£ºL.data=";
	ll.ListTraverse(L);
	cout << "ListLength(L)=" << ll.ListLength(L) << endl;
	i = ll.ListEmpty(L);
	cout << "If L is empty£ºi=" << i << "(1:true 0:false)"<<endl;
	i = ll.ClearList(&L);
	cout << "After we clear L£ºListLength(L)=" << ll.ListLength(L) << endl;
	i = ll.ListEmpty(L);
	cout << "If L is empty£ºi=" << i << "(1:true 0:false)" << endl;
	for (j = 1; j <= 10; j++)
		ll.ListInsert(L, j, j);
	cout << "after we insert 1~10 in tail of L in order£ºL.data=";
	ll.ListTraverse(L);
	cout << "ListLength(L)=" << ll.ListLength(L) << endl;
	ll.ListInsert(L, 1, 10);
	cout << "After we insert 0 in head of L£ºL.data=";
	ll.ListTraverse(L);
	cout << "ListLength(L)=" << ll.ListLength(L) << endl;
	ll.GetElem(L, 5, &e);
	cout << "The 5th element is£º" << e << endl;
	for (j = 3; j <= 4; j++) {
		k = ll.LocateElem(L, j);
		if (k)
			cout << "The " << k << "th element is " << j << endl;
		else
			cout << "There is not element,whose value is " << j << endl;
	}
	k = ll.ListLength(L);
	for (j = k + 1; j >= k; j--)
	{
		i = ll.ListDelete(L, j, &e);
		if (i == ERROR)
			cout << "Deleting " << j << "th elment failed" << endl;
		else
			cout << "Deleted " << j << "th element is: " << e << endl;
	}
	cout<<"Traverse L in order£º";
	ll.ListTraverse(L);
	j = 5;
	ll.ListDelete(L, j, &e);
	cout << "Deleted " << j << "th element is:  " << e << endl;
	cout << "Traverse L in order£º";
	ll.ListTraverse(L);
	i = ll.ClearList(&L);
	cout << endl << "After we clear L£ºListLength(L)=" << ll.ListLength(L) << endl;
	ll.CreateListHead(&L, 20);
	cout << "Create the elements of L as a whole (CreateListHead)£º" << endl;
	ll.ListTraverse(L);
	i = ll.ClearList(&L);
	cout << endl << "After we clear L£ºListLength(L)=" << ll.ListLength(L) << endl;
	ll.CreateListTail(&L, 20);
	cout << "Create the elements of L as a whole (CreateListTail)£º" << endl;
	ll.ListTraverse(L);

	system("pause");
}