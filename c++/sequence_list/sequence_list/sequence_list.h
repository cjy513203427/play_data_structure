#pragma once
#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
//orginal capacity
#define MAXSIZE 20 

//function type,return OK or Error
typedef int Status;
//according to differrent situations,assume int
typedef int ElementType;


class SqList
{
public:
	Status visit(ElementType c);
	//init sequence list
	Status InitList(SqList *L);
	//judge if list empty is
	Status ListEmpty(SqList sl);
	//clear sequence list
	Status ClearList(SqList *sl);
	// return list length
	int ListLength(SqList sl);
	/*Condition:0¡Üi¡ÜListLength
	according to index return element
	*/
	Status GetElem(SqList sl, int i, ElementType *et);
	/*Condition:ListLength>0
	according to element return element's index
	*/
	int locateElem(SqList sl, ElementType et);
	/*Condition: !=MAXSIZE; 0¡Üi¡ÜListLength
	insert element in position i
	*/
	Status ListInsert(SqList *sl, int i, ElementType et);
	/*Condition:ListLength!=0; 0¡Üi¡ÜListLength
	delete element according to index
	return deleted element
	*/
	Status ListDelete(SqList *sl, int i, ElementType *et);
	Status ListTraverse(SqList sl);

	ElementType data[MAXSIZE];
	int length;
};