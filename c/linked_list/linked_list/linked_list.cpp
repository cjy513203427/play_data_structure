#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Define capacity
#define MAXSIZE 20 
// Define return status code
typedef int Status;
// Define data type
typedef int ElemType;


Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;

// Define link list
typedef struct Node *LinkList;

// Init link list	
Status InitList(LinkList *L)
{
	// generate head node,L points to head node
	*L = (LinkList)malloc(sizeof(Node)); 
	// when memory allocation fails
	if (!(*L)) 
		return ERROR;
	// pointer field = NULL
	(*L)->next = NULL; 

	return OK;
}

// Condition:link list is exist
// Judge if link list is empty
Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

// Condition:link list is exist
// Let link list be a empty link list
Status ClearList(LinkList *L)
{
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
int ListLength(LinkList L)
{
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

// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// return value according to index i
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	// assign p first node
	p = L->next;
	j = 1;	
	// search node according to index i  with traverse
	while (p && j<i)
	{
		p = p->next;
		++j;
	}
	// when the ith element is not exist
	if (!p || j>i)
		return ERROR;
	*e = p->data;
	return OK;
}

// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// return index of element
int LocateElem(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e)
			return i;
		p = p->next;
	}

	return 0;
}


// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// Insert element in index i,length plus 1
Status ListInsert(LinkList L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = L;
	j = 1;
	// search node according to index i with traverse
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	// when the ith element is not exist
	if (!p || j > i)
		return ERROR;
	// generate new node
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s; 
	return OK;
}

// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// Delete element according to index i,return deleted value,length minus 1
Status ListDelete(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = L;
	j = 1;
	// search node according to index i with traverse
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	// when the ith element is not exist
	if (!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

// Condition:link list is exist,1¡Üi¡ÜListLength(L)
// Traverse every element
Status ListTraverse(LinkList L)
{
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
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	// initialize random seed
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	// build a single linked list with head node 
	(*L)->next = NULL;
	for (i = 0; i<n; i++)
	{
		// generate new node
		p = (LinkList)malloc(sizeof(Node));
		// generate random number within 100
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		// insert head of linked list
		(*L)->next = p;
	}
}

// Randomly generate values for n elements
// Build a single linked list with head node,insert from tail
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	// initialize random seed
	srand(time(0));
	// L is whole linked list
	*L = (LinkList)malloc(sizeof(Node));
	// r points to tail
	r = *L;
	for (i = 0; i<n; i++)
	{
		// generate new node
		p = (Node *)malloc(sizeof(Node));
	    // generate random number within 100
		p->data = rand() % 100 + 1;
		r->next = p;
		// then r is last element
		r = p;
	}
	r->next = NULL;
}

int main()
{
	LinkList L;
	ElemType e;
	Status i;
	int j, k;
	i = InitList(&L);
	printf("After L initialized £ºListLength(L)=%d\n", ListLength(L));
	for (j = 1; j <= 5; j++)
		i = ListInsert(L, 1, j);
	printf("After we insert 1~5 in head of L in order£ºL.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));
	i = ListEmpty(L);
	printf("If L is empty£ºi=%d(1:true 0:false)\n", i);

	i = ClearList(&L);
	printf("After we clear L£ºListLength(L)=%d\n", ListLength(L));
	i = ListEmpty(L);
	printf("If L is empty£ºi=%d(1:true 0:false)\n", i);

	for (j = 1; j <= 10; j++)
		ListInsert(L, j, j);
	printf("after we insert 1~10 in tail of L in order£ºL.data=");
	ListTraverse(L);

	printf("ListLength(L)=%d \n", ListLength(L));

	ListInsert(L, 1, 0);
	printf("After we insert 0 in head of L£ºL.data=");
	ListTraverse(L);
	printf("ListLength(L)=%d \n", ListLength(L));

	GetElem(L, 5, &e);
	printf("The 5th element is£º%d\n", e);
	for (j = 3; j <= 4; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("The %dth element is %d\n", k, j);
		else
			printf("There is not element,whose value is %d\n", j);
	}


	k = ListLength(L);
	for (j = k + 1; j >= k; j--)
	{
		i = ListDelete(L, j, &e);
		if (i == ERROR)
			printf("Deleting %dth elment failed\n", j);
		else
			printf("Deleted %dth elment is£º%d\n", j, e);
	}
	printf("Traverse L in order£º");
	ListTraverse(L);

	j = 5;
	ListDelete(L, j, &e);
	printf("Deleted %dth elment is£º%d\n", j, e);

	printf("Traverse L in order£º");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\nAfter we clear L£ºListLength(L)=%d\n", ListLength(L));
	CreateListHead(&L, 20);
	printf("Create the elements of  L as a whole (CreateListHead)£º");
	ListTraverse(L);

	i = ClearList(&L);
	printf("\nAfter we clear L£ºListLength(L)=%d\n", ListLength(L));
	CreateListTail(&L, 20);
	printf("Create the elements of  L as a whole (CreateListTail)£º");
	ListTraverse(L);

	system("pause");
	return 0;
}
