1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6
7    bool isVowel(char ch)
8    {
9        return (ch == 'a' || ch == 'e' || ch == 'i' ||
10                ch == 'o' || ch == 'u');
11    }
12
13    int countVowelSubstrings(string word)
14    {
15        int answer = 0;
16        int n = word.size();
17
18        for(int i = 0; i < n; i++)
19        {
20            vector<int> frequency(26, 0);
21            int distinctVowels = 0;
22
23            for(int j = i; j < n; j++)
24            {
25                if(!isVowel(word[j]))
26                {
27                    break;
28                }
29
30                int index = word[j] - 'a';
31
32                if(frequency[index] == 0)
33                {
34                    distinctVowels++;
35                }
36
37                frequency[index]++;
38
39                if(distinctVowels == 5)
40                {
41                    answer++;
42                }
43            }
44        }
45
46        return answer;
47    }
48};