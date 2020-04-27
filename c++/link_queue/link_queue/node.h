#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
// Define data type
typedef int QElemType;
class QNode {
public:
	QElemType data;
	QNode *next;
};

#endif