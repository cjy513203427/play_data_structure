#pragma once
#include "Node.h"
#ifndef STATIC_LINKED_LIST_H
#define STATIC_LINKED_LIST_H
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Define capacity
#define MAXSIZE 1000 
// Define return status code
typedef int Status;

class StaticLinkedList
{
public:
	Node StaticLinkList[MAXSIZE] ;
	Status visit(ElemType c);
	// Initialize array to alternate link list,space[0].cur is head pointer,"0" means null pointer
	Status InitList();
	// If static link list is null,then return index of distributed element
	int Malloc_SSL();
	// Recycle free element to alternate link list
	void Free_SSL(int k);
	// Condition: static link list is exist.
	// Return number of element	
	int ListLength();
	// Insert new element in index i
	Status ListInsert(int i, ElemType e);
	// Delete the ith element
	Status ListDelete(int i);
	Status ListTraverse();

};

#endif // !NODE_H
