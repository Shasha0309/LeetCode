class Solution {
   /* void solve(vector<int>& dp,int n){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[]
        dp[n]=solve(dp,n-1)+solve(dp,n-2);
    }*/
public:
    int climbStairs(int n) {
        if(n<2) return n;
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};