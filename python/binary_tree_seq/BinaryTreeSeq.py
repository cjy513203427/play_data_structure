# -*- encoding: utf-8 -*-
'''
@File    :   BinaryTreeSeq.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/8/10 11:44   Jonas           None
'''
import math

import numpy as np

MAX_TREE_SIZE = 100


class Position(object):
    def __init__(self,level,order):
        self.level = 0 or level
        self.order = 0 or order


class BinaryTreeSeq(object):
    def __init__(self):
        self.SqBiTree = np.zeros(MAX_TREE_SIZE)

    def visit(self, element):
        print(element,end=" ")
        return True

    # Construct empty binary tree
    def InitBiTree(self):
        for i in range(0, MAX_TREE_SIZE):
            # Initial value is null
            self.SqBiTree[i] = 0
        return True

    # In sequencial order generate binary tree nodes, construct sequential binary tree
    def CreateBiTree(self):
        print(
            "In sequencial order generate binary tree nodes, 0 is null node, until 99 is over. Number of nodes≤%d:\n"
            % MAX_TREE_SIZE)
        i = 0
        while i < 10:
            self.SqBiTree[i] = i + 1
            # If this node is not null and not root node, has no parents
            if i != 0 and self.SqBiTree[math.floor((i + 1) / 2) - 1] == 0 and self.SqBiTree[i] != 0:
                print("Nodes, which are no root node and have not parents node, appear %d\n" % self.SqBiTree[i])
                return False
            i += 1

        while i < MAX_TREE_SIZE:
            # Assign null to node after T node
            self.SqBiTree[i] = 0
            i += 1

        return True

    # Condition: Binary tree is exist
    # Result: If T is empty binary tree, return TRUE, otherwise return FALSE
    def BiTreeEmpty(self):
        # If root node is null, binary tree is empty
        if self.SqBiTree[0] == 0:
            return True
        else:
            return False

    # Condition: Binary tree is exist
    # Result: Return depth of tree
    def BiTreeDepth(self):
        j = 0
        # Find the last node
        for i in range(MAX_TREE_SIZE - 1, -1, -1):
            if self.SqBiTree[i] != 0:
                break
        i += 1
        while i >= math.pow(2, j):
            return j

    # Condition: Binary tree is exist
    # Result: Return root
    def Root(self):
        if self.BiTreeEmpty():
            return False
        else:
            e = self.SqBiTree[0]
            return e

    # Condition: Binary tree is exist, e is the node of tree
    # Result: Return value of node, which locates in the postion e(layer, serial number in this layer)
    def Value(self, e):
        return self.SqBiTree[int(math.pow(2, e.level - 1) + e.order - 2)]

    # Condition: Binary tree is exist, e is the node of tree
    # Result: Assign new value to node, which locates in the position e
    def Assign(self, e, value):
        # Converse layer, serial number of this layer to serial number of matrix
        i = int(math.pow(2, e.level - 1) + e.order - 2)
        # If we assign value to leaves nodes, whose parents nodes are empty
        if value != 0 and self.SqBiTree[math.floor((i + 1) / 2) - 1] == 0:
            return False
        # If we assign null value to parents nodes, whose leaves nodes are not empty
        elif value == 0 and (self.SqBiTree[i * 2 + 1] != 0 or self.SqBiTree[i * 2 + 2] != 0):
            return False
        self.SqBiTree[i] = value
        return True

    # Condition: Binary tree is exist, e is the node of tree
    # Result: If e ist not the root node of tree, return its parents, otherwise return null
    def Parent(self, e):
        # If this is an empty tree
        if self.SqBiTree[0] == 0:
            return 0
        for i in range(1, MAX_TREE_SIZE):
            if self.SqBiTree[i] == e:
                return self.SqBiTree[math.floor((i + 1) / 2) - 1]
        return 0

    # Condition: Binary tree is exist, e is the node of tree
    # Result: Return left child of e, if e has not left child, return "null"
    def LeftChild(self, e):
        # If this is an empty tree
        if self.SqBiTree[0] == 0:
            return 0
        for i in range(1, MAX_TREE_SIZE):
            if self.SqBiTree[i] == e:
                return self.SqBiTree[i * 2 + 1]
        return 0

    # Condition: Binary tree is exist, e is the node of tree
    # Result: Return right child of e, if e has not right child, return "null"
    def RightChild(self, e):
        # If this is an empty tree
        if self.SqBiTree[0] == 0:
            return 0
        for i in range(1, MAX_TREE_SIZE):
            if self.SqBiTree[i] == e:
                return self.SqBiTree[i * 2 + 2]
        return 0

    def LeftSibling(self, e):
        # If this is an empty tree
        if self.SqBiTree[0] == 0:
            return 0
        for i in range(1, MAX_TREE_SIZE):
            if self.SqBiTree[i] == e and i % 2 == 0:
                return self.SqBiTree[i - 1]
        return 0

    # Condition: Binary tree is exist, e is the node of tree
    # Result: Return right sibling of e. If e is right child of tree or has no right siblings, then return "null"
    def RightSibling(self, e):
        # If this is an empty tree
        if self.SqBiTree[0] == 0:
            return 0
        for i in range(1, MAX_TREE_SIZE):
            if (self.SqBiTree[i] == e and i % 2):
                return self.SqBiTree[i + 1]
        return 0

    def PreTraverse(self, e):
        self.visit(self.SqBiTree[e])
        if self.SqBiTree[2 * e + 1] != 0:
            self.PreTraverse(2 * e + 1)
        if self.SqBiTree[2 * e + 2] != 0:
            self.PreTraverse(2 * e + 2)

    def PreOrderTraverse(self):
        if not self.BiTreeEmpty():
            self.PreTraverse(0)
        print("\n")
        return True

    def InTraverse(self, e):
        if self.SqBiTree[2 * e + 1] != 0:
            self.InTraverse(2 * e + 1)
        self.visit(self.SqBiTree[e])
        if self.SqBiTree[2 * e + 2] != 0:
            self.InTraverse(2 * e + 2)

    def InOrderTraverse(self):
        if not self.BiTreeEmpty():
            self.InTraverse(0)
        print("\n")
        return True

    def PostTraverse(self, e):
        if self.SqBiTree[2 * e + 1] != 0:
            self.PostTraverse(2 * e + 1)
        if self.SqBiTree[2 * e + 2] != 0:
            self.PostTraverse(2 * e + 2)
        self.visit(self.SqBiTree[e])

    def PostOrderTraverse(self):
        if not self.BiTreeEmpty():
            self.PostTraverse(0)
        print("\n")
        return True

    # Sequence traverse binary tree
    def LevelOrderTraverse(self):
        i = MAX_TREE_SIZE - 1
        # From the root node, traverse binary tree sequencial
        for j in range(0, i + 1):
            if self.SqBiTree[j] != 0:
                self.visit(self.SqBiTree[j])
        print("\n")

    # Print binary tree according to serial number
    def Print(self):
        p = Position()
        for j in range(1, self.BiTreeDepth() + 1):
            print("%dth layer: " % j)
            for k in range(1, math.pow(2, j - 1) + 1):
                p.level = j;
                p.order = k;
                e = self.Value(p);
                if (e != 0):
                    print("%d:%d ", k, e);

            print("\n")


'''
			     1
			/        \
		  2		        3
		/   \          /  \
	   4     5		  6    7
	  / \    /
	 8   9  10
'''
if __name__ == '__main__':
    bts =  BinaryTreeSeq()

    bts.InitBiTree()
    bts.CreateBiTree()
    print("After constructing binary tree, if tree is empty?%d(1:true 0:false) depth of tree=%d\n", bts.BiTreeEmpty(), bts.BiTreeDepth())
    i = bts.Root()
    if not i:
        print("Root of the binary tree:%d\n" %i)
    else:
        print("Tree is empty, no root\n")
    print("LevelOrderTraverse:\n")
    bts.LevelOrderTraverse()
    print("PreOrderTraverse:\n")
    bts.PreOrderTraverse()
    print("InOrderTraverse:\n")
    bts.InOrderTraverse()
    print("PostOrderTraverse:\n")
    bts.PostOrderTraverse()
    print("Change node, whose layer is 3 and serial number of this layer is 2\n")

    p = Position(3,2)
    e = bts.Value(p)
    print("Node to be modified is %d please input new value: 50 \n" %e)
    e = 50
    bts.Assign(p, e)
    print("Preorder:\n")
    bts.PreOrderTraverse()
    print("Node %d's parents are %d, left and right child are " %(e, bts.Parent(e)))
    print("%d,%d,left and right siblings are " %(bts.LeftChild(e), bts.RightChild(e)))
    print("%d,%d\n" %(bts.LeftSibling(e), bts.RightSibling(e)))
    bts.InitBiTree()
    print("After clearing binary tree, if tree is empty?%d(1:true 0:false) depth of tree=%d\n" %(bts.BiTreeEmpty(), bts.BiTreeDepth()))
    i = bts.Root()
    if not i:
        print("Root of binary tree is:%d\n" %e)
    else:
        print("Tree is empty, no root\n")