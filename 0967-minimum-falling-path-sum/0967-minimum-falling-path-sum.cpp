class Solution {
    int solve(vector<vector<int>>& matrix,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(j<0 || j>=n) return 1e9;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        int a = matrix[i][j]+solve(matrix,i-1,j,m,n,dp);
        int b = matrix[i][j]+((j!=0) ? solve(matrix,i-1,j-1,m,n,dp) : 1e9);
        int c = matrix[i][j]+((j<n-1) ? solve(matrix,i-1,j+1,m,n,dp) : 1e9);
        return dp[i][j] = min(a, min(b,c));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        int mini = 1e9;
        for(int i=0;i<n;i++){
        mini = min (mini,solve(matrix,m-1,i,m,n,dp));
        }
        return mini;
    }
};