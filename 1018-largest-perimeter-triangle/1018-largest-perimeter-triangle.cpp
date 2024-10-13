class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        int ans = 0;
        for(int i=2;i<nums.size();i++){
            if(nums[i-1]+nums[i-2]>nums[i]){
                sum=nums[i-1]+nums[i-2]+nums[i];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};