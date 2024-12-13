class Solution {
    int solve(vector<int>& num,vector<vector<int>>& dp,int n,int ind,int prev){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int ntake = 0+solve(num,dp,n,ind+1,prev);
        int take = 0;
        if(prev==-1 || num[ind]>num[prev]){
            take = 1+solve(num,dp,n,ind+1,ind);
        }
        return dp[ind][prev+1] = max(ntake,take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return solve(nums,dp,n,0,-1);
    }
};