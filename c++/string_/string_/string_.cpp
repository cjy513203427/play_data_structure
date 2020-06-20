#include "string_.h"

Status String_::StrAssign(String T, const char *chars)
{
	int i;
	if (strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}

// Copy string S,then get string T
Status String_::StrCopy(String T, String S)
{
	int i;
	for (i = 0; i <= S[0]; i++)
		T[i] = S[i];
	return OK;
}

// If string S is empty,return TRUE,otherwise return FALSE
Status String_::StrEmpty(String S)
{
	if (S[0] == 0)
		return TRUE;
	else
		return FALSE;
}
// Condition:String S and String T are exist
// Result:If S>T,returned value>0;If S=T,returned value = 0;If S<t,returned value < 0
int String_::StrCompare(String S, String T)
{
	int i;
	for (i = 1; i <= S[0] && i <= T[0]; ++i)
		if (S[i] != T[i])
			return S[i] - T[i];
	return S[0] - T[0];
}

// Return number of elements
int String_::StrLength(String S)
{
	return S[0];
}

// Condition:string S is exist
// Reuslt:clear string
Status String_::ClearString_(String S)
{
	S[0] = 0;
	return OK;
}

// Return new string with T,that is concated S1 and S2.If string is not concated,return TRUE,otherwise return FALSE
Status String_::Concat(String T, String S1, String S2)
{
	int i;
	if (S1[0] + S2[0] <= MAXSIZE)
	{
		// No truncation
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= S2[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	}
	else
	{
		// Truncate S2
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= MAXSIZE - S1[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = MAXSIZE;
		return FALSE;
	}
}

// Return substring with Sub,that starts from pos,whose length is len
Status String_::SubString_(String Sub, String S, int pos, int len)
{
	int i;
	// len>S[0]-pos+1
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos)
		return ERROR;
	for (i = 1; i <= len; i++)
		Sub[i] = S[pos + i - 1];
	Sub[0] = len;
	return OK;
}

// 例子：子串"abcfghijk"在主串"abcfghijkbcd"中第1个字符之后的位置(包括第一个字符)是1
// 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0
// Example: Substring is "abcfghijk", Mainstring is "abcfghijkbcd", result is 1
// Return position,where substring in mainstring after pos_th string, if not exist, return 0
// T is not null, 1≤pos≤StrLength(S)
int String_::Index(String S, String T, int pos)
{
	// Index of mainstring
	int i = pos;
	// Index of substring
	int j = 1;
	while (i <= S[0] && j <= T[0])
	{
		// If both characters are equal
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		// Restart matching progress
		{
			// I goes back to the next position of matched first position
			i = i - j + 2;
			// J goes back to the first position of substring T
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

// T is not empty string. If character of mainstring S, that is after the pos character of mainstring, equal to T.
// return the postion of the first matched string, otherwise return 0
int String_::Index2(String S, String T, int pos)
{
	int n, m, i;
	String sub;
	if (pos > 0)
	{
		// Get length of mainstring S
		n = StrLength(S);
		// Get length of substring T
		m = StrLength(T);
		i = pos;
		while (i <= n - m + 1)
		{
			// Get substring,who starts fromt ith position, its length is equal to T
			SubString_(sub, S, i, m);
			// If two string are not equal
			if (StrCompare(sub, T) != 0)
				++i;
			// If two string are equal
			else
				// Return i
				return i;
		}
	}
	// No matched substring, return 0
	return 0;
}

// Condition: If string S and string T is exist, 1≤pos≤StrLength(S)+1
// Result: Insert string T before the pos th character of string S. Complete insert returns true, partially insert returns false.
Status String_::StrInsert(String S, int pos, String T)
{
	int i;
	if (pos<1 || pos>S[0] + 1)
		return ERROR;
	if (S[0] + T[0] <= MAXSIZE)
	{
		// Complete insert
		// First insert back element(string S)
		for (i = S[0]; i >= pos; i--)
			S[i + T[0]] = S[i];
		// Second insert front element(string T)
		for (i = pos; i<pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = S[0] + T[0];
		return TRUE;
	}
	else
	{
		// Partially insert
		for (i = MAXSIZE; i >= pos; i--)
			S[i] = S[i - T[0]];
		for (i = pos; i<pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = MAXSIZE;
		return FALSE;
	}
}

// Condition: string S is exist, 1≤pos≤StrLength(S)-len+1
// Result: Delete string S' substring, that starts from the pos th character and whose length is len.
Status String_::StrDelete(String S, int pos, int len)
{
	int i;
	if (pos<1 || pos>S[0] - len + 1 || len<0)
		return ERROR;
	// It is similar with deleteNode from linear list
	for (i = pos + len; i <= S[0]; i++)
		S[i - len] = S[i];
	S[0] -= len;
	return OK;
}

// Condition: If string S,T und V is exist, T is not empty string
// Result: Replace mainstring S' substring, that is the same substring as T, with V.
Status String_::Replace(String S, String T, String V)
{
	// From the first character of string s
	int i = 1;
	// If T is empty
	if (StrEmpty(T))
		return ERROR;
	do
	{
		// Get the position of matched substring
		i = Index(S, T, i);
		// If string S includes string T
		if (i)
		{
			// Delete string T
			StrDelete(S, i, StrLength(T));
			// Insert string V in the position of primary string T
			StrInsert(S, i, V);

			// Search the string T after the postion of string V
			i += StrLength(V);
		}
	} while (i);
	return OK;
}

// Print string
void String_::StrPrint(String T)
{
	int i;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}


int main()
{

	int i, j;
	Status k;
	char s;
	String t, s1, s2;
	String_ st;
	printf("Please input string s1:");
	k = st.StrAssign(s1, "abcd");
	if (!k)
	{
		printf("Length of string is more than MAXSIZE (=%d)\n", MAXSIZE);
		exit(0);
	}
	printf("Length of string is %d If string is empty? %d(1:true 0:false)\n", st.StrLength(s1), st.StrEmpty(s1));
	st.StrCopy(s2, s1);
	printf("Copy string s1 and generate new string:");
	st.StrPrint(s2);
	printf("Please input string s2:");

	k = st.StrAssign(s2, "efghijk");
	if (!k)
	{
		printf("Length of string is more than MAXSIZE(%d)\n", MAXSIZE);
		exit(0);
	}
	i = st.StrCompare(s1, s2);
	if (i<0)
		s = '<';
	else if (i == 0)
		s = '=';
	else
		s = '>';
	printf("String s1 %c string s2 \n", s);
	k = st.Concat(t, s1, s2);
	printf("String s1 concats string s2, get string t:");
	st.StrPrint(t);
	if (k == FALSE)
		printf("String t has truncation \n");
	st.ClearString_(s1);
	printf("After clearing the empty string, string s1 is:");
	st.StrPrint(s1);
	printf("Length of string is %d If string is empty？%d(1:true 0:false)\n", st.StrLength(s1), st.StrEmpty(s1));
	printf("Get substring of string t, please input initial position of substring, length of substring: ");

	i = 2;
	j = 3;
	printf("%d,%d \n", i, j);

	k = st.SubString_(s2, t, i, j);
	if (k)
	{
		printf("Substring s2 is: ");
		st.StrPrint(s2);
	}
	printf("From the pos th character of string t, delete number of length character, please input pos,len ");

	i = 4;
	j = 2;
	printf("%d,%d \n", i, j);


	st.StrDelete(t, i, j);
	printf("After deleting, string t is:");
	st.StrPrint(t);
	i = st.StrLength(s2) / 2;
	st.StrInsert(s2, i, t);
	printf("After inserting string t in the position of %d th of string s2, string s2 is:\n", i);
	st.StrPrint(s2);
	k = st.StrAssign(s2, "abcdefg");
	k = st.StrAssign(t, "cd");
	i = st.Index(s2, t, 3);
	printf("The position of substring t is after the 2th character of mainstring s2. The position is exactly %d\n", i);
	k = st.StrAssign(s2, "abcdefghi");
	k = st.StrAssign(t, "fgh");
	i = st.Index2(s2, t, 1);
	printf("T is not empty string. If after the first character of mainstring, that is equal to string T, the position is %d\n", i);
	st.SubString_(t, s2, 1, 1);
	printf("String t is:");
	st.StrPrint(t);
	st.Concat(s1, t, t);
	printf("String s1 is:");
	st.StrPrint(s1);
	printf("String s2 is:");
	st.StrPrint(s2);
	st.Replace(s2, t, s1);
	printf("Replace string s2, that is the same wth string t ,with s1, string s2 is ");
	st.StrPrint(s2);

	system("pause");
	return 0;
}