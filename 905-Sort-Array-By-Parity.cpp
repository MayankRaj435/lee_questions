class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
    // vector<int> ans;                                  //first approach

    // for(int x : nums)
    //     if(x % 2 == 0)
    //         ans.push_back(x);

    // for(int x : nums)
    //     if(x % 2 != 0)
    //         ans.push_back(x);

    // return ans;
    //     }
    // };

stable_partition(nums.begin(), nums.end(),[](int x){   // this will be used to put even first and then odd while preserving the order   and if one doesn't want to maintain preserve the order just remove "stable" from the method .
        return x % 2 == 0;
 });
        return nums;
}
};