1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        int min_val = *min_element(nums.begin(), nums.end());
5        int max_val = *max_element(nums.begin(), nums.end());
6        
7        return (long long)k *(max_val - min_val);
8        
9    }
10};