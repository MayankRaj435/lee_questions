1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string result;
5        
6        for (const string& word : words) {
7            int sumWeight = 0;
8            
9            for (char ch : word) {
10                sumWeight += weights[ch - 'a'];
11            }
12            
13            int value = sumWeight % 26;
14            
15            result.push_back(char('z' - value));
16        }
17        
18        return result;
19    }
20};