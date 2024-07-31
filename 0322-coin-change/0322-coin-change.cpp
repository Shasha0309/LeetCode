class Solution {
    int solve(vector<int>& coins,int amount,int n,vector<vector<int>>& dp){
        if(n==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
        int nottake = 0 + solve(coins,amount,n-1,dp);
        int take = 1e9;
        if(coins[n]<=amount) take = 1 + solve(coins,amount-coins[n],n,dp);
        return dp[n][amount] = min(nottake,take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans =  solve(coins,amount,n-1,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};