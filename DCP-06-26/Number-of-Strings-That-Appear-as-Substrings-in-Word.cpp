1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        int count=0;
5        for(int i=0;i<patterns.size();i++){
6            if (word.find(patterns[i]) != string::npos) {
7                count++;
8            }
9        }
10        return count;
11    }
12};