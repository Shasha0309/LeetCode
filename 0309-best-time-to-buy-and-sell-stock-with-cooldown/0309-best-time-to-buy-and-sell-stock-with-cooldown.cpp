class Solution {
    int solve(vector<int> prices,int ind,int buy,vector<vector<int>>& dp){
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+solve(prices,ind+1,0,dp),0+solve(prices,ind+1,1,dp));
        }
        else{
            profit = max(prices[ind]+solve(prices,ind+2,1,dp),0+solve(prices,ind+1,0,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                   dp[i][j] = max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }
                else{
                    dp[i][j] = max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};