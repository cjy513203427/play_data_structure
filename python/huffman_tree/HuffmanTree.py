# -*- encoding: utf-8 -*-
'''
@File    :   HuffmanTree.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/9/30 16:36   Jonas           None
'''

import json


class Node(object):
    def __init__(self, data, weight):
        self.data = data
        self.weight = weight
        self.leftChild = None
        self.rightChild = None

    def __str__(self):
        return "Node[data= %s, weight= %s]" % (self.data, self.weight)


# Construct huffman tree
class HuffmanTree(object):

    def createTree(self, nodes):
        # As long as nodes array has more than 1 node
        while len(nodes) > 1:
            self.quickSort(nodes)
            # Get two nodes, whose value is smallest
            left = nodes[len(nodes) - 1]
            right = nodes[len(nodes) - 2]

            # Generate a new node, whose value is equal to the sum of two subnodes
            parent = Node(None, left.weight + right.weight)

            # Let new node to be parent node of two nodes, whose value is smallest
            parent.leftChild = left
            parent.rightChild = right

            # Delete two nodes, whose value is smallest
            del nodes[len(nodes) - 1]
            del nodes[len(nodes) - 1]

            # Put new node into the list
            nodes.append(parent)

        return nodes[0]

    # Swap element, whose index is i, and element, whose index is j
    def swap(self, nodes, i, j):
        tmp = nodes[i]
        nodes[i] = nodes[j]
        nodes[j] = tmp

    # Implement quicksort, in order to sort the nodes
    def subSort(self, nodes, start, end):
        if start < end:
            # Use the first element as boundary value
            base = nodes[start]
            # i searchs from the left, searchs the index of the element, whose value is bigger than boundary value.
            i = start
            # j searchs from the right, searchs the index of the element, whose value is smaller than boundary value.
            j = end + 1
            while True:
                # Find the index of element, whose value is bigger than boundary value, or i has arrived 'end'
                i += 1
                while i < end and nodes[i].weight >= base.weight:
                    i += 1
                # Find the index of element, whose value is smaller than boundary value, or j has arrived 'start'
                j -= 1
                while j > start and nodes[j].weight <= base.weight:
                    j -= 1

                if i < j:
                    self.swap(nodes, i, j)
                else:
                    break

            self.swap(nodes, start, j)

            # Recursive left subsequence
            self.subSort(nodes, start, j - 1)
            # Recursive right subsequence
            self.subSort(nodes, j + 1, end)

    def quickSort(self, nodes):
        self.subSort(nodes, 0, len(nodes) - 1)

    # Breadth first traversal
    def breadthFirst(self, root):
        queue = []
        list = []

        if root is not None:
            # Add root element to 'queue'
            queue.append(root)

        while len(queue) != 0:
            # Add the head of queue to the list
            list.append(queue[0])
            p = queue[0]
            del queue[0]

            # If left child node is not null, add it to the queue
            if p.leftChild is not None:
                queue.append(p.leftChild)

            # If right child node is not null, add it to the queue
            if p.rightChild is not None:
                queue.append(p.rightChild)

        return list


'''
                100*
               /    \
             40     60*
                    / \
                 30*  30
                 /\
               10 20*
                  / \
                10*  10
                /\
               2  8

'''

if __name__ == '__main__':
    nodes = []
    nodes.append(Node("A", 40.0))
    nodes.append(Node("B", 8.0))
    nodes.append(Node("C", 10.0))
    nodes.append(Node("D", 30.0))
    nodes.append(Node("E", 10.0))
    nodes.append(Node("F", 2.0))

    ht = HuffmanTree()

    root = ht.createTree(nodes)

    for i in ht.breadthFirst(root):
        print(i)
