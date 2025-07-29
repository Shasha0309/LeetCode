class Solution {
    int sol(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 || grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = sol(i-1,j,dp,grid);
        int right = sol(i,j-1,dp,grid);
        return dp[i][j] = up+right; 

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //if(obstacleGrid[0][0]==1) return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
         //int dp[m][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                int up=0;
                int right=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) right = dp[i][j-1];
                dp[i][j] = up+right;
                }
            }
        }
        return dp[n-1][m-1];
    }
};