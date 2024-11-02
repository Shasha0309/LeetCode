class Solution {
    int solve(vector<int>& nums,vector<int>& dp,int n){
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick = nums[n]+solve(nums,dp,n-2);
        int notpick = solve(nums,dp,n-1);
        return dp[n] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> nums1, nums2;
       for(int i=0;i<n;i++){
        if(i!=n-1) nums1.push_back(nums[i]);
        if(i!=0) nums2.push_back(nums[i]);
       }
       vector<int> dp1(n,-1);
       vector<int> dp2(n,-1);
       return max(solve(nums1,dp1,n-2),solve(nums2,dp2,n-2));
    }
};