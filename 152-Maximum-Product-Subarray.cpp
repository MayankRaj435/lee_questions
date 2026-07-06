class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1;
        int n=nums.size();
        int suff=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(pre==0) pre=1;
            pre=pre*nums[i];
            if(suff==0) suff=1;
            suff=suff*nums[n-i-1];

            ans=max(ans,max(pre,suff));
        }
        return ans;
    }
};