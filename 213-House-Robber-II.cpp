class Solution {
public:
    int robRange(vector<int>& nums, int l, int r) {
        int prev1 = 0, prev2 = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];  
        
        int case1 = robRange(nums, 0, n-2);
        int case2 = robRange(nums, 1, n-1);
        
        return max(case1, case2);
    }
};
