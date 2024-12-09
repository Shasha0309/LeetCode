class Solution {
    int solve(vector<vector<int>>& trian,vector<vector<int>>& dp,int n,int r,int i){
        if(r==n-1) return trian[r][i];
        if(dp[r][i]!=-1) return dp[r][i];
        int down = trian[r][i] + solve(trian,dp,n,r+1,i);
        int diag = trian[r][i] + solve(trian,dp,n,r+1,i+1);
        return dp[r][i] = min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(triangle,dp,n,0,0);
    }
};