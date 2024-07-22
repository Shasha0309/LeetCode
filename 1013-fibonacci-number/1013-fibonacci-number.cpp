class Solution {
    int solve(int n,vector<int> &dp){
        if(n<=1) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
public:
    int fib(int n) {
        int prev2 = 0;
        int prev = 1;
        if(n==0) return prev2;
        if(n==1) return 1;
        for(int i=2;i<=n;i++){
             int curri=prev2+prev;
            prev2 = prev;
            prev=curri;
        }
        return prev;
    }
};