#include "string.h"
#include "ctype.h"      

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
#define MAXSIZE 1000

// Status code
typedef int Status;
// Data type
typedef char ElemType;


Status visit(ElemType c)
{
	printf("%c ", c);
	return OK;
}

// Static link list structure of linear list
typedef struct
{
	ElemType data;
	// Cursor,if the value is equal to zero,it means pointless
	int cur;
} Node, StaticLinkList[MAXSIZE];

// Initialize array to alternate link list,space[0].cur is head pointer,"0" means null pointer
Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i<MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	// for now link list is null,the cursor of last element is 0
	space[MAXSIZE - 1].cur = 0; 
	return OK;
}


// If static link list is null,then return index of distributed element
int Malloc_SSL(StaticLinkList space)
{
	// Get index of free element
	int i = space[0].cur;

	if (space[0].cur)
		// Use next element als alternate element
		space[0].cur = space[i].cur;

	return i;
}


// Recycle free element to alternate link list
void Free_SSL(StaticLinkList space, int k)
{
	// Link deleted element to a alternate link list
	space[k].cur = space[0].cur;
	// Let the deleted element become the first element of alternate link list
	space[0].cur = k;
}

// Condition: static link list is exist.
// Return number of element	
int ListLength(StaticLinkList L)
{
	int j = 0;
	// Get index of the first element with value
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

// Insert new element in index i
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;
	// k is the index of the last element
	k = MAXSIZE - 1;
	if (i < 0 || i > ListLength(L) )
		return ERROR;
	// Get index of free element
	j = Malloc_SSL(L);
	if (j)
	{
		L[j].data = e;
		// Find the element,who is in front of the ith element
		for (l = 0; l < i; l++)
			k = L[k].cur;
		// s->next = p-next
		L[j].cur = L[k].cur;
		// p->next = s
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

// Delete the ith element
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i < 0 || i > ListLength(L)-1)
		return ERROR;
	k = MAXSIZE - 1;
	// Find the element,who is in front of the ith element
	for (j = 0; j < i; j++)
		k = L[k].cur;
	// q = p->next
	j = L[k].cur;
	// p->next = q->next
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;
}


Status ListTraverse(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		visit(L[i].data);
		i = L[i].cur;
		j++;
	}
	return j;
	printf("\n");
	return OK;
}


int main()
{
	StaticLinkList L;
	Status i;
	i = InitList(L);
	printf("After we initialize L£ºL.length=%d\n", ListLength(L));

	i = ListInsert(L, 0, 'F');
	i = ListInsert(L, 0, 'E');
	i = ListInsert(L, 0, 'D');
	i = ListInsert(L, 0, 'B');
	i = ListInsert(L, 0, 'A');

	printf("\nAfter we insert FEDBA in the head of L£º\nL.data=");
	ListTraverse(L);

	i = ListInsert(L, 2, 'C');
	printf("\nAfter we insert 'C' between 'B' and 'D' in L£º\nL.data=");
	ListTraverse(L);

	i = ListDelete(L, 0);
	printf("\nAfter we delete 'A' in L£º\nL.data=");
	ListTraverse(L);

	printf("\n");

	system("pause");
	return 0;
}