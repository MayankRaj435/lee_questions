class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                maxi=max(maxi, (j-i) * min(height[i],height[j]));
            }
        }
        return maxi;
    }
};