class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int missing=-1;
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<=nums.size();i++){
            if(hash[i]==0){
                missing=i;
            }
        }
        return missing;
    }
};