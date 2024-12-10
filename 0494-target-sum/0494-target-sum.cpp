class Solution {
    int solve(vector<int>& nums,vector<vector<int>>& dp,int ind,int tar){
        if(ind==0){
            if(tar==0 && nums[0]==tar) return 2;
            else if(tar==0 || nums[0]==tar) return 1;
            else return 0;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int ntake = solve(nums,dp,ind-1,tar);
        int take = 0;
        if(nums[ind]<=tar) take = solve(nums,dp,ind-1,tar-nums[ind]);
        return dp[ind][tar] = ntake+take;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for(int i=0;i<n;i++){
            totsum+=nums[i];
        }
        if(totsum<target || (totsum-target)%2!=0) return 0;
        int k = (totsum-target)/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(nums,dp,n-1,k);
    }
};