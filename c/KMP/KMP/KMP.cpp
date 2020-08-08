#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
// Define capacity
#define MAXSIZE 100

typedef int Status;		
typedef int ElemType;

// Data Unit 0 stores the length of String
typedef char String_[MAXSIZE + 1];

// Generate a new String, whose value is equal to chars
Status StrAssign(String_ T,const char *chars)
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

Status ClearString_(String_ S)
{
	// Make the length 0
	S[0] = 0;
	return OK;
}

// Print String
void StrPrint(String_ T)
{
	int i;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}

// Print Next array
void NextPrint(int next[], int length)
{
	int i;
	for (i = 1; i <= length; i++)
		printf("%d", next[i]);
	printf("\n");
}

// Return number of elements
int StrLength(String_ S)
{
	return S[0];
}

// 例子：子串"abcfghijk"在主串"abcfghijkbcd"中第1个字符之后的位置(包括第一个字符)是1
// 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0
// Example: SubString_ is "abcfghijk", MainString_ is "abcfghijkbcd", result is 1
// Return position,where subString_ in mainString_ after pos_th String_, if not exist, return 0
// T is not null, 1≤pos≤StrLength(S)
int Index(String_ S, String_ T, int pos)
{
	// Index of mainString
	int i = pos;
	// Index of subString
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
			// I is back to the next position of matched first position
			i = i - j + 2;
			// J is back to the first position of subString T
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}


// Return "next" array of subString
void get_next(String_ T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	// T[0] is the length of String T
	while (i<T[0])
	{
		// T[i] means single character of suffix, T[j] means single character of prefix. 
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			// If String is not the same, j traces back.
			j = next[j];
	}
}


// 例子：子串"abcfghijk"在主串"abcfghijkbcd"中第1个字符之后的位置(包括第一个字符)是1
// 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0
// Example: SubString is "abcfghijk", MainString is "abcfghijkbcd", result is 1
// Return position,where subString in mainString after pos_th String, if not exist, return 0
// T is not null, 1≤pos≤StrLength(S)
int Index_KMP(String_ S, String_ T, int pos)
{
	// Index of mainString
	int i = pos;	
	// Index of subString
	int j = 1;		
	// Define a next array
	int next[255];	
	// Analyse String T, get next array
	get_next(T, next);
	while (i <= S[0] && j <= T[0])
	{
		// If j is equal to zero and both characters are equal
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		// Restart matching progress
		else 
			// J returns back to the appropriate position, i keep unchanged
			j = next[j];
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

// Get the "corrected next" array of string T
void get_nextval(String_ T, int *nextval)
{
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	// T[0] is the length of string
	while (i<T[0]) 
	{
		// T[i] means single character of suffix, T[j] means single character of prefix. 
		if (j == 0 || T[i] == T[j]) 
		{
			++i;
			++j;
			// If current string is not equal to prefix string
			if (T[i] != T[j])
				// Set j to nextval[i]
				nextval[i] = j;
			// If current string is equal to prefix string
			else
				// Set nextval of prefix string to nextval[i] 
				nextval[i] = nextval[j];
		}
		else
			// If String is not the same, j traces back.
			j = nextval[j];	
	}
}

int Index_KMP1(String_ S, String_ T, int pos)
{
	// Index of mainString
	int i = pos;	
	// Index of subString
	int j = 1;
	// Define "next" array
	int next[255];
	// Analyse String T, get next array
	get_nextval(T, next);
	while (i <= S[0] && j <= T[0])
	{
		// If j is equal to zero and both characters are equal
		if (j == 0 || S[i] == T[j]) 
		{
			++i;
			++j;
		}
		// Restart matching progress
		else 
			// J returns back to the appropriate position, i keep unchanged
			j = next[j];
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

int main()
{
	int i, *p;
	String_ s1, s2;

	StrAssign(s1, "abcdex");
	printf("Substring is: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next is: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "abcabx");
	printf("Substring is: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next is: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "ababaaaba");
	printf("Substring is: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next is: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "aaaaaaaab");
	printf("Substring is: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next is: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "ababaaaba");
	printf("Next is: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next is: ");
	NextPrint(p, StrLength(s1));
	get_nextval(s1, p);
	printf("NextVal is: ");
	NextPrint(p, StrLength(s1));
	printf("\n");

	StrAssign(s1, "aaaaaaaab");
	printf("Substring is: ");
	StrPrint(s1);
	i = StrLength(s1);
	p = (int*)malloc((i + 1) * sizeof(int));
	get_next(s1, p);
	printf("Next is: ");
	NextPrint(p, StrLength(s1));
	get_nextval(s1, p);
	printf("NextVal is: ");
	NextPrint(p, StrLength(s1));

	printf("\n");

	StrAssign(s1, "00000000000000000000000000000000000000000000000001");
	printf("Mainstring is: ");
	StrPrint(s1);
	StrAssign(s2, "0000000001");
	printf("Substring is: ");
	StrPrint(s2);
	printf("\n");
	printf("Mainstring and Substring match for the first time at the %d th charcter (Naive pattern matching algorithm) \n", Index(s1, s2, 1));
	printf("Mainstring and Substring match for the first time at the %d th charcter (KMP algorithm) \n", Index_KMP(s1, s2, 1));
	printf("Mainstring and Substring match for the first time at the %d th charcter (KMP corrected algorithm) \n", Index_KMP1(s1, s2, 1));

	system("pause");
	return 0;
}
