class Solution {
    int solve(vector<int> &nums,vector<int>& dp,int ind){
         dp[0] = nums[0];

         for(int i=1;i<ind;i++){
         int pick = nums[i];
         if(i>1) pick += dp[i-2];
         int notpick = dp[i-1];
         
        dp[i] = max(pick,notpick);
         }
         return dp[ind-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,n);
    }
};