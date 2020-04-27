var MAXSIZE = 20
function SqList(props) {
    this.data = new Array(MAXSIZE);
    this.length = props.length || 0;
}

SqList.prototype.visit = function (element) {
    //console.log(element + ' ');
    process.stdout.write(element + ' ');
    return true;
};
//init sequence list
SqList.prototype.InitList = function (sl) {
    sl.length = 0;
    return true;
}
//judge if list empty is
SqList.prototype.ListEmpty = function (sl) {
    if (sl.length == 0)
        return true;
    else
        return false;
}
//clear sequence list
SqList.prototype.ClearList = function (sl) {
    sl.length = 0;
    return true;
}
// return list length
SqList.prototype.ListLength = function (sl) {
    return sl.length;
}

/*Condition:0≤i≤ListLength
according to index return element
*/
SqList.prototype.GetElem = function (sl, i) {
    if (sl.length == 0 || i < 0 || i > sl.length - 1)
        return false;
    var et = sl.data[i];
    return et;
}

/*Condition:ListLength>0
according to element return element's index
*/
SqList.prototype.locateElem = function (sl, et) {
    var i;
    if (sl.length == 0)
        return false;
    for (i = 0; i < sl.length; i++) {
        if (sl.data[i] == et)
            break;
    }
    if (i >= sl.length)
        return false;
    return i;
}

/*Condition:!=MAXSIZE; 0≤i≤ListLength
insert element in position i
*/
SqList.prototype.ListInsert = function (sl, i, et) {
    var k;
    if (sl.length == MAXSIZE)
        return false;
    if (i < 0 || i > sl.length)
        return false;
    // not final position
    if (i < sl.length) {
        for (var k = sl.length - 1; k >= i; k--)
            sl.data[k + 1] = sl.data[k];
    }
    sl.data[i] = et;
    sl.length++;
    return true;
}

/*Condition:ListLength!=0; 0≤i≤ListLength
delete element according to index
return deleted element
*/
SqList.prototype.ListDelete = function (sl, i) {
    var k;
    if (sl.length == 0)
        return false;
    if (i < 0 || i > sl.length - 1)
        return false;
    et = sl.data[i];
    // not final position
    if (i < sl.length - 1) {
        for (k = i; k < sl.length - 1; k++)
            sl.data[k] = sl.data[k + 1];
    }
    sl.length--;
    return et;
}

SqList.prototype.ListTraverse = function(sl){
    var i;
    for(i=0;i<sl.length;i++)
        this.visit(sl.data[i]);
    console.log()
    return true;
}


function createSqList(props) {
    return new SqList(props || {})
}

var sl = createSqList({});


sl.InitList(sl);
console.log("after Initialization:sl.length="+sl.length)
for (j = 0; j <= 5; j++)
    i = sl.ListInsert(sl, 0, j);
console.log( "after we insert from 0 to 5:sl.data=")
sl.ListTraverse(sl);
console.log("sl.length="+sl.length);
i = sl.ListEmpty(sl);
console.log("if L is null:i="+i+"(1:True 0:False)");
i = sl.ClearList(sl);
console.log("after clear:sl.length="+sl.length);
i = sl.ListEmpty(sl);
console.log("if L is null:i="+i+"(1:True 0:False)");

for (j = 0; j <= 10; j++) {
    sl.ListInsert(sl, j, j);
}
console.log("after we insert from 0 to 10:sl.data=");
sl.ListTraverse(sl);
console.log("sl.length="+sl.length);

sl.ListInsert(sl, 0, 0);
console.log("after we insert 0 in head:sl.data=");
sl.ListTraverse(sl);
console.log("sl.length="+sl.length);
et = sl.GetElem(sl, 4);
console.log("the 4th element is "+et);

for (j = 3; j <= 4; j++) {
    k = sl.locateElem(sl, j);
    if (k)
        console.log("the "+k+"th element is "+j);
    else
        console.log("without "+j+"th element ");
}

k = sl.ListLength(sl);
i = sl.ListDelete(sl, 5);
console.log("delete "+5+"th element is "+et);
console.log("output element ")
sl.ListTraverse(sl);