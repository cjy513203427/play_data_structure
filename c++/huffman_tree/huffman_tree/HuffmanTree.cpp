#include "Node.h"
#include "HuffmanTree.h"

// Construct huffman tree
Node HuffmanTree::createTree(Node Nodes[], int len) {
    // As long as nodes array has more than 1 node
    while (len > 1) {
        quickSort(Nodes, len);
        // Get two nodes, whose value is smallest
        Node left = Nodes[len - 1];
        Node right = Nodes[len - 2];

        // Generate a new node, whose value is equal to the sum of two subnodes
        Node *parent = new Node();
        parent->data = NULL;
        parent->weight = left.weight + right.weight;

        // Let new node to be parent node of two nodes, whose value is smallest
        parent->leftChild = &left;
        parent->rightChild = &right;

        // Delete two nodes, whose value is smallest
        Nodes[len - 1] = Nodes[len];
        len--;
        Nodes[len - 1] = Nodes[len];
        len--;

        // Put new node into the list
        Nodes[len] = *parent;
        len++;
    }
    return Nodes[0];
}

// Swap element, whose index is i, and element, whose index is j
Status HuffmanTree::swap(Node Nodes[], int i, int j) {
    Node tmp = Nodes[i];
    Nodes[i] = Nodes[j];
    Nodes[j] = tmp;
    return true;
}

// Implement quicksort, in order to sort the nodes
void HuffmanTree::subSort(Node Nodes[], int start, int end) {
    if (start < end) {
        // Use the first element as boundary value
        Node base = Nodes[start];
        // i searchs from the left, searchs the index of the element, whose value is bigger than boundary value.
        int i = start;
        // j searchs from the right, searchs the index of the element, whose value is smaller than boundary value.
        int j = end + 1;
        while (true) {
            // Find the index of element, whose value is bigger than boundary value, or i has arrived 'end'
            while (i < end && Nodes[++i].weight >= base.weight);
            // Find the index of element, whose value is smaller than boundary value, or j has arrived 'start'
            while (j > start && Nodes[--j].weight <= base.weight);

            if (i < j) {
                swap(Nodes, i, j);
            }
            else {
                break;
            }
        }

        swap(Nodes, start, j);
        // Recursive left subsequence
        subSort(Nodes, start, j - 1);
        // Recursive right subsequence
        subSort(Nodes, j + 1, end);
    }
}

Status HuffmanTree::quickSort(Node Nodes[], int len) {
    subSort(Nodes, 0, len - 1);
    return true;
}

// Breadth first traversal
Node* HuffmanTree::breadthFirst(Node* root) {
    Node queue[MAX_TREE_SIZE];
    Node list[MAX_TREE_SIZE];

    if (root != NULL)
        // Add root element to 'queue'
        queue[sizeof(queue) / sizeof(queue[0])] = *root;

    while (sizeof(queue) / sizeof(queue[0]) != 0) {
        // Add the head of queue to the list
        list[sizeof(queue) / sizeof(queue[0])] = queue[0];

        // Removes the first element from queue and returns it.
        Node p = queue[0];
        for (int i = 0; i < sizeof(queue) / sizeof(queue[0]); ++i) {
            // copy next element left
            queue[i] = queue[i + 1];
        }

        // If left child node is not null, add it to the queue
        if (p.leftChild != NULL)
            queue[sizeof(queue) / sizeof(queue[0])] = *p.leftChild;

        // If right child node is not null, add it to the queue
        if (p.rightChild != NULL)
            queue[sizeof(queue) / sizeof(queue[0])] = *p.rightChild;
    }

    return list;
}

/*
 *           100*
 *         /    \
 *       40     60*
 *             / \
 *           30*  30
 *           /\
 *         10 20*
 *            / \
 *          10*  10
 *          /\
 *         2  8
 **/

int main() {

    Node* node1 = new Node();
    node1->data = 'A';
    node1->weight = 40;

    Node* node2 = new Node();
    node2->data = 'B';
    node2->weight = 8;

    Node* node3 = new Node();
    node3->data = 'C';
    node3->weight = 10;

    Node* node4 = new Node();
    node4->data = 'D';
    node4->weight = 30;

    Node* node5 = new Node();
    node5->data = 'E';
    node5->weight = 10;

    Node* node6 = new Node();
    node6->data = 'F';
    node6->weight = 2;

    Node Nodes[MAX_TREE_SIZE] = { *node1,*node2,*node3,*node4,*node5,*node6 };
    int len = sizeof(Nodes) / sizeof(Nodes[0]);

    HuffmanTree* ht = new HuffmanTree();
    Node root = ht->createTree(Nodes, len);
    cout << ht->breadthFirst(&root);

    system("pause");
    return 0;
}