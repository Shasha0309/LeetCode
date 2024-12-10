class Solution {
    int solve(vector<int>& arr,vector<vector<int>>& dp,int ind,int tar){
        if(ind==0){
            if(tar%arr[0]==0) return tar/arr[0];
            else return 1e9+7;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int ntake = 0+solve(arr,dp,ind-1,tar);
        int take = 1e9;
        if(arr[ind]<=tar) take = 1+solve(arr,dp,ind,tar-arr[ind]);
        return dp[ind][tar] = min(ntake,take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =  solve(coins,dp,n-1,amount);
        if(ans>=1e9) return -1;
        return ans;
    }
};