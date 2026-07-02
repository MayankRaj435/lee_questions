1class Solution {
2public:
3    void nextPermutation(vector<int>& nums) {
4        int ind=-1;
5        for(int i=nums.size()-2;i>=0;i--){
6            if(nums[i]<nums[i+1]){
7                ind=i;
8                break;
9            }
10        }
11        if(ind==-1){
12            reverse(nums.begin(),nums.end());
13            return;
14        }
15        for(int i=nums.size()-1;i>ind;i--){
16            if(nums[i]>nums[ind]){
17                swap(nums[i],nums[ind]);
18                break;
19            }
20        }
21        reverse(nums.begin()+ind+1,nums.end());
22    }
23};