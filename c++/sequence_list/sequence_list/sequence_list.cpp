#include "sequence_list.h"

Status SqList::visit(ElementType c) {
	cout<<c <<" ";
	return TRUE;
}

//init sequence list
Status SqList::InitList(SqList *L) {
	L->length = 0;
	return TRUE;
}

//judge if list empty is
Status SqList::ListEmpty(SqList sl) {
	if (sl.length == 0)
		return TRUE;
	else
		return FALSE;
}

//clear sequence list
Status SqList::ClearList(SqList *sl) {
	sl->length = 0;
	return TRUE;
}

// return list length
int SqList::ListLength(SqList sl) {
	return sl.length;
}

/*Condition:0¡Üi¡ÜListLength
according to index return element
*/
Status SqList::GetElem(SqList sl, int i, ElementType *et) {
	if (sl.length == 0 || i<0 || i>sl.length-1) 
		return FALSE;
	*et = sl.data[i];
	return TRUE;
}

/*Condition:ListLength>0
according to element return element's index
*/
int SqList::locateElem(SqList sl, ElementType et) {
	int i;
	if (sl.length == 0)
		return FALSE;
	for (i = 0; i < sl.length; i++) {
		if (sl.data[i] == et)
			break;
	}
	if (i >= sl.length)
		return FALSE;
	return i;
	
}

/*Condition: !=MAXSIZE; 0¡Üi¡ÜListLength
insert element in position i
*/
Status SqList::ListInsert(SqList *sl, int i, ElementType et) {
	int k;
	if (sl->length == MAXSIZE)
		return FALSE;
	if (i<0 || i>sl->length)
		return FALSE;
	// not final position
	if (i < sl->length) {
		for (k = length-1; k >= i; k--) {
			sl->data[k + 1] = sl->data[k];
		}
	}
	sl->data[i] = et;
	sl->length++;
	return TRUE;
}

/*Condition:ListLength!=0; 0¡Üi¡ÜListLength
delete element according to index
return deleted element
*/
Status SqList::ListDelete(SqList *sl, int i, ElementType *et) {
	int k;
	if (sl->length == 0)
		return FALSE;
	if (i<0 || i>sl->length - 1)
		return FALSE;
	*et = sl->data[i];
	// not final position
	if (i < sl->length - 1) {
		for (k = i; k < length-1; k++)
			sl->data[k] = sl->data[k+1];
	}
	sl->length--;
	return true;
}

Status SqList::ListTraverse(SqList sl) {
	int i;
	for (i = 0; i < sl.length; i++)
		visit(sl.data[i]);
	cout << endl;
	return TRUE;
	
}

int main()
{
	SqList sl;
	SqList lb;
	ElementType et;
	Status i;
	int j, k;
	i = sl.InitList(&sl);
	cout<<"after Initialization:sl.length="<< sl.length<<endl;

	for (j = 0; j <= 5; j++)
		i = sl.ListInsert(&sl, 0, j);
	cout << "after we insert from 0 to 5:sl.data="<<endl;

	sl.ListTraverse(sl);
	cout<<"sl.length="<< sl.length<<endl;
	
	i = sl.ListEmpty(sl);
	cout<<"if L is null:i="<<i<<"(1:True 0:False)"<<endl;
	
	i = sl.ClearList(&sl);
	cout << "after clear:sl.length=" << sl.length << endl;

	i = sl.ListEmpty(sl);
	cout<<"if L is null:i="<<i<<"(1:True 0:False)"<<endl;

	for (j = 0; j <= 10; j++) {
		sl.ListInsert(&sl, j, j);
	}
	cout << "after we insert from 0 to 10:sl.data=";
	sl.ListTraverse(sl);
	cout << "sl.length="<< sl.length<<endl;

	sl.ListInsert(&sl, 0, 0);
	cout << "after we insert 0 in head:sl.data=";
	sl.ListTraverse(sl);
	cout<<"sl.length="<<sl.length<<endl;

	sl.GetElem(sl, 4, &et);
	cout<<"the 4th element is "<<et<<endl;

	for (j = 3; j <= 4; j++) {
		k = sl.locateElem(sl, j);
		if (k)
			cout << "the " << k << "th element is " << j << endl;
		else
			cout << "without "<<j<<"th element "<<endl;
	}

	k = sl.ListLength(sl);
	i = sl.ListDelete(&sl, 5, &et);
	cout << "delete "<<5<<"th element is "<<et<<endl;

	cout<<"output element "<<endl;
	sl.ListTraverse(sl);

	system("pause");
}