#include "Node.h"
#include "StaicLinkedList.h"

Status StaticLinkedList::visit(ElemType c) {
	cout << c <<" ";
	return OK;
}

// Initialize array to alternate link list,space[0].cur is head pointer,"0" means null pointer
Status StaticLinkedList::InitList() {
	int i = 0;
	for (i = 0; i < MAXSIZE - 1; i++)
		StaticLinkList[i].cur = i + 1;
	// for now link list is null,the cursor of last element is 0
	StaticLinkList[MAXSIZE - 1].cur = 0;
	return OK;
}

// If static link list is null,then return index of distributed element
int StaticLinkedList::Malloc_SSL() {
	// Get index of free element
	int i = StaticLinkList[0].cur;

	if (StaticLinkList[0].cur)
		// Use next element as alternate element
		StaticLinkList[0].cur = StaticLinkList[i].cur;
	return i;
}

// Recycle free element to alternate link list
void StaticLinkedList::Free_SSL(int k) {
	// Link deleted element to a alternate link list
	// Let free element become the second element of alternate link list
	StaticLinkList[k].cur = StaticLinkList[0].cur;
	// Let the deleted element become the first element of alternate link list
	StaticLinkList[0].cur = k;
}

// Condition: static link list is exist.
// Return number of element	
int StaticLinkedList::ListLength() {
	int j = 0;
	// Get index of the first element with value
	int i = StaticLinkList[MAXSIZE - 1].cur;
	while (i)
	{
		i = StaticLinkList[i].cur;
		j++;
	}
	return j;
}

// Insert new element in index i
Status StaticLinkedList::ListInsert(int i, ElemType e) {
	int j, k, l;
	// k is the index of the last element
	k = MAXSIZE - 1;
	if (i<0 || i>ListLength())
		return ERROR;
	// Get index of free element
	j = Malloc_SSL();
	if (j)
	{
		StaticLinkList[j].data = e;
		// Find the element,who is in front of the ith element
		for (l = 0; l < i; l++) 
			k = StaticLinkList[k].cur;
		// s->next = p->next
		StaticLinkList[j].cur = StaticLinkList[k].cur;
		// p->next = s
		StaticLinkList[k].cur = j;
		return OK;
	}
	return ERROR;
}

// Delete the ith element
Status StaticLinkedList::ListDelete(int i) {
	int j, k;
	if (i<0 || i>ListLength() - 1)
		return ERROR;
	k = MAXSIZE - 1;
	// Find the element,who is in front of the ith element
	for(j=0;j<i;j++)
		k = StaticLinkList[k].cur;
	// q = p->next
	j = StaticLinkList[k].cur;
	// p->next = q->next
	StaticLinkList[k].cur = StaticLinkList[j].cur;
	Free_SSL(j);
	return OK;
}

Status StaticLinkedList::ListTraverse() {
	int j = 0;
	int i = StaticLinkList[MAXSIZE - 1].cur;
	while (i)
	{
		visit(StaticLinkList[i].data);
		i = StaticLinkList[i].cur;
		j++;
	}
	return j;
	cout << endl;
	return OK;
}


int main() {
	Status i;
	StaticLinkedList sll;
	sll.InitList();
	cout << "After we initialize L£ºL.length=" << sll.ListLength() << endl;

	i = sll.ListInsert(0, 'F');
	i = sll.ListInsert(0, 'E');
	i = sll.ListInsert(0, 'D');
	i = sll.ListInsert(0, 'B');
	i = sll.ListInsert(0, 'A');

	cout << endl << "After we insert FEDBA in the head of L£º" << endl << "L.data=";
	sll.ListTraverse();

	i = sll.ListInsert(2, 'C');
	cout << endl << "After we insert 'C' between 'B' and 'D' in L£º"<<endl<<"L.data=";
	sll.ListTraverse();

	i = sll.ListDelete(0);
	cout << endl << "After we delete 'A' in L£º" << endl << "L.data=";
	sll.ListTraverse();

	cout << endl;

	system("pause");
	return 0;
}