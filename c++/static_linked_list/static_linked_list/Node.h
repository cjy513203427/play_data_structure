#pragma once
#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

// Define data type
typedef char ElemType;

class Node
{
public:
	ElemType data;
	// Cursor,if the value is equal to zero,it means pointless.
	int cur;
};

#endif