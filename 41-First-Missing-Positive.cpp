class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.erase(remove_if(nums.begin(), nums.end(), [](int n) { return n <= 0; }), nums.end());

        sort(nums.begin(), nums.end());

        int target = 1;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == target) {
                target++;
            } else if (nums[i] > target) {
                return target;
            }
        }
        
        return target;        
    }
};