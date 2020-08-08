#include "BinaryTreeSeq.h"
#include "Position.h"

Status BinaryTreeSeq::visit(TElemType c) {
	cout << c << " ";
	return OK;
}

// Construct empty binary tree
Status BinaryTreeSeq::InitBiTree(SqBiTree T)
{
	int i;
	for (i = 0; i<MAX_TREE_SIZE; i++)
		// Initial value is null
		T[i] = Nil;
	return OK;
}

// In sequencial order generate binary tree nodes, construct sequential binary tree
Status BinaryTreeSeq::CreateBiTree(SqBiTree T)
{
	int i = 0;
	printf("In sequencial order generate binary tree nodes, 0 is null node, until 99 is over. Number of nodes¡Ü%d:\n", MAX_TREE_SIZE);
	while (i<10)
	{
		T[i] = i + 1;
		// If this node is not null and not root node, has no parents 
		if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
		{
			printf("Nodes, which are no root node and have not parents node, appear %d\n", T[i]);
			exit(ERROR);
		}
		i++;
	}
	while (i<MAX_TREE_SIZE)
	{
		// Assign null to node after T node
		T[i] = Nil;
		i++;
	}

	return OK;
}

/*
	Condition: Binary tree is exist
	Result: If T is empty binary tree, return TRUE, otherwise return FALSE
*/
Status BinaryTreeSeq::BiTreeEmpty(SqBiTree T)
{
	// If root node is null, binary tree is empty
	if (T[0] == Nil)
		return TRUE;
	else
		return FALSE;
}

/*
	Condition: Binary tree is exist
	Result: Return depth of tree
*/
int BinaryTreeSeq::BiTreeDepth(SqBiTree T)
{
	int i, j = -1;
	// Find the last node
	for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
		if (T[i] != Nil)
			break;
	i++;
	do
		j++;
	// Calculate 2^j
	while (i >= powl(2, j));
	return j;
}

/*
	Condition: Binary tree is exist
	Result: Return root
*/
Status BinaryTreeSeq::Root(SqBiTree T, TElemType *e)
{
	if (BiTreeEmpty(T))
		return ERROR;
	else
	{
		*e = T[0];
		return OK;
	}
}


/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return value of node, which locates in the postion e(layer, serial number in this layer)
*/
TElemType BinaryTreeSeq::Value(SqBiTree T, Position e)
{
	return T[(int)powl(2, e.level - 1) + e.order - 2];
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Assign new value to node, which locates in the position e
*/
Status BinaryTreeSeq::Assign(SqBiTree T, Position e, TElemType value)
{
	// Converse layer, serial number of this layer to serial number of matrix
	int i = (int)powl(2, e.level - 1) + e.order - 2;
	// If we assign value to leaves nodes, whose parents nodes are empty
	if (value != Nil && T[(i + 1) / 2 - 1] == Nil)
		return ERROR;
	// If we assign null value to parents nodes, whose leaves nodes are not empty
	else if (value == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil))
		return ERROR;
	T[i] = value;
	return OK;
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: If e ist not the root node of tree, return its parents, otherwise return null
*/
TElemType BinaryTreeSeq::Parent(SqBiTree T, TElemType e)
{
	int i;
	// If this is an empty tree
	if (T[0] == Nil)
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
		if (T[i] == e)
			return T[(i + 1) / 2 - 1];
	return Nil;
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return left child of e, if e has not left child, return "null"
*/
TElemType BinaryTreeSeq::LeftChild(SqBiTree T, TElemType e)
{
	int i;
	// If this is an empty tree
	if (T[0] == Nil)
		return Nil;
	for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
		if (T[i] == e)
			return T[i * 2 + 1];
	return Nil;
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return right child of e, if e has not right child, return "null"
*/
TElemType BinaryTreeSeq::RightChild(SqBiTree T, TElemType e)
{
	int i;
	// If this is an empty tree
	if (T[0] == Nil)
		return Nil;
	for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
		if (T[i] == e)
			return T[i * 2 + 2];
	return Nil;
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return left sibling of e. If e is left child of tree or has no left siblings, then return "null"
*/
TElemType BinaryTreeSeq::LeftSibling(SqBiTree T, TElemType e)
{
	int i;
	// If this is an empty tree
	if (T[0] == Nil)
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
		if (T[i] == e && i % 2 == 0)
			return T[i - 1];
	return Nil;
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return right sibling of e. If e is right child of tree or has no right siblings, then return "null"
*/
TElemType BinaryTreeSeq::RightSibling(SqBiTree T, TElemType e)
{
	int i;
	// If this is an empty tree
	if (T[0] == Nil)
		return Nil;
	for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
		if (T[i] == e && i % 2)
			return T[i + 1];
	return Nil;
}

void BinaryTreeSeq::PreTraverse(SqBiTree T, int e)
{
	visit(T[e]);
	if (T[2 * e + 1] != Nil) /* ×ó×ÓÊ÷²»¿Õ */
		PreTraverse(T, 2 * e + 1);
	if (T[2 * e + 2] != Nil) /* ÓÒ×ÓÊ÷²»¿Õ */
		PreTraverse(T, 2 * e + 2);
}

Status BinaryTreeSeq::PreOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T)) /* Ê÷²»¿Õ */
		PreTraverse(T, 0);
	printf("\n");
	return OK;
}

void BinaryTreeSeq::InTraverse(SqBiTree T, int e)
{
	if (T[2 * e + 1] != Nil) /* ×ó×ÓÊ÷²»¿Õ */
		InTraverse(T, 2 * e + 1);
	visit(T[e]);
	if (T[2 * e + 2] != Nil) /* ÓÒ×ÓÊ÷²»¿Õ */
		InTraverse(T, 2 * e + 2);
}

Status BinaryTreeSeq::InOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T)) /* Ê÷²»¿Õ */
		InTraverse(T, 0);
	printf("\n");
	return OK;
}

void BinaryTreeSeq::PostTraverse(SqBiTree T, int e)
{
	if (T[2 * e + 1] != Nil) /* ×ó×ÓÊ÷²»¿Õ */
		PostTraverse(T, 2 * e + 1);
	if (T[2 * e + 2] != Nil) /* ÓÒ×ÓÊ÷²»¿Õ */
		PostTraverse(T, 2 * e + 2);
	visit(T[e]);
}

Status BinaryTreeSeq::PostOrderTraverse(SqBiTree T)
{
	if (!BiTreeEmpty(T)) /* Ê÷²»¿Õ */
		PostTraverse(T, 0);
	printf("\n");
	return OK;
}

// Sequence traverse binary tree
void BinaryTreeSeq::LevelOrderTraverse(SqBiTree T)
{
	int i = MAX_TREE_SIZE - 1, j;
	// From the root node, traverse binary tree sequencial
	for (j = 0; j <= i; j++)
		if (T[j] != Nil)
			visit(T[j]);
	printf("\n");
}

// Print binary tree according to serial number
void BinaryTreeSeq::Print(SqBiTree T)
{
	int j, k;
	Position p;
	TElemType e;
	for (j = 1; j <= BiTreeDepth(T); j++)
	{
		printf("%dth layer: ", j);
		for (k = 1; k <= powl(2, j - 1); k++)
		{
			p.level = j;
			p.order = k;
			e = Value(T, p);
			if (e != Nil)
				printf("%d:%d ", k, e);
		}
		printf("\n");
	}
}

/*
1
/        \
2		        3
/   \          /  \
4     5		  6    7
/ \    /
8   9  10
*/

int main()
{
	Status i;
	// struct
	Position p;
	TElemType e;
	// tree array
	SqBiTree T;
	BinaryTreeSeq bts;
	bts.InitBiTree(T);
	bts.CreateBiTree(T);
	printf("After constructing binary tree, if tree is empty?%d(1:true 0:false) depth of tree=%d\n", bts.BiTreeEmpty(T), bts.BiTreeDepth(T));
	i = bts.Root(T, &e);
	if (i)
		printf("Root of the binary tree:%d\n", e);
	else
		printf("Tree is empty, no root\n");
	printf("LevelOrderTraverse:\n");
	bts.LevelOrderTraverse(T);
	printf("PreOrderTraverse:\n");
	bts.PreOrderTraverse(T);
	printf("InOrderTraverse:\n");
	bts.InOrderTraverse(T);
	printf("PostOrderTraverse:\n");
	bts.PostOrderTraverse(T);
	printf("Change node, whose layer is 3 and serial number of this layer is 2\n");
	p.level = 3;
	p.order = 2;
	e = bts.Value(T, p);
	printf("", e);
	printf("Node to be modified is %d please input new value: 50 \n", e);
	e = 50;
	bts.Assign(T, p, e);
	printf("Preorder:\n");
	bts.PreOrderTraverse(T);
	printf("Node %d's parents are %d, left and right child are ", e, bts.Parent(T, e));
	printf("%d,%d,left and right siblings are ", bts.LeftChild(T, e), bts.RightChild(T, e));
	printf("%d,%d\n", bts.LeftSibling(T, e), bts.RightSibling(T, e));
	bts.ClearBiTree(T);
	printf("After clearing binary tree, if tree is empty?%d(1:true 0:false) depth of tree=%d\n", bts.BiTreeEmpty(T), bts.BiTreeDepth(T));
	i = bts.Root(T, &e);
	if (i)
		printf("Root of binary tree is:%d\n", e);
	else
		printf("Tree is empty, no root\n");

	system("pause");
	return 0;
}
