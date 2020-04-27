var MAXSIZE = 1000
var StaticLinkList = new Array(MAXSIZE)


// define node
function Node(props) {
    this.data = props.data
    // Cursor,if the value is equal to zero,it means pointless.
    this.cur = props.cur
}

// define static link list
function StaticLinkedList(props){}

StaticLinkedList.prototype.visit=function(element){
    process.stdout.write(element + ' ')
}

// Initialize array to alternate link list,space[0].cur is head pointer,"0" means null pointer
StaticLinkedList.prototype.InitList=function(){
    var i = 0;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        StaticLinkList[i] = new Node({data:null,cur:i+1})
    }
	// for now link list is null,the cursor of last element is 0
	StaticLinkList[MAXSIZE - 1] = new Node({data:null,cur:0});
	return true;
}


// If static link list is null,then return index of distributed element
StaticLinkedList.prototype.Malloc_SSL=function(){
    // Get index of free element
    var i = StaticLinkList[0].cur
    if(i)
        // Use next element as alternate element
        StaticLinkList[0].cur = StaticLinkList[i].cur;
	return i;
}

StaticLinkedList.prototype.Free_SSL=function(k){
    // Link deleted element to a alternate link list
    // Let free element become the second element of alternate link list
    StaticLinkList[k].cur = StaticLinkList[0].cur;
    // Let the deleted element become the first element of alternate link list
    StaticLinkList[0].cur = k;
}

// Condition: static link list is exist
// Return number of element	
StaticLinkedList.prototype.ListLength=function(){
    var j = 0;
    // Get index of the first element with value
    var i = StaticLinkList[MAXSIZE-1].cur;
    while(i)
    {
        i = StaticLinkList[i].cur;
        j++;
    }
    return j;
}

// Insert new element in index i
StaticLinkedList.prototype.ListInsert=function(i,  e) {
	var j, k, l;
	// k is the index of the last element
	k = MAXSIZE - 1;
	if (i<0 || i>sll.ListLength())
		return ERROR;
	// Get index of free element
	j = sll.Malloc_SSL();
	if (j)
	{
		StaticLinkList[j].data = e;
		// Find the element,who is in front of the ith element
		for (l = 0; l < i; l++) 
			k = StaticLinkList[k].cur;
		// s->next = p->next
		StaticLinkList[j].cur = StaticLinkList[k].cur;
		// p->next = s
		StaticLinkList[k].cur = j;
		return true;
	}
	return false;
}

// Delete the ith element
StaticLinkedList.prototype.ListDelete=function(i) {
	var j, k;
	if (i<0 || i>sll.ListLength() - 1)
		return ERROR;
	k = MAXSIZE - 1;
	// Find the element,who is in front of the ith element
	for(j=0;j<i;j++)
		k = StaticLinkList[k].cur;
	// q = p->next
	j = StaticLinkList[k].cur;
	// p->next = q->next
	StaticLinkList[k].cur = StaticLinkList[j].cur;
	sll.Free_SSL(j);
	return true;
}

StaticLinkedList.prototype.ListTraverse=function(){
	var j = 0;
	var i = StaticLinkList[MAXSIZE - 1].cur;
	while (i)
	{
		sll.visit(StaticLinkList[i].data);
		i = StaticLinkList[i].cur;
		j++;
	}
	return true;
}

var sll = new StaticLinkedList();
sll.InitList();
console.log("After we initialize L：L.length= %d" ,sll.ListLength())
i = sll.ListInsert(0, 'F');
i = sll.ListInsert(0, 'E');
i = sll.ListInsert(0, 'D');
i = sll.ListInsert(0, 'B');
i = sll.ListInsert(0, 'A');

console.log("After we insert FEDBA in the head of L：\nL.data= ")
sll.ListTraverse();

i = sll.ListInsert(2, 'C');
console.log("\nAfter we insert 'C' between 'B' and 'D' in L：\nL.data=")
sll.ListTraverse();

i = sll.ListDelete(0);
console.log("\nAfter we delete 'A' in L：\nL.data=")
sll.ListTraverse();

console.log()