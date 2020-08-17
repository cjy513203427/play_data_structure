#ifndef BINARY_TREE_LINK_H
#define BINARY_TREE_LINK_H
#include "Node.h"
#include <iostream>
using namespace std;


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100


typedef int Status;

TElemType Nil = ' ';
// To build binary tree
int index = 1;
// Unit 0 stores the length of string
typedef char String[24];
String str;

class BinaryTreeLink {
public:
	Status StrAssign(String T, const char *chars);
	Status visit(TElemType e);
	// Construct empty binary tree
	Status InitBiTree(Node *T);
	/*
		Condition: binary tree is exist
		Result: destroy binary tree
	*/
	void DestroyBiTree(Node **T);
	// "#" means empty tree
	void CreateBiTree(Node** T);
	/*
		Condition: binary tree is exist
		Result: If tree is empty, return true, otherwise return false
	*/
	Status BiTreeEmpty(Node *T);
	#define ClearBiTree DestroyBiTree
	/*
		Condition: binary tree is exist
		Result: return the length of tree
	*/
	int BiTreeDepth(Node *T);
	/*
		Condition: binary tree is exist
		Result: return root of the tree
	*/
	TElemType Root(Node *T);
	/*
		Condition: binary tree is exist, p points to a node of the tree
		result: return data, which is pointed by p
	*/
	TElemType Value(Node T);
	// Assign value to node, which is pointed by p
	void Assign(Node *T,TElemType value);
	/*
		Condition: binary tree is exist
		Result: preorder traverse
	*/
	void PreOrderTraverse(Node *T);
	/*
		Condition: binary tree is exist
		Result: inorder traverse
	*/
	void InOrderTraverse(Node *T);
	/*
		Condition: binary tree is exist
		Result: postorder traverse
	*/
	void PostOrderTraverse(Node *T);

};

#endif