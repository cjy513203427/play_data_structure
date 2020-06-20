var MAXSIZE = 40

function String_(){}

var st =  new String_()

String_.prototype.StrAssign = function(chars){
    T = new Array(MAXSIZE)
    var i
	if (chars.length>MAXSIZE)
		return false
	else
	{
		T[0] = chars.length;
		for (i = 1; i <= T[0]; i++)
            T[i] = chars[i-1]
		return T
	}
}

// Copy string S,then get string T
String_.prototype.StrCopy = function(S)
{
	var i
	var T = new Array(MAXSIZE)
	for (i = 0; i <= S[0]; i++)
		T[i] = S[i]
	return T
}

// If string S is empty,return TRUE,otherwise return FALSE
String_.prototype.StrEmpty = function(S)
{
	if (S[0] == 0)
		return true
	else
		return false
}

// Condition:String S and String T are exist
// Result:If S>T,returned value>0;If S=T,returned value = 0;If S<t,returned value < 0
String_.prototype.StrCompare = function(S,T)
{
	var i
	for (i = 1; i <= S[0] && i <= T[0]; ++i)
		if (S[i] != T[i])
		
			if (S[i] < T[i])
			{
				r = S[i] < T[i]
				return -1
			}
			else if (S[i] == T[i])
			{
				r = S[i] == T[i]
				return 0
			}else
			{
				return 1
			}
			
	return S[0] - T[0]
}

// Return number of elements
String_.prototype.StrLength = function(S)
{
	return parseInt(S[0])
}

// Condition:string S is exist
// Reuslt:clear string
String_.prototype.ClearString_ = function(S)
{
	S[0] = 0;
	return true;
}

// Return new string with T,that is concated S1 and S2.If string is not concated,return true,otherwise return false
String_.prototype.Concat = function(S1,S2)
{
	var i
	var T = new Array(MAXSIZE)
	if(S1[0] + S2[0] <= MAXSIZE)
	{
		// No truncation
		for(i=1; i<= S1[0]; i++)
			T[i] = S1[i]
		for(i=1; i<=S2[0]; i++)
			T[S1[0]+i] = S2[i]
		T[0] = S1[0] + S2[0]
		return T
	}
	else
	{
		// Truncate S2
		for(i=1; i<= S1[0]; i++)
			T[i] = S1[i]
		for(i=1; i<=MAXSIZE-S1[0]; i++)
			T[S1[0] + i] = S2[i]
		T[0] = MAXSIZE
		return T
	}
}

// Return substring with Sub,that starts from pos,whose length is len
String_.prototype.SubString_ = function(S, pos, len)
{
	var i
	var Sub = new Array(MAXSIZE)
	// len>S[0]-pos+1
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos)
		return false
	for(i=1; i<=len; i++)
		Sub[i] = S[pos+i-1]
	Sub[0] = len
	return Sub
}

// 例子：子串"abcfghijk"在主串"abcfghijkbcd"中第1个字符之后的位置(包括第一个字符)是1
// 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0
// Example: Substring is "abcfghijk", Mainstring is "abcfghijkbcd", result is 1
// Return position,where substring in mainstring after pos_th string, if not exist, return 0
// T is not null, 1≤pos≤StrLength(S)
String_.prototype.Index = function(S, T, pos)
{
	// Index of mainstring
	var i = pos
	// Index of substring
	var j = 1
	while(i<=S[0] && j<=T[0])
	{
		// If both characters are equal
		if(S[i] == T[j])
		{
			++i
			++j
		}
		else
		// Restart matching progress
		{
			// I goes back to the next position of matched first position
			i = i - j + 2
			// J goes back to the first position of substring T
			j = 1
		}
	}
	if(j>T[0])
		return i-T[0]
	else
		return 0
}

// T is not empty string. If character of mainstring S, that is after the pos character of mainstring, equal to T.
// return the postion of the first matched string, otherwise return 0
String_.prototype.Index2 = function(S, T, pos)
{
	var n,m,i,sub
	if(pos>0)
	{
		// Get length of mainstring S
		n = st.StrLength(S)
		// Get length of substring T
		m = st.StrLength(T)
		i = pos
		while(i<=n-m+1)
		{
			// Get substring,who starts fromt ith position, its length is equal to T
			sub = st.SubString_(S,i,m)
			// If two string are not equal
			if (st.StrCompare(sub, T) != 0)
				++i
			// If two string are equal
			else
				// Return i
				return i
		}
	}
	// No matched substring, return 0
	return 0
}

// Condition: If string S and string T is exist, 1≤pos≤StrLength(S)+1
// Result: Insert string T before the pos th character of string S. Complete insert returns true, partially insert returns false.
String_.prototype.StrInsert = function(S, pos, T)
{
	var i
	if (pos<1 || pos>S[0] + 1)
		return false
	if(S[0] + T[0] <= MAXSIZE)
	{
		// Complete insert
		// First insert back element(string S)
		for(i = S[0]; i>= pos; i--)
			S[i+T[0]] = S[i]
		// Second insert front element(string T)
		for(i = pos; i<pos+T[0]; i++)
			S[i] = T[i-pos+1]
		S[0] = S[0] + T[0]
		return S		
	}
	else
	{
		// Partially insert
		for (i = MAXSIZE; i >= pos; i--)
			S[i] = S[i - T[0]]
		for (i = pos; i<pos + T[0]; i++)
			S[i] = T[i - pos + 1]
		S[0] = MAXSIZE
		return S
	}
}

// Condition: string S is exist, 1≤pos≤StrLength(S)-len+1
// Result: Delete string S' substring, that starts from the pos th character and whose length is len.
String_.prototype.StrDelete = function(S, pos, len)
{
	var i
	if (pos<1 || pos>S[0] - len + 1 || len<0)
		return false
	// It is similar with deleteNode from linear list
	for (i = pos + len; i <= S[0]; i++)
		S[i - len] = S[i]
	S[0] -= len
	return true
}

// Condition: If string S,T und V is exist, T is not empty string
// Result: Replace mainstring S' substring, that is the same substring as T, with V.
String_.prototype.Replace = function(S, T, V)
{
	// From the first character of string s
	var i = 1
	// If T is empty
	if (st.StrEmpty(T))
		return false
	do
	{
		// Get the position of matched substring
		i = st.Index(S, T, i)
		// If string S includes string T
		if (i)
		{
			// Delete string T
			st.StrDelete(S, i, st.StrLength(T))
			// Insert string V in the position of primary string T
			st.StrInsert(S, i, V)
			// Search the string T after the postion of string V
			i += st.StrLength(V)
		}
	} while (i)
	return true
}

// Print string
String_.prototype.StrPrint = function(T)
{
	var i
	for (i = 1; i <= T[0]; i++)
		process.stdout.write(T[i]+' ');
	console.log()
}

var i,j,k,s,t,s1,s2,st
console.log("Please input string s1:");
s1 = st.StrAssign("abcd");
if (!s1)
{
	console.log("Length of string is more than MAXSIZE (=%d)\n", MAXSIZE)
}
console.log("Length of string is %d If string is empty? %d(1:true 0:false)\n", st.StrLength(s1), st.StrEmpty(s1));
s2 = st.StrCopy(s1)
console.log("Copy string s1 and generate new string:")
st.StrPrint(s2)
console.log("Please input string s2:")

s2 = st.StrAssign("efghijk")
if (!s2)
{
	console.log("Length of string is more than MAXSIZE(%d)\n", MAXSIZE)
}
i = st.StrCompare(s1, s2)
if (i<0)
	s = '<'
else if (i == 0)
	s = '='
else
	s = '>'
console.log("String s1 %s string s2 \n", s);
t = st.Concat(s1, s2);
console.log("String s1 concats string s2, get string t:");
st.StrPrint(t);
// no use
if (k == false)
	console.log("String t has truncation \n");
st.ClearString_(s1);
console.log("After clearing the empty string, string s1 is:");
st.StrPrint(s1);
console.log("Length of string is %d If string is empty？%d(1:true 0:false)\n", st.StrLength(s1), st.StrEmpty(s1));
console.log("Get substring of string t, please input initial position of substring, length of substring: ");

i = 2;
j = 3;
console.log("%d,%d \n", i, j);

s2 = st.SubString_(t, i, j);
if (s2)
{
	console.log("Substring s2 is: ");
	st.StrPrint(s2);
}
console.log("From the pos th character of string t, delete number of length character, please input pos,len ");

i = 4;
j = 2;
console.log("%d,%d \n", i, j);


st.StrDelete(t, i, j);
console.log("After deleting, string t is:");
st.StrPrint(t);
i = 1;
s2 = st.StrInsert(s2, i, t);
console.log("After inserting string t in the position of %d th of string s2, string s2 is:\n", i);
st.StrPrint(s2);
s2 = st.StrAssign("googlegood");
t = st.StrAssign("google");
i = st.Index(s2, t, 1);
console.log("The position of substring t is after the 2th character of mainstring s2. The position is exactly %d\n", i);
s2 = st.StrAssign("abcdefghi");
t = st.StrAssign("fgh");
i = st.Index2(s2, t, 1);
console.log("T is not empty string. If after the first character of mainstring, that is equal to string T, the position is %d\n", i);
t = st.SubString_(s2, 1, 1);
console.log("String t is:");
st.StrPrint(t);
s1 = st.Concat(t, t);
console.log("String s1 is:");
st.StrPrint(s1);
console.log("String s2 is:");
st.StrPrint(s2);
st.Replace(s2, t, s1);
console.log("Replace string s2, that is the same wth string t ,with s1, string s2 is ");
st.StrPrint(s2);