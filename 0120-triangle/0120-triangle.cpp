class Solution {
   /* int solve(vector<vector<int>>& triangle,int n,int r,int i,vector<vector<int>>& dp){
        if(r==n-1){
            return triangle[r][i];
        }
        if(dp[r][i]!=-1) return dp[r][i];
        int down = triangle[r][i] + solve(triangle,n,r+1,i,dp);
        int diag = triangle[r][i] + solve(triangle,n,r+1,i+1,dp);
        return dp[r][i] = min(down,diag);
    }*/
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
       // return solve(triangle,n,0,0,dp);
       for(int i=0;i<n;i++){
        dp[n-1][i] = triangle[n-1][i];
       }
       for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = triangle[i][j]+dp[i+1][j];
            int diag = triangle[i][j]+dp[i+1][j+1];
            dp[i][j] = min(down,diag);
            }
        }
       return dp[0][0];
        }
};