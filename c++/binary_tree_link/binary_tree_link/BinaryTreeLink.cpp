#include "Node.h"
#include "BinaryTreeLink.h"


Status BinaryTreeLink::StrAssign(String T, const char *chars)
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

Status BinaryTreeLink::visit(TElemType e)
{
	cout << e << " ";
	return OK;
}

// Construct empty binary tree
Status BinaryTreeLink::InitBiTree(Node *T)
{
	T = NULL;
	return OK;
}

/*
	Condition: binary tree is exist
	Result: destroy binary tree
*/
void BinaryTreeLink::DestroyBiTree(Node **T)
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
void BinaryTreeLink::CreateBiTree(Node** T)
{
	TElemType ch;

	ch = str[index++];

	if (ch == '#')
		*T = NULL;
	else
	{
		*T = new Node();
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

// "#" means empty tree
//void BinaryTreeLink::CreateBiTree1(Node* T)
//{
//	TElemType ch;
//
//	ch = str[index++];
//
//	if (ch == '#')
//		T = NULL;
//	else
//	{
//		T = new Node();
//		if (!T)
//			exit(OVERFLOW);
//		// Generate root node
//		T->data = ch;
//		// Construct left subtree
//		CreateBiTree1(T->lchild);
//		// Construct right subtree
//		CreateBiTree1(T->rchild);
//	}
//}

/*
	Condition: binary tree is exist
	Result: If tree is empty, return true, otherwise return false
*/
Status BinaryTreeLink::BiTreeEmpty(Node *T)
{
	if (T)
		return FALSE;
	else
		return TRUE;
}

/*
	Condition: binary tree is exist
	Result: return the length of tree
*/
int BinaryTreeLink::BiTreeDepth(Node *T)
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
TElemType BinaryTreeLink::Root(Node *T)
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
TElemType BinaryTreeLink::Value(Node T)
{
	return T.data;
}

// Assign value to node, which is pointed by p
void BinaryTreeLink::Assign(Node *T,TElemType value)
{
	T->data = value;
}

/*
	Condition: binary tree is exist
	Result: preorder traverse
*/
void BinaryTreeLink::PreOrderTraverse(Node *T)
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
void BinaryTreeLink::InOrderTraverse(Node *T)
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
void BinaryTreeLink::PostOrderTraverse(Node *T)
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
	Node *T = new Node();
	TElemType e1;
	BinaryTreeLink btl;
	btl.InitBiTree(T);


	btl.StrAssign(str, "ABDH#K###E##CFI###G#J##");

	btl.CreateBiTree(&T);

	printf("After constructing empty binary tree, if the tree is empty? %d(1:true 0:false) depth of the tree is=%d\n", btl.BiTreeEmpty(T), btl.BiTreeDepth(T));
	e1 = btl.Root(T);
	printf("Root of binary tree is: %c\n", e1);

	printf("\n Preorder traverse:");
	btl.PreOrderTraverse(T);
	printf("\n Inorder traverse:");
	btl.InOrderTraverse(T);
	printf("\n Postorder traverse:");
	btl.PostOrderTraverse(T);
	btl.ClearBiTree(&T);
	printf("\n After clearing binary tree, if the tree is empty? %d(1:true 0:false) depth of the tree is=%d\n", btl.BiTreeEmpty(T), btl.BiTreeDepth(T));
	i = btl.Root(T);
	if (!i)
		printf("Tree is empty, no root\n");

	system("pause");
	return 0;
}

