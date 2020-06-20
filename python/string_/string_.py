# -*- encoding: utf-8 -*-
'''
@File    :   string_.py    
@Modify Time      @Author       @Desciption
------------      -------       -----------
2020/6/12 21:16   Jonas          把list当作string，string当作char，模拟串的操作
'''

MAXSIZE = 40


class String_(object):

    def StrAssign(self, chars):
        T = [None] * MAXSIZE
        if len(chars) > MAXSIZE:
            return False
        else:

            T[0] = len(chars)
            for i in range(1, T[0] + 1, 1):
                T[i] = chars[i - 1]
            return T

    # Copy string S,then get string T
    def StrCopy(self, S):
        T = [None] * MAXSIZE
        for i in range(0, S[0] + 1, 1):
            T[i] = S[i]
        return T

    # If string S is empty,return TRUE,otherwise return FALSE
    def StrEmpty(self, S):
        if S[0] == 0:
            return True
        else:
            return False

    # Condition:String S and String T are exist
    # Result:If S>T,returned value>0;If S=T,returned value = 0;If S<t,returned value < 0
    def StrCompare(self, S, T):
        i = 0
        while i <= S[0] and i <= T[0]:
            i += 1
            if S[i] != T[i]:

                if S[i] < T[i]:
                    return -1
                elif S[i] == T[i]:
                    return 0
                else:
                    return 1

        return S[0] - T[0]

    # Return number of elements
    def StrLength(self, S):
        return S[0]

    # Condition:string S is exist
    # Reuslt:clear string
    def ClearString_(self, S):
        S[0] = 0
        return True

    # Return new string with T,that is concated S1 and S2.If string is not concated,return true,otherwise return false
    def Concat(self, S1, S2):
        T = [None] * MAXSIZE
        if (S1[0] + S2[0] <= MAXSIZE):
            # No truncation
            for i in range(1, S1[0] + 1, 1):
                T[i] = S1[i]
            for i in range(1, S2[0] + 1, 1):
                T[S1[0] + i] = S2[i]

            T[0] = S1[0] + S2[0]
            return T

        else:
            # Truncate S2
            for i in range(1, S1[0] + 1, 1):
                T[i] = S1[i]
            for i in range(1, MAXSIZE - S1[0], 1):
                T[S1[0] + i] = S2[i]
            T[0] = MAXSIZE
            return T

    # Return substring with Sub,that starts from pos,whose length is len
    def SubString_(self, S, pos, len):
        Sub = [None] * MAXSIZE
        # len > S[0] - pos + 1
        if pos < 1 or pos > S[0] or len < 0 or len > S[0] - pos:
            return False
        for i in range(1, len + 1, 1):
            Sub[i] = S[pos + i - 1]
        Sub[0] = len
        return Sub

    # 例子：子串"abcfghijk"在主串"abcfghijkbcd"中第1个字符之后的位置(包括第一个字符)是1
    # 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0
    # Example: Substring is "abcfghijk", Mainstring is "abcfghijkbcd", result is 1
    # Return position,where substring in mainstring after pos_th string, if not exist, return 0
    # T is not null, 1≤pos≤StrLength(S)
    def Index(self, S, T, pos):
        # Index of mainstring
        i = pos
        # Index of substring
        j = 1

        while (i <= S[0] and j <= T[0]):
            # If both characters are equal
            if S[i] == T[j]:
                i += 1
                j += 1

            # Restart matching progress
            else:
                # I goes back to the next position of matched first position
                i = i - j + 2
                # J goes back to the first position of substring T
                j = 1

        if j > T[0]:
            return i - T[0]
        else:
            return 0

    # T is not empty string. If character of mainstring S, that is after the pos character of mainstring, equal to T.
    # return the postion of the first matched string, otherwise return 0
    def Index2(self, S, T, pos):
        if pos > 0:
            # Get length of mainstring S
            n = self.StrLength(S)
            # Get length of substring T
            m = self.StrLength(T)
            i = pos
            while i <= n - m + 1:
                # Get substring,who starts fromt ith position, its length is equal to T
                sub = self.SubString_(S, i, m)
                # If two string are not equal
                if self.StrCompare(sub, T) != 0:
                    i += 1
                # If two string are equal
                else:
                    return i

        # No matched substring, return 0
        return 0

    # Condition: If string S and string T is exist, 1≤pos≤StrLength(S)+1
    # Result: Insert string T before the pos th character of string S. Complete insert returns true, partially insert returns false.
    def StrInsert(self, S, pos, T):
        if pos < 1 or pos > S[0] + 1:
            return False

        if S[0] + T[0] <= MAXSIZE:
            # Complete insert
            # First insert back element(string S)
            for i in range(S[0], pos - 1, -1):
                S[i + T[0]] = S[i]
            # Second insert front element(string T)
            for i in range(pos, pos + T[0], 1):
                S[i] = T[i - pos + 1]

            S[0] = S[0] + T[0]
            return S
        else:
            # Partially insert
            for i in range(MAXSIZE, pos - 1, -1):
                S[i] = S[i - T[0]]
            for i in range(pos, pos + T[0], 1):
                S[i] = T[i - pos + 1]
            S[0] = MAXSIZE
            return S

    # Condition: string S is exist, 1≤pos≤StrLength(S)-len+1
    # Result: Delete string S' substring, that starts from the pos th character and whose length is len.
    def StrDelete(self, S, pos, len):
        if pos < 1 or pos > S[0] - len + 1 or len < 0:
            return False
        # It is similar with deleteNode from linear list
        for i in range(pos + len, S[0] + 1, 1):
            S[i - len] = S[i]
        S[0] -= len
        return True

    # Condition: If string S,T und V is exist, T is not empty string
    # Result: Replace mainstring S' substring, that is the same substring as T, with V.
    def Replace(self, S, T, V):
        # From the first character of string s
        i = 1
        # If T is empty
        if self.StrEmpty(T):
            return False

        while i:
            # Get the position of matched substring
            i = self.Index(S, T, i)
            # If string S includes string T
            if i:
                # Delete string T
                self.StrDelete(S, i, self.StrLength(T))
                # Insert string V in the position of primary string T
                self.StrInsert(S, i, V)
                # Search the string T after the postion of string V
                i += self.StrLength(V)

        return True

    # Print string
    def StrPrint(self, T):
        for i in range(1, T[0] + 1, 1):
            print(T[i], end=' ')
        print("\n")


if __name__ == '__main__':
    st = String_()

    print("Please input string s1:")
    s1 = st.StrAssign("abcd")
    if not s1:
        print("Length of string is more than MAXSIZE (=%d)\n" % MAXSIZE)

    print("Length of string is %d If string is empty? %d(1:true 0:false)\n" % (st.StrLength(s1), st.StrEmpty(s1)));
    s2 = st.StrCopy(s1)
    print("Copy string s1 and generate new string:")
    st.StrPrint(s2)
    print("Please input string s2:")

    s2 = st.StrAssign("efghijk")
    if not s2:
        print("Length of string is more than MAXSIZE(%d)\n" % MAXSIZE)

    i = st.StrCompare(s1, s2)
    if i < 0:
        s = '<'
    elif i == 0:
        s = '='
    else:
        s = '>'
    print("String s1 %s string s2 \n" % s)

    t = st.Concat(s1, s2)
    print("String s1 concats string s2, get string t:")
    st.StrPrint(t)
    st.ClearString_(s1)
    print("After clearing the empty string, string s1 is:")
    st.StrPrint(s1)
    print("Length of string is %d If string is empty？%d(1:true 0:false)\n" % (st.StrLength(s1), st.StrEmpty(s1)))
    print("Get substring of string t, please input initial position of substring, length of substring: ")

    i = 2
    j = 3
    print("%d,%d \n" % (i, j))

    s2 = st.SubString_(t, i, j)

    if s2:
        print("Substring s2 is: ")
        st.StrPrint(s2)

    print("From the pos th character of string t, delete number of length character, please input pos,len ");

    i = 4
    j = 2
    print("%d,%d \n" % (i, j))

    st.StrDelete(t, i, j)
    print("After deleting, string t is:")
    st.StrPrint(t)
    i = 1
    s2 = st.StrInsert(s2, i, t)
    print("After inserting string t in the position of %d th of string s2, string s2 is:\n" % i);
    st.StrPrint(s2)
    s2 = st.StrAssign("abcdefg")
    t = st.StrAssign("cd")
    i = st.Index(s2, t, 3)
    print("The position of substring t is after the 2th character of mainstring s2. The position is exactly %d\n" % i)
    s2 = st.StrAssign("abcdefghi")
    t = st.StrAssign("fgh")
    i = st.Index2(s2, t, 1)
    print("T is not empty string. If after the first character of mainstring, that is equal to string T, the position "
          "is %d\n" % i);
    t = st.SubString_(s2, 1, 1)
    print("String t is:")
    st.StrPrint(t)
    s1 = st.Concat(t, t)
    print("String s1 is:")
    st.StrPrint(s1)
    print("String s2 is:")
    st.StrPrint(s2)
    st.Replace(s2, t, s1)
    print("Replace string s2, that is the same wth string t ,with s1, string s2 is ");
    st.StrPrint(s2)
