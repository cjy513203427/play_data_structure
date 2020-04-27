// define node
function Node(props) {
    this.data = props.data
    this.next = null
}

// define link list
function LinkedList(props){
    this.LinkList = new Node({})
}

LinkedList.prototype.visit=function(element){
    process.stdout.write(element + ' ')
}

// Init link list
LinkedList.prototype.InitList=function()
{
    // generate head Node,L points to head Node
    L = new Node({})
    // when memory allocation fails
    if(!L)
        return false
    // pointer field = NULL
    L.next = null
    return true
}

// Condition:link list is exist
// Judge if link list is empty
LinkedList.prototype.ListEmpty=function(){
    // judge if the first Node has value
    if(this.LinkList.next)
        return false
    else
        return true
}

// Condition:link list is exist
// Let link list be a empty link list
LinkedList.prototype.ClearList=function(){
    var p,q
    // assign p first Node
    p = this.LinkList.next
    while(p)
    {
        // save next Node
        q = p.next
        p=q
    }
    // pointer domin of head Node is NULL
    this.LinkList.next = null
    return true

}

// Condition:link list is exist
// Return length of link list
LinkedList.prototype.ListLength=function(){
    var i = 0
    // assign p first Node
    var p = this.LinkList.next
    while(p)
    {
        i++
        p = p.next
    }
    return i
}

// Condition:link list is exist
// return value of index i
LinkedList.prototype.GetElem=function(i){
    var j
    var p
    // assign p first Node
    p = this.LinkList.next
    j=1
    // search Node according to index i with traverse
    while(p&&j<i){
        p = p.next
        ++j
    }
    // when the ith element is not exist
    if(!p||j>i)
        return false
    
    var e = p.data
    return e
}

// Condition:link list is exist,1≤i≤ListLength(L)
// return index of element
LinkedList.prototype.LocateElem = function(e){
    var i = 0
    var p = this.LinkList.next
    while(p){
        i++;
        if(p.data == e)
            return i
        p = p.next
    }
    return false
}

// Condition:link list is exist,1≤i≤ListLength(L)
// Insert element in index i,length plus 1
LinkedList.prototype.ListInsert = function(i,e){
    var j;
    var p,s
    p=this.LinkList
    j=1
    // search Node according to index i with traverse
    while(p&&j<i){
        p = p.next
        ++j
    }
    // when the ith element is not exist
    if(!p||j>i)
        return false
    // generate new Node
    s = new Node({});
    s.data = e
    s.next = p.next
    p.next = s
    return true
}

// Condition:link list is exist,1≤i≤ListLength(L)
// Delete element according to index i,return deleted value,length minus 1
LinkedList.prototype.ListDelete = function(i){
    var j
    var p,q
    p=this.LinkList
    j=1
    //search Node according to index i with traverse
    while (p.next && j<i){
        p = p.next
        ++j
    }
    // when the ith element is not exist
    if(!(p.next)||j>i)
        return false
    
    q = p.next
    p.next = q.next
    var e = q.data
    return e;
}

// Condition:link list is exist,1≤i≤ListLength(L)
// Traverse every element
LinkedList.prototype.ListTraverse = function(){
    var p = this.LinkList.next
    while(p){
        this.visit(p.data)
        p=p.next
    }
    console.log()
    return true
}

// Randomly generate values for n elements
// Build a single linked list with head Node,insert from head
LinkedList.prototype.CreateListHead = function(n){
    var p
    var i
    L = this.LinkList
    // build a single linked list with head Node
    L.next = null
    for(i=0;i<n;i++){
        // generate new Node
        p = new Node({})
        // generate number within 100
        p.data = i
        p.next = L.next
        L.next = p
    }
    
}

// Randomly generate values for n elements
// Build a single linked list with head Node,insert from tail
LinkedList.prototype.CreateListTail = function(n){
    var p,r
    var i
    // L is whole linked list
    L = this.LinkList
    // r points to tail
    r = L
    for(var i=0; i<n; i++){
        // generate new Node
        p = new Node({})
        // generate number within 100
        p.data = i
        r.next = p
        // then r is last element
        r = p
    }
    r.next = null
}

function createLinkedList(props) {
    return new LinkedList(props || {})
}

var ll = createLinkedList({
    
});
ll.InitList();
console.log("After L initialized ：ListLength() ="+ll.ListLength())

for (j = 1; j <= 5; j++)
    ll.ListInsert(1, j);
console.log("After we insert 1~5 in head of L in order：L.data=")
ll.ListTraverse();
console.log("ListLength()="+ll.ListLength())
i = ll.ListEmpty();
console.log("If L is empty：i="+i);
ll.ClearList();
console.log("After we clear L：ListLength()="+ll.ListLength())
i = ll.ListEmpty();
console.log("If L is empty：i="+i)
for (j = 1; j <= 10; j++)
    ll.ListInsert(j, j);

console.log("after we insert 1~10 in tail of L in order：L.data=")
ll.ListTraverse();
console.log("ListLength()="+ll.ListLength())
ll.ListInsert(1, 10);
console.log("After we insert 10 in head of L：L.data=")
ll.ListTraverse();
console.log("ListLength(L)="+ll.ListLength())
e = ll.GetElem(5);
console.log("The 5th element is："+e)

for (j = 3; j <= 4; j++) {
    k = ll.LocateElem(j);
    if (k)
        console.log("The "+k+"th element is "+j)
    else
        console.log("There is not element,whose value is "+j)
}
k = ll.ListLength();
for (j = k + 1; j >= k; j--)
{
    i = ll.ListDelete(j);
    if (i == false)
        console.log("Deleting "+j+"th elment failed")
    else
        console.log("Deleted "+j+"th element is: "+i)
}
console.log("Traverse L in order：")
ll.ListTraverse();
j = 5;
e = ll.ListDelete(j);
console.log("Deleted "+j+"th element is:  " +e)
console.log("Traverse L in order：")
ll.ListTraverse();

i = ll.ClearList();
console.log("After we clear L：ListLength(L)="+ll.ListLength())
ll.CreateListHead(20);
console.log("Create the elements of L as a whole (CreateListHead)：")
ll.ListTraverse();
i = ll.ClearList();
console.log("After we clear L：ListLength(L)="+ll.ListLength())
ll.CreateListTail(20);
console.log("Create the elements of L as a whole (CreateListTail)：")
ll.ListTraverse();