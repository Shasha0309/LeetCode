class Solution {
    int sol(int n,vector<int>& dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=sol(n-1,dp)+sol(n-2,dp);
    }
public:
    int climbStairs(int n) {
     //   vector<int> dp(n+1,-1);
        int prev = 1;
        int prev2 = 1;
        for(int i=2;i<=n;i++){
            int curr = prev2 + prev;
            prev2 = prev;
            prev=curr;
        }
        return prev;
    }
};