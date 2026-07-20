class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int subarrays = 1;
        long long currSum = 0;

        for (int num : nums) {
            if (currSum + num <= maxSum) {
                currSum += num;
            } else {
                subarrays++;
                currSum = num;

                if (subarrays > k)
                    return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;      // try to minimize the answer
            } else {
                low = mid + 1;       // increase allowed maximum sum
            }
        }

        return ans;
    }
};