#pragma once
#include "node.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Define capacity
#define MAXSIZE 20 
// Define return status code
typedef int Status;

typedef Node * LinkList;
class LinkedList {
public:

	Status visit(ElemType c);
	// Init link list	
	Status InitList(LinkList *L);
	// Condition:link list is exist
	// Judge if link list is empty
	Status ListEmpty(LinkList L);
	// Condition:link list is exist
	// Let link list be a empty link list
	Status ClearList(LinkList *L);
	// Condition:link list is exist
	// return length of link list
	int ListLength(LinkList L);
	// Condition:link list is exist,1¡Üi¡ÜListLength(L)
	// return value according to index i
	Status GetElem(LinkList L, int i, ElemType *e);
	// Condition:link list is exist,1¡Üi¡ÜListLength(L)
	// return index of element
	int LocateElem(LinkList L, ElemType e);
	// Condition:link list is exist,1¡Üi¡ÜListLength(L)
	// Insert element in index i,length plus 1
	Status ListInsert(LinkList L, int i, ElemType e);
	// Condition:link list is exist,1¡Üi¡ÜListLength(L)
	// Delete element according to index i,return deleted value,length minus 1
	Status ListDelete(LinkList L, int i, ElemType *e);
	// Condition:link list is exist,1¡Üi¡ÜListLength(L)
	// Traverse every element
	Status ListTraverse(LinkList L);
	// Randomly generate values for n elements
	// Build a single linked list with head node,insert from head
	void CreateListHead(LinkList *L, int n);
	// Randomly generate values for n elements
	// Build a single linked list with head node,insert from tail
	void CreateListTail(LinkList *L, int n);
};

#endif // !LINKED_LIST_H
