1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st ; 
5        for (int i = 0 ;  i< s.length() ; i++)
6        {
7            char ch = s[i];
8            if (ch == '(' || ch == '{' || ch == '[')
9            {
10                st.push(ch) ; 
11            }
12            else {
13
14                if (!st.empty())
15                {
16                    char top = st.top() ;
17                    if ((ch == ')' && top == '(') || 
18                        (ch == '}' && top == '{') ||
19                        (ch == ']' && top == '[')) 
20                        {
21                            st.pop() ;
22                        }
23                        else 
24                        {
25                            return false ; 
26                        }
27                }
28                else 
29                {
30
31                    return false ;
32                }
33            }
34        }
35
36        if (st.empty())
37        {
38            return true ; 
39        }
40        return false ;
41    }
42};