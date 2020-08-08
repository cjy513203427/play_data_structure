#ifndef BINARY_TREE_SEQ__H
#include "Position.h"
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

// Define maximum number of nodes
#define MAX_TREE_SIZE 100
// It's the same when we use sequence structure
#define ClearBiTree InitBiTree

// Define return status
typedef int Status;
// Define data type of tree nodes
typedef int TElemType;
// Unit 0 stores root node
typedef TElemType SqBiTree[MAX_TREE_SIZE];

// Define null
TElemType Nil = 0;
class BinaryTreeSeq {
public:
	Status visit(TElemType c);
	// Construct empty binary tree
	Status InitBiTree(SqBiTree T);
	// In sequencial order generate binary tree nodes, construct sequential binary tree
	Status CreateBiTree(SqBiTree T);
	/*
	Condition: Binary tree is exist
	Result: If T is empty binary tree, return TRUE, otherwise return FALSE
	*/
	Status BiTreeEmpty(SqBiTree T);
	/*
	Condition: Binary tree is exist
	Result: Return depth of tree
	*/
	int BiTreeDepth(SqBiTree T);
	/*
	Condition: Binary tree is exist
	Result: Return root
	*/
	Status Root(SqBiTree T, TElemType *e);
	/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return value of node, which locates in the postion e(layer, serial number in this layer)
	*/
	TElemType Value(SqBiTree T, Position e);
	/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Assign new value to node, which locates in the position e
	*/
	Status Assign(SqBiTree T, Position e, TElemType value);
	/*
	Condition: Binary tree is exist, e is the node of tree
	Result: If e ist not the root node of tree, return its parents, otherwise return null
	*/
	TElemType Parent(SqBiTree T, TElemType e);
	/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return left child of e, if e has not left child, return "null"
	*/
	TElemType LeftChild(SqBiTree T, TElemType e);
	/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return right child of e, if e has not right child, return "null"
	*/
	TElemType RightChild(SqBiTree T, TElemType e);
	/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return left sibling of e. If e is left child of tree or has no left siblings, then return "null"
	*/
	TElemType LeftSibling(SqBiTree T, TElemType e);
	/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return right sibling of e. If e is right child of tree or has no right siblings, then return "null"
	*/
	TElemType RightSibling(SqBiTree T, TElemType e);

	void PreTraverse(SqBiTree T, int e);
	Status PreOrderTraverse(SqBiTree T);
	void InTraverse(SqBiTree T, int e);
	Status InOrderTraverse(SqBiTree T);
	void PostTraverse(SqBiTree T, int e);
	Status PostOrderTraverse(SqBiTree T);
	// Sequence traverse binary tree
	void LevelOrderTraverse(SqBiTree T);
	// Print binary tree according to serial number
	void Print(SqBiTree T);

};


#endif