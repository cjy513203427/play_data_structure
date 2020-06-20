#ifndef STRING__H
#define STRING__H
#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40

using namespace std;
// Status code
typedef int Status;
// Data type
typedef int ElemType;
// Index 0 of Array stores length of String_
typedef char String [MAXSIZE + 1];

class String_ {
public:
	// Assign char to String_
	Status StrAssign(String T, const char *chars);
	// Copy string S,then get string T
	Status StrCopy(String T, String S);
	// If string S is empty,return TRUE,otherwise return FALSE
	Status StrEmpty(String S);
	// Condition:String S and String T are exist
	// Result:If S>T,returned value>0;If S=T,returned value = 0;If S<t,returned value < 0
	int StrCompare(String S, String T);
	// Return number of elements
	int StrLength(String S);
	// Condition:string S is exist
	// Reuslt:clear string
	Status ClearString_(String S);
	// Return new string with T,that is concated S1 and S2.If string is not concated,return TRUE,otherwise return FALSE
	Status Concat(String T, String S1, String S2);
	// Return substring with Sub,that starts from pos,whose length is len
	Status SubString_(String Sub, String S, int pos, int len);
	// Example: Substring is "abcfghijk", Mainstring is "abcfghijkbcd", result is 1
	// Return position,where substring in mainstring after pos_th string, if not exist, return 0
	// T is not null, 1¡Üpos¡ÜStrLength(S)
	int Index(String S, String T, int pos);
	// T is not empty string. If character of mainstring S, that is after the pos character of mainstring, equal to T.
	// return the postion of the first matched string, otherwise return 0
	int Index2(String S, String T, int pos);
	// Condition: If string S and string T is exist, 1¡Üpos¡ÜStrLength(S)+1
	// Result: Insert string T before the pos th character of string S. Complete insert returns true, partially insert returns false.
	Status StrInsert(String S, int pos, String T);
	// Condition: string S is exist, 1¡Üpos¡ÜStrLength(S)-len+1
	// Result: Delete string S' substring, that starts from the pos th character and whose length is len.
	Status StrDelete(String S, int pos, int len);
	// Condition: If string S,T und V is exist, T is not empty string
	// Result: Replace mainstring S' substring, that is the same substring as T, with V.
	Status Replace(String S, String T, String V);
	// Print string
	void StrPrint(String T);

};

#endif