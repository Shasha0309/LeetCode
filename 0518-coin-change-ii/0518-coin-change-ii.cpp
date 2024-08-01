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
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
            dp[0][i] = 1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                long nottake = dp[i-1][j];
                long take = 0;
                if(coins[i]<=j) take = dp[i][j-coins[i]];
                dp[i][j] = nottake + take;
            }
        }
        return dp[n-1][amount];
    }
};