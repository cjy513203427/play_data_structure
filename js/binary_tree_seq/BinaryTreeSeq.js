var MAX_TREE_SIZE = 100
var SqBiTree = new Array(MAX_TREE_SIZE)

function BinaryTreeSeq(props) {}

function Position(props) {
    this.level = props.level
    this.order = props.order
}

BinaryTreeSeq.prototype.visit = function(element) {
    process.stdout.write(element + ' ')
    return true
};

// Construct empty binary tree
BinaryTreeSeq.prototype.InitBiTree = function() {
    var i;
    for (i = 0; i < MAX_TREE_SIZE; i++)
    // Initial value is null
        SqBiTree[i] = 0
    return true
}

// In sequencial order generate binary tree nodes, construct sequential binary tree
BinaryTreeSeq.prototype.CreateBiTree = function() {
    var i = 0
    console.log("In sequencial order generate binary tree nodes, 0 is null node, until 99 is over. Number of nodes≤%d:\n", MAX_TREE_SIZE)
    while (i < 10) {
        SqBiTree[i] = i + 1
            // If this node is not null and not root node, has no parents 
        if (i != 0 && SqBiTree[Math.floor((i + 1) / 2) - 1] == 0 && SqBiTree[i] != 0) {
            console.log("Nodes, which are no root node and have not parents node, appear %d\n", SqBiTree[i])
            return false
        }
        i++
    }
    while (i < MAX_TREE_SIZE) {
        // Assign null to node after T node
        SqBiTree[i] = 0
        i++
    }

    return true
}

/*
	Condition: Binary tree is exist
	Result: If T is empty binary tree, return TRUE, otherwise return FALSE
*/
BinaryTreeSeq.prototype.BiTreeEmpty = function() {
    // If root node is null, binary tree is empty
    if (SqBiTree[0] == 0)
        return true
    else
        return false
}

/*
	Condition: Binary tree is exist
	Result: Return depth of tree
*/
BinaryTreeSeq.prototype.BiTreeDepth = function() {
    var i, j = -1
        // Find the last node
    for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
        if (SqBiTree[i] != 0)
            break
    i++
    do {
        j++
    }
    // Calculate 2^j
    while (i >= Math.pow(2, j)) {
        return j
    }
}

/*
	Condition: Binary tree is exist
	Result: Return root
*/
BinaryTreeSeq.prototype.Root = function() {
    if (bts.BiTreeEmpty())
        return false
    else {
        e = SqBiTree[0]
        return e
    }
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return value of node, which locates in the postion e(layer, serial number in this layer)
*/
BinaryTreeSeq.prototype.Value = function(e) {
    return SqBiTree[Math.pow(2, e.level - 1) + e.order - 2]
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Assign new value to node, which locates in the position e
*/
BinaryTreeSeq.prototype.Assign = function(e, value) {
    // Converse layer, serial number of this layer to serial number of matrix
    var i = Math.pow(2, e.level - 1) + e.order - 2
        // If we assign value to leaves nodes, whose parents nodes are empty
    if (value != 0 && SqBiTree[Math.floor((i + 1) / 2) - 1] == 0)
        return false
            // If we assign null value to parents nodes, whose leaves nodes are not empty
    else if (value == 0 && (SqBiTree[i * 2 + 1] != 0 || SqBiTree[i * 2 + 2] != 0))
        return false
    SqBiTree[i] = value
    return true
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: If e ist not the root node of tree, return its parents, otherwise return null
*/
BinaryTreeSeq.prototype.Parent = function(e) {
    var i
        // If this is an empty tree
    if (SqBiTree[0] == 0)
        return 0
    for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
        if (SqBiTree[i] == e)
            return SqBiTree[Math.floor((i + 1) / 2) - 1]
    return 0
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return left child of e, if e has not left child, return "null"
*/
BinaryTreeSeq.prototype.LeftChild = function(e) {
    var i
        // If this is an empty tree
    if (SqBiTree[0] == 0)
        return 0
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
        if (SqBiTree[i] == e)
            return SqBiTree[i * 2 + 1]
    return 0
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return right child of e, if e has not right child, return "null"
*/
BinaryTreeSeq.prototype.RightChild = function(e) {
    var i
        // If this is an empty tree
    if (SqBiTree[0] == 0)
        return 0
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
        if (SqBiTree[i] == e)
            return SqBiTree[i * 2 + 2]
    return 0
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return left sibling of e. If e is left child of tree or has no left siblings, then return "null"
*/
BinaryTreeSeq.prototype.LeftSibling = function(e) {
    var i
        // If this is an empty tree
    if (SqBiTree[0] == 0)
        return 0
    for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
        if (SqBiTree[i] == e && i % 2 == 0)
            return SqBiTree[i - 1]
    return 0
}

/*
	Condition: Binary tree is exist, e is the node of tree
	Result: Return right sibling of e. If e is right child of tree or has no right siblings, then return "null"
*/
BinaryTreeSeq.prototype.RightSibling = function(e) {
    var i
        // If this is an empty tree
    if (SqBiTree[0] == 0)
        return 0
    for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
        if (SqBiTree[i] == e && i % 2)
            return SqBiTree[i + 1]
    return 0
}

BinaryTreeSeq.prototype.PreTraverse = function(e) {
    bts.visit(SqBiTree[e])
    if (SqBiTree[2 * e + 1] != 0)
        bts.PreTraverse(2 * e + 1)
    if (SqBiTree[2 * e + 2] != 0)
        bts.PreTraverse(2 * e + 2)
}

BinaryTreeSeq.prototype.PreOrderTraverse = function() {
    if (!bts.BiTreeEmpty())
        bts.PreTraverse(0)
    console.log()
    return true
}

BinaryTreeSeq.prototype.InTraverse = function(e) {
    if (SqBiTree[2 * e + 1] != 0)
        bts.InTraverse(2 * e + 1)
    bts.visit(SqBiTree[e])
    if (SqBiTree[2 * e + 2] != 0)
        bts.InTraverse(2 * e + 2)
}

BinaryTreeSeq.prototype.InOrderTraverse = function() {
    if (!bts.BiTreeEmpty())
        bts.InTraverse(0)
    console.log()
    return true
}

BinaryTreeSeq.prototype.PostTraverse = function(e) {
    if (SqBiTree[2 * e + 1] != 0)
        bts.PostTraverse(2 * e + 1)
    if (SqBiTree[2 * e + 2] != 0)
        bts.PostTraverse(2 * e + 2)
    bts.visit(SqBiTree[e])
}

BinaryTreeSeq.prototype.PostOrderTraverse = function(e) {
    if (!bts.BiTreeEmpty())
        bts.PostTraverse(0)
    console.log()
    return true
}


// Sequence traverse binary tree
BinaryTreeSeq.prototype.LevelOrderTraverse = function()
{
    var i = MAX_TREE_SIZE - 1, j
    // From the root node, traverse binary tree sequencial
    for (j = 0; j <= i; j++)
        if (SqBiTree[j] != 0)
            bts.visit(SqBiTree[j])
    console.log()
}

// Print binary tree according to serial number
BinaryTreeSeq.prototype.Print = function()
{
    var j, k
    var p = new Position({})
    var e
    for (j = 1; j <= bts.BiTreeDepth(); j++)
    {
        console.log("%dth layer: ", j);
        for (k = 1; k <= Math.pow(2, j - 1); k++)
        {
            p.level = j;
            p.order = k;
            e = bts.Value(p);
            if (e != 0)
                console.log("%d:%d ", k, e);
        }
        console.log()
    }
}
/*
			     1
			/        \
		  2		        3
		/   \          /  \
	   4     5		  6    7
	  / \    /
	 8   9  10
*/


var bts = new BinaryTreeSeq({})

bts.InitBiTree()
bts.CreateBiTree()
console.log("After constructing binary tree, if tree is empty?%d(1:true 0:false) depth of tree=%d\n", bts.BiTreeEmpty(), bts.BiTreeDepth());
i = bts.Root()
if (i!=false)
    console.log("Root of the binary tree:%d\n",i)
else
    console.log("Tree is empty, no root\n")
console.log("LevelOrderTraverse:\n")
bts.LevelOrderTraverse()
console.log("PreOrderTraverse:\n")
bts.PreOrderTraverse()
console.log("InOrderTraverse:\n")
bts.InOrderTraverse()
console.log("PostOrderTraverse:\n")
bts.PostOrderTraverse()
console.log("Change node, whose layer is 3 and serial number of this layer is 2\n")

var p = new Position({ level: 3, order: 2 })
e = bts.Value(p)
console.log("Node to be modified is %d please input new value: 50 \n", e)
e = 50
bts.Assign(p, e)
console.log("Preorder:\n")
bts.PreOrderTraverse()
console.log("Node %d's parents are %d, left and right child are ", e, bts.Parent(e))
console.log("%d,%d,left and right siblings are ", bts.LeftChild(e), bts.RightChild(e))
console.log("%d,%d\n", bts.LeftSibling(e), bts.RightSibling(e))
bts.InitBiTree()
console.log("After clearing binary tree, if tree is empty?%d(1:true 0:false) depth of tree=%d\n", bts.BiTreeEmpty(), bts.BiTreeDepth())
i = bts.Root()
if (i)
    console.log("Root of binary tree is:%d\n", e)
else
    console.log("Tree is empty, no root\n")