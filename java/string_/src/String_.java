import java.sql.Time;

/**
 * @Author: 谷天乐
 * @Date: 2020/6/17 15:17
 * @Description:
 */
public class String_ {

    public static final int MAXSIZE = 40;

    // Assign char to String_
    public char[] StrAssign(char[] chars) {
        char[] T = new char[MAXSIZE];
        int i;
        if (chars.length > MAXSIZE)
            return T;
        else {
            T[0] = (char) chars.length;
            for (i = 1; i <= T[0]; i++)
                T[i] = chars[i - 1];
            return T;
        }
    }

    // Copy string S,then get string T
    public char[] StrCopy(char[] S)
    {
        char[] T = new char[MAXSIZE];
        int i;
        for (i = 0; i <= S[0]; i++)
            T[i] = S[i];
        return T;
    }

    // If string S is empty,return TRUE,otherwise return FALSE
    public boolean StrEmpty(char[] S)
    {
        if (S[0] == 0)
            return true;
        else
            return false;
    }

    // Condition:String S and String T are exist
    // Result:If S>T,returned value>0;If S=T,returned value = 0;If S<t,returned value < 0
    public int StrCompare(char[] S, char[] T)
    {
        int i;
        for (i = 1; i <= S[0] && i <= T[0]; ++i)
            if (S[i] != T[i])
                return S[i] - T[i];
        return S[0] - T[0];
    }

    // Return number of elements
    public int StrLength(char[] S)
    {
        return S[0];
    }

    // Condition:string S is exist
    // Reuslt:clear string
    public boolean ClearString_(char[] S)
    {
        S[0] = 0;
        return true;
    }

    // Return new string with T,that is concated S1 and S2.If string is not concated,return TRUE,otherwise return FALSE
    public char[] Concat( char[] S1, char[] S2)
    {
        char[] T = new char[MAXSIZE];
        int i;
        if (S1[0] + S2[0] <= MAXSIZE)
        {
            // No truncation
            for (i = 1; i <= S1[0]; i++)
                T[i] = S1[i];
            for (i = 1; i <= S2[0]; i++)
                T[S1[0] + i] = S2[i];
            T[0] = (char) (S1[0] + S2[0]);
            return T;
        }
        else
        {
            // Truncate S2
            for (i = 1; i <= S1[0]; i++)
                T[i] = S1[i];
            for (i = 1; i <= MAXSIZE - S1[0]; i++)
                T[S1[0] + i] = S2[i];
            T[0] = MAXSIZE;
            return T;
        }
    }

    // Return substring with Sub,that starts from pos,whose length is len
    public char[] SubString_(char[] S, int pos, int len)
    {
        char[] Sub = new char[MAXSIZE];
        int i;
        // len>S[0]-pos+1
        if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos)
            return new char[]{'0'};
        for (i = 1; i <= len; i++)
            Sub[i] = S[pos + i - 1];
        Sub[0] = (char) len;
        return Sub;
    }

    // 例子：子串"abcfghijk"在主串"abcfghijkbcd"中第1个字符之后的位置(包括第一个字符)是1
    // 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0
    // Example: Substring is "abcfghijk", Mainstring is "abcfghijkbcd", result is 1
    // Return position,where substring in mainstring after pos_th string, if not exist, return 0
    // T is not null, 1≤pos≤StrLength(S)
    public int Index(char[] S, char[] T, int pos)
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
    public int Index2(char [] S, char [] T, int pos)
    {
        int n, m, i;
        char[] sub;
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
                sub = SubString_(S, i, m);
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
    public char[] StrInsert(char [] S, int pos, char [] T)
    {
        int i;
        if (pos<1 || pos>S[0] + 1)
            return S;
        if (S[0] + T[0] <= MAXSIZE)
        {
            // Complete insert
            // First insert back element(string S)
            for (i = S[0]; i >= pos; i--)
                S[i + T[0]] = S[i];
            // Second insert front element(string T)
            for (i = pos; i<pos + T[0]; i++)
                S[i] = T[i - pos + 1];
            S[0] = (char) (S[0] + T[0]);
            return S;
        }
        else
        {
            // Partially insert
            for (i = MAXSIZE; i >= pos; i--)
                S[i] = S[i - T[0]];
            for (i = pos; i<pos + T[0]; i++)
                S[i] = T[i - pos + 1];
            S[0] = MAXSIZE;
            return S;
        }
    }

    // Condition: string S is exist, 1≤pos≤StrLength(S)-len+1
    // Result: Delete string S' substring, that starts from the pos th character and whose length is len.
    public boolean StrDelete(char[] S, int pos, int len)
    {
        int i;
        if (pos<1 || pos>S[0] - len + 1 || len<0)
            return false;
        // It is similar with deleteNode from linear list
        for (i = pos + len; i <= S[0]; i++)
            S[i - len] = S[i];
        S[0] -= len;
        return true;
    }

    // Condition: If string S,T und V is exist, T is not empty string
    // Result: Replace mainstring S' substring, that is the same substring as T, with V.
    public boolean Replace(char[] S, char[] T, char[] V)
    {
        // From the first character of string s
        int i = 1;
        // If T is empty
        if (StrEmpty(T))
            return false;
        do
        {
            // Get the position of matched substring
            i = Index(S, T, i);
            // If string S includes string T
            if (i!=0)
            {
                // Delete string T
                StrDelete(S, i, StrLength(T));
                // Insert string V in the position of primary string T
                StrInsert(S, i, V);

                // Search the string T after the postion of string V
                i += StrLength(V);
            }
        } while (i!=0);
        return true;
    }

    // Print string
    public void StrPrint(char[] T)
    {
        int i;
        for (i = 1; i <= T[0]; i++)
            System.out.printf("%c", T[i]);
        System.out.println();
    }

    public static void main(String[] args) {
        String_ st = new String_();
        System.out.printf("Please input string s1:");
        char[] s1 = st.StrAssign(new char[]{'a','b','c','d'});
        if (s1.length == 0)
        {
            System.out.printf("Length of string is more than MAXSIZE (=%d)\n", MAXSIZE);
        }
        System.out.printf("Length of string is %d If string is empty? %b(1:true 0:false)\n", st.StrLength(s1), st.StrEmpty(s1));
        char [] s2 = st.StrCopy(s1);
        System.out.printf("Copy string s1 and generate new string:");
        st.StrPrint(s2);
        System.out.printf("Please input string s2:");

        s2 = st.StrAssign(new char[]{'e','f','g','h','i','j','k'});
        if (s2.length == 0)
        {
            System.out.printf("Length of string is more than MAXSIZE(%d)\n", MAXSIZE);
        }
        int i = st.StrCompare(s1, s2);
        char s;
        if (i<0)
            s = '<';
        else if (i == 0)
            s = '=';
        else
            s = '>';
        System.out.printf("String s1 %s string s2 \n", s);
        char[] t = st.Concat(s1, s2);
        System.out.printf("String s1 concats string s2, get string t:");
        st.StrPrint(t);
        st.ClearString_(s1);
        System.out.printf("After clearing the empty string, string s1 is:");
        st.StrPrint(s1);
        System.out.printf("Length of string is %d If string is empty？%b(1:true 0:false)\n", st.StrLength(s1), st.StrEmpty(s1));
        System.out.printf("Get substring of string t, please input initial position of substring, length of substring: ");

        i = 2;
        int j = 3;
        System.out.printf("%d,%d \n", i, j);

        s2 = st.SubString_(t, i, j);
        if (s2[0] != '0')
        {
            System.out.printf("Substring s2 is: ");
            st.StrPrint(s2);
        }
        System.out.printf("From the pos th character of string t, delete number of length character, please input pos,len ");

        i = 4;
        j = 2;
        System.out.printf("%d,%d \n", i, j);

        st.StrDelete(t, i, j);
        System.out.printf("After deleting, string t is:");
        st.StrPrint(t);
        i = 1;
        s2 = st.StrInsert(s2, i, t);
        System.out.printf("After inserting string t in the position of %d th of string s2, string s2 is:\n", i);
        st.StrPrint(s2);
        s2 = st.StrAssign(new char[]{'a','b','c','d','e','f','g'});
        t = st.StrAssign(new char[]{'c','d'});
        i = st.Index(s2, t, 3);
        System.out.printf("The position of substring t is after the 2th character of mainstring s2. The position is exactly %d\n", i);
        s2 = st.StrAssign(new char[]{'a','b','c','d','e','f','g','h','i'});
        t = st.StrAssign(new char[]{'f','g','h'});
        i = st.Index2(s2, t, 1);
        System.out.printf("T is not empty string. If after the first character of mainstring, that is equal to string T, the position is %d\n", i);
        t = st.SubString_(s2, 1, 1);
        System.out.printf("String t is:");
        st.StrPrint(t);
        s1 = st.Concat(t, t);
        System.out.printf("String s1 is:");
        st.StrPrint(s1);
        System.out.printf("String s2 is:");
        st.StrPrint(s2);
        st.Replace(s2, t, s1);
        System.out.printf("Replace string s2, that is the same wth string t ,with s1, string s2 is ");
        st.StrPrint(s2);
    }
}