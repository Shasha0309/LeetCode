class Solution {
    int solve(vector<int> &nums,vector<int>& dp,int ind){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind] != -1) return dp[ind];

         int pick = nums[ind] + solve(nums,dp,ind-2);
         int notpick = 0 + solve(nums,dp,ind-1);
        
        return dp[ind] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,n-1);
    }
};