class Solution {
    int solve(vector<int>& coins,int n,vector<vector<int>>& dp,int amt){
        if(n==0) return (amt%coins[0]==0);
        if(dp[n][amt]!=-1) return dp[n][amt];
        int nottake = solve(coins,n-1,dp,amt);
        int take = 0;
        if(coins[n]<=amt) take = solve(coins,n,dp,amt-coins[n]);
        return dp[n][amt] = take + nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(coins,n-1,dp,amount);
    }
};