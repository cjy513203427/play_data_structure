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

// Define capacity of space
#define MAXSIZE 100
// Define status code
typedef int Status;
typedef char TElemType;
/*
	Link == 0 means that, it points to lchild or rchild 
	Thread == 1 means that, it points to precursor node or subsequent node
*/
typedef enum { Link, Thread } PointerTag;
// Thread binary tree node structure
typedef  struct BiThrNode
{
	TElemType data;
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag;
	PointerTag RTag;
} BiThrNode, * BiThrTree;

// Define null string
TElemType Nil = '#'; 

Status visit(TElemType e)
{
	printf("%c ", e);
	return OK;
}

/*
	Input node value of thread binary tree with preorder, construct thread binary tree T
*/
Status CreateBiThrTree(BiThrTree* T)
{
	TElemType h;
	scanf_s("%c", &h);

	if (h == Nil)
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if (!*T)
			exit(OVERFLOW);
		// Generate root node(preorder)
		(*T)->data = h;
		// Recursive construct left subtree
		CreateBiThrTree(&(*T)->lchild);
		// If it has left child
		if ((*T)->lchild) /* газѓКЂзг */
			(*T)->LTag = Link;
		// Recursive construct right subtree
		CreateBiThrTree(&(*T)->rchild);
		// If it has right child
		if ((*T)->rchild)
			(*T)->RTag = Link;
	}
	return OK;
}

// Global variable, that points to visited node
BiThrTree pre;
// Use Inorder traverse to make binary tree threaded
void InThreading(BiThrTree p)
{
	if (p)
	{
		// Recursive left subtree threaded
		InThreading(p->lchild);
		// If it has no left child
		if (!p->lchild)
		{
			// Precursor threaded
			p->LTag = Thread;
			// Left child points to precursor node
			p->lchild = pre;
		}
		// If it has no right child
		if (!pre->rchild)
		{
			// Successor threaded
			pre->RTag = Thread;
			// Right child of precursor node points to successor(current node p)
			pre->rchild = p;
		}
		// Pre points to precursor of p
		pre = p;
		// Recursive right subtree threaded
		InThreading(p->rchild);
	}
}

// Inorder traverse binary tree T, make it inorder threaded, Thrt points to head node
Status InOrderThreading(BiThrTree* Thrt, BiThrTree T)
{
	*Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
	if (!*Thrt)
		exit(OVERFLOW);
	// Constructing head node
	(*Thrt)->LTag = Link;
	(*Thrt)->RTag = Thread;
	// Rchild points to self
	(*Thrt)->rchild = (*Thrt);
	if (!T)
		// If binary tree is empty, lchild points to self
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		// Inorder threaded
		InThreading(T);
		pre->rchild = *Thrt;
		// Make last node threaded
		pre->RTag = Thread; 
		(*Thrt)->rchild = pre;
	}
	return OK;
}

// Preorder traverse thread binary tree (Non-recursive algorithm)
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	// p points to root node, T is head node
	p = T->lchild;
	// When the thread binary tree is not empty
	while (p != T)
	{
		// A->B->D->H
		while (p->LTag == Link)
			p = p->lchild;
		// No use
		if (!visit(p->data))
			return ERROR;
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			// Print The subsequent node
			visit(p->data);
		}
		p = p->rchild;
	}
	return OK;
}

/*
			   A
			  / \
			B     C
		   / \   / \
		  D   E F   G
		 / \ / 
		H  I J
*/
int main()
{
	BiThrTree H, T;
	printf("Input binary tree according to preorder(like:'ABDH##I##EJ###CF##G##')\n");
	// Construct binary tree according to preorder
	CreateBiThrTree(&T);
	// Inorder traverse binary tree T, make it inorder threaded
	InOrderThreading(&H, T);
	printf("Inorder print thread binary tree:\n");
	InOrderTraverse_Thr(H);
	printf("\n");

	system("pause");
	return 0;
}