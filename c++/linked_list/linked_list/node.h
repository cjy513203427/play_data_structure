#pragma once
#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

// Define data type
typedef int ElemType;

class Node
{
public:
	ElemType data;
	Node *next;
};

#endif