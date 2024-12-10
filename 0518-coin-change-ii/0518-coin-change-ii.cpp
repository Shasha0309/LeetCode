class Solution {
    int mod = (int)1e9+7;
    int solve(vector<int>& arr,vector<vector<int>>& dp,int ind,int tar){
        if(ind==0) return tar%arr[0]==0;
    
        if(dp[ind][tar]!=-1) return dp[ind][tar];

        int ntake = solve(arr,dp,ind-1,tar);
        int take = 0;
        if(arr[ind]<=tar) take = solve(arr,dp,ind,tar-arr[ind]);
        return dp[ind][tar] = ntake+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(coins,dp,n-1,amount);
      //  if(ans==1e9) return 0;
        return ans;
    }
};