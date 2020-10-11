// define node
function BiTNode(props){
    this.data = props.data
    this.lchild = null
    this.rchild = null
}
var MAXSIZE = 100

function BinaryTreeLink(props){}

var btl = new BinaryTreeLink({})

BinaryTreeLink.prototype.visit=function(element){
    process.stdout.write(element + ' ')
}

var strArr = new Array(24)

BinaryTreeLink.prototype.StrAssign = function(T,chars)
{
    if (chars.length>MAXSIZE)
        return false
    else
    {
        T[0] = chars.length
        for (i = 1; i <= T[0]; i++)
            T[i] = chars[i-1]
        return true
    }
}

// Construct empty binary tree
BinaryTreeLink.prototype.InitBiTree = function(T)
{
    // Direct to make Object null, is no use
    T = null
    return true
}

/*
	Condition: binary tree is exist
	Result: destroy binary tree
*/
BinaryTreeLink.prototype.DestroyBiTree = function(T)
{
    if (T)
    {
        // If tree has left child
        if (T.lchild)
            // Destroy subtree of left child
            btl.DestroyBiTree(T.lchild)
        // If tree has right child
        if (T.rchild)
            // Destroy subtree of right child
            btl.DestroyBiTree(T.rchild)
        // Relese root node
        T.data = null
        T.lchild = null
        T.rchild = null
    }
}


index = 1
// "#" means empty tree
BinaryTreeLink.prototype.CreateBiTree = function(T)
{
    var ch
    ch = strArr[index++]

    if (ch == '#')
        T = null
    else
    {
        if (!T)
            return false
        // Generate root node
        T.data = ch
        T.lchild = new BiTNode({})
        T.rchild = new BiTNode({})
        // Construct left subtree
        btl.CreateBiTree(T.lchild)
        // Construct right subtree
        btl.CreateBiTree(T.rchild)
    }
}

/*
	Condition: binary tree is exist
	Result: If tree is empty, return true, otherwise return false
*/
BinaryTreeLink.prototype.BiTreeEmpty = function(T)
{
    if (T.data != undefined)
        return false
    else
        return true
}

/*
	Condition: binary tree is exist
	Result: return the length of tree
*/
BinaryTreeLink.prototype.BiTreeDepth = function(T)
{
    var i, j
    if (!T)
        return 0
    if (T.lchild)
        i = btl.BiTreeDepth(T.lchild)
    else
        i = 0;
    if (T.rchild)
        j = btl.BiTreeDepth(T.rchild)
    else
        j = 0
    return i>j ? i+1 : j+1
}

/*
	Condition: binary tree is exist
	Result: return root of the tree
*/
BinaryTreeLink.prototype.Root = function(T)
{
    if (btl.BiTreeEmpty(T))
        return 0
    else
        return T.data
}

/*
	Condition: binary tree is exist, p points to a node of the tree
	result: return data, which is pointed by p
*/
BinaryTreeLink.prototype.Value = function(p)
{
    return p.data
}

// Assign value to node, which is pointed by p
BinaryTreeLink.prototype.Assign = function(p, value)
{
    p.data = value
}

/*
	Condition: binary tree is exist
	Result: preorder traverse
*/
BinaryTreeLink.prototype.PreOrderTraverse = function(T)
{
    if (T == null)
        return false
    console.log("%s", T.data)
    btl.PreOrderTraverse(T.lchild)
    btl.PreOrderTraverse(T.rchild)
}

/*
	Condition: binary tree is exist
	Result: inorder traverse
*/
BinaryTreeLink.prototype.InOrderTraverse = function(T)
{
    if (T == null)
        return false
    btl.InOrderTraverse(T.lchild)
    console.log("%s", T.data)
    btl.InOrderTraverse(T.rchild)
}

/*
	Condition: binary tree is exist
	Result: postorder traverse
*/
BinaryTreeLink.prototype.PostOrderTraverse = function(T)
{
    if (T == null)
        return false
    btl.PostOrderTraverse(T.lchild)
    btl.PostOrderTraverse(T.rchild)
    console.log("%s", T.data)
}
/*
		 A
	   /   \
	  B      C
	 /  \   /  \
   D    E  F    G
  /       /      \
 H       I        J
  \
   K
*/



var BinarTreeLink = new BiTNode({})
var i;
var T;
var e1;
btl.InitBiTree(BinarTreeLink)


btl.StrAssign(strArr,"ABDH#K###E##CFI###G#J##")

btl.CreateBiTree(BinarTreeLink)

console.log("After constructing empty binary tree, if the tree is empty? %d(1:true 0:false) depth of the tree is=%d\n", btl.BiTreeEmpty(BinarTreeLink), btl.BiTreeDepth(BinarTreeLink))
e1 = btl.Root(BinarTreeLink)
console.log("Root of binary tree is: %c\n", e1)

console.log("\n Preorder traverse:")
btl.PreOrderTraverse(BinarTreeLink)
console.log("\n Inorder traverse:")
btl.InOrderTraverse(BinarTreeLink)
console.log("\n Postorder traverse:")
btl.PostOrderTraverse(BinarTreeLink)
btl.DestroyBiTree(BinarTreeLink)
console.log("\n After clearing binary tree, if the tree is empty? %d(1:true 0:false) depth of the tree is=%d\n", btl.BiTreeEmpty(BinarTreeLink), btl.BiTreeDepth(BinarTreeLink))
i = btl.Root(BinarTreeLink)
if (!i)
    console.log("Tree is empty, no root\n")