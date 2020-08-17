#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int Status;

// To build binary tree
int index = 1;
// Unit 0 stores the length of string
typedef char String[24];
String str;

Status StrAssign(String T, const char *chars)
{
	int i;
	if (strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}
typedef char TElemType;
TElemType Nil = ' ';

Status visit(TElemType e)
{
	printf("%c ", e);
	return OK;
}

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


// Construct empty binary tree
Status InitBiTree(BiTree *T)
{
	*T = NULL;
	return OK;
}

/*
	Condition: binary tree is exist
	Result: destroy binary tree
*/
void DestroyBiTree(BiTree *T)
{
	if (*T)
	{
		// If tree has left child
		if ((*T)->lchild)
			// Destroy subtree of left child
			DestroyBiTree(&((*T)->lchild));
		// If tree has right child
		if ((*T)->rchild)
			// Destroy subtree of right child
			DestroyBiTree(&((*T)->rchild));
		// Relese root node
		free(*T);
		*T = NULL;
	}
}


// "#" means empty tree
void CreateBiTree(BiTree *T)
{
	TElemType ch;

	ch = str[index++];

	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(OVERFLOW);
		// Generate root node
		(*T)->data = ch;
		// Construct left subtree
		CreateBiTree(&(*T)->lchild);
		// Construct right subtree
		CreateBiTree(&(*T)->rchild);
	}
}

/*
	Condition: binary tree is exist
	Result: If tree is empty, return true, otherwise return false
*/
Status BiTreeEmpty(BiTree T)
{
	if (T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/*
	Condition: binary tree is exist
	Result: return the length of tree
*/
int BiTreeDepth(BiTree T)
{
	int i, j;
	if (!T)
		return 0;
	if (T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if (T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i>j ? i + 1 : j + 1;
}

/*
	Condition: binary tree is exist
	Result: return root of the tree
*/
TElemType Root(BiTree T)
{
	if (BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/*
	Condition: binary tree is exist, p points to a node of the tree
	result: return data, which is pointed by p
*/
TElemType Value(BiTree p)
{
	return p->data;
}

// Assign value to node, which is pointed by p
void Assign(BiTree p, TElemType value)
{
	p->data = value;
}

/*
	Condition: binary tree is exist
	Result: preorder traverse
*/
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/*
	Condition: binary tree is exist
	Result: inorder traverse
*/
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

/*
	Condition: binary tree is exist
	Result: postorder traverse
*/
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}


int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);


	StrAssign(str, "ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("After constructing empty binary tree, if the tree is empty? %d(1:true 0:false) depth of the tree is=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	e1 = Root(T);
	printf("Root of binary tree is: %c\n", e1);

	printf("\n Preorder traverse:");
	PreOrderTraverse(T);
	printf("\n Inorder traverse:");
	InOrderTraverse(T);
	printf("\n Postorder traverse:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n After clearing binary tree, if the tree is empty? %d(1:true 0:false) depth of the tree is=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	i = Root(T);
	if (!i)
		printf("Tree is empty, no root\n");

	system("pause");
	return 0;
}
