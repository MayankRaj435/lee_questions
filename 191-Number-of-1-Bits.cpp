class Solution {
public:
    int hammingWeight(int n) {
         return __builtin_popcount(n); // not for long long ,use _builtin_popcountll
        
    }
};