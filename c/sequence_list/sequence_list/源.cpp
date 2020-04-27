#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define TRUE 1
#define FALSE 0

//orginal capacity
#define MAXSIZE 20 

//function type,return OK or Error
typedef int Status;
//according to differrent situations,assume int
typedef int ElementType;

Status visit(ElementType c) {
	printf("%d ", c);
	return TRUE;
}

typedef struct {
	ElementType data[MAXSIZE];
	int length;
} SqList;

//init sequence list
Status InitList(SqList *L)
{
	L->length = 0;
	return TRUE;
}

//judge if list empty is
Status ListEmpty(SqList sl) {
	if (sl.length == 0)
		return TRUE;
	else
		return FALSE;
}

//clear sequence list
Status ClearList(SqList *sl) {
	sl->length = 0;
	return TRUE;
}

// return list length
int ListLength(SqList sl) {
	return sl.length;
}

/*Condition:0¡Üi¡ÜListLength
according to index return element
*/
Status GetElem(SqList sl, int i, ElementType *et) {
	if (sl.length == 0 || i<0 || i > sl.length - 1)
		return FALSE;
	*et = sl.data[i];

	return TRUE;
}

/*Condition:ListLength>0
according to element return element's index
*/
int locateElem(SqList sl, ElementType et) {
	int i;
	if (sl.length == 0) {
		return FALSE;
	}
	for (i = 0; i < sl.length; i++) {
		if (sl.data[i] == et)
			break;
	}
	if(i>=sl.length)
		return FALSE;
	return i;
}

/*Condition:!=MAXSIZE; 0¡Üi¡ÜListLength
insert element in position i
*/
Status ListInsert(SqList *sl, int i, ElementType et) {
	int k;
	if (sl->length == MAXSIZE) {
		return FALSE;
	}
	if (i<0 || i>sl->length) {
		return FALSE;
	}
	// not final position
	if (i < sl->length) {
		for (int k = sl->length-1; k >= i; k--) 
			sl->data[k + 1] = sl->data[k];
	}
	sl->data[i] = et;
	sl->length++;
	return TRUE;
}

/*Condition:ListLength!=0; 0¡Üi¡ÜListLength
delete element according to index
return deleted element
*/
Status ListDelete(SqList *sl, int i, ElementType *et) {
	int k;
	if (sl->length == 0) {
		return FALSE;
	}
	if (i<0 || i>sl->length - 1) {
		return FALSE;
	}
	*et = sl->data[i];
	// not final position
	if (i < sl->length - 1) {
		for (k = i; k < sl->length-1; k++)
			sl->data[k] = sl->data[k + 1];
	}
	sl->length--;
	return TRUE;
}

Status ListTraverse(SqList sl) {
	int i;
	for (i = 0; i < sl.length; i++) 
		visit(sl.data[i]);
	printf("\n");
	return TRUE;
}

int main()
{
	SqList sl;
	SqList lb;
	ElementType et;
	Status i;
	int j, k;
	i = InitList(&sl);
	printf("after Initialization:sl.length=%d\n", sl.length);

	for (j = 0; j <= 5; j++)
		i = ListInsert(&sl, 0, j);
	printf("after we insert from 0 to 5:sl.data=");

	ListTraverse(sl);
	printf("sl.length=%d \n", sl.length);

	i = ListEmpty(sl);
	printf("if L is null:i=%d(1:True 0:False) \n", i);

	i = ClearList(&sl);
	printf("after clear:sl.length=%d\n", sl.length);

	i = ListEmpty(sl);
	printf("if L is null:i=%d(1:True 0:False) \n", i);

	for (j = 0; j <= 10; j++) {
		ListInsert(&sl, j, j);
	}
	printf("after we insert from 0 to 10:sl.data=");
	ListTraverse(sl);
	printf("sl.length=%d \n", sl.length);

	ListInsert(&sl, 0, 0);
	printf("after we insert 0 in head:sl.data=");
	ListTraverse(sl);
	printf("sl.length=%d \n", sl.length);

	GetElem(sl, 4, &et);
	printf("the fifth element is %d \n", et);

	for (j = 3; j <= 4; j++) {
		k = locateElem(sl, j);
		if (k)
			printf("the %dth element is %d \n", k, j);
		else
			printf("without %dth element \n", j);
	}

	k = ListLength(sl);
	i = ListDelete(&sl, 5, &et);
	printf("delete %dth element is %d \n", 5, et);

	printf("output element \n");
	ListTraverse(sl);

	system("pause");
}