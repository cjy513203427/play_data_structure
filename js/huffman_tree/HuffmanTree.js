function Node(props) {
    this.data = props.data
    this.weight = props.weight
    this.leftChild = null
    this.rightChild = null
}

function HuffmanTree() {}

// Construct huffman tree
HuffmanTree.prototype.createTree = function(nodes){
    // As long as nodes array has more than 1 node
    while (nodes.length>1){
        this.quickSort(nodes)
        // Get two nodes, whose value is smallest
        left = nodes[nodes.length-1]
        right = nodes[nodes.length-2]

        // Generate a new node, whose value is equal to the sum of two subnodes
        parent = new Node({data:null, weight:left.weight+right.weight})

        // Let new node to be parent node of two nodes, whose value is smallest
        parent.leftChild = left
        parent.rightChild = right

        // Delete two nodes, whose value is smallest
        nodes.pop()
        nodes.pop()

        // Put new node into the list
        nodes.push(parent)
}

    return nodes[0]
}

// Swap element, whose index is i, and element, whose index is j
HuffmanTree.prototype.swap = function(nodes, i, j){
    tmp = nodes[i]
    nodes[i] = nodes[j]
    nodes[j] = tmp
}

// Implement quicksort, in order to sort the nodes
HuffmanTree.prototype.subSort = function(nodes, start, end) {
    if(start<end){
        // Use the first element as boundary value
        base = nodes[start]
        // i searchs from the left, searchs the index of the element, whose value is bigger than boundary value.
        i = start
        // j searchs from the right, searchs the index of the element, whose value is smaller than boundary value.
        j = end + 1
        while (true) {
            // Find the index of element, whose value is bigger than boundary value, or i has arrived 'end'
            while (i < end && nodes[++i].weight >= base.weight);
            // Find the index of element, whose value is smaller than boundary value, or j has arrived 'start'
            while (j > start && nodes[--j].weight <= base.weight);

            if (i < j) {
                this.swap(nodes, i, j);
            } else {
                break;
            }
        }

        this.swap(nodes, start, j)

        // Recursive left subsequence
        this.subSort(nodes, start, j-1)
        // Recursive right subsequence
        this.subSort(nodes, j+1, end)
    }
}

HuffmanTree.prototype.quickSort = function(nodes) {
    this.subSort(nodes, 0, nodes.length-1)
}

// Breadth first traversal
HuffmanTree.prototype.breadthFirst = function(root) {
    queue = new Array()
    list = new Array()

    if(root != null)
        // Add root element to 'queue'
        queue.push(root)

    while (queue.length != 0){
        // Add the head of queue to the list
        list.push(queue[0])
        // Removes the first element from queue and returns it.
        p = queue.shift()

        // If left child node is not null, add it to the queue
        if(p.leftChild != null)
            queue.push(p.leftChild)

        // If right child node is not null, add it to the queue
        if(p.rightChild != null)
            queue.push(p.rightChild)
    }

    return list
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

var ht = new HuffmanTree()
var nodes = new Array()
nodes.push(new Node({data:"A", weight:40.0}))
nodes.push(new Node({data:"B", weight:8.0}))
nodes.push(new Node({data:"C", weight:10.0}))
nodes.push(new Node({data:"D", weight:30.0}))
nodes.push(new Node({data:"E", weight:10.0}))
nodes.push(new Node({data:"F", weight:2.0}))

root = ht.createTree(nodes)
console.log(ht.breadthFirst(root))

