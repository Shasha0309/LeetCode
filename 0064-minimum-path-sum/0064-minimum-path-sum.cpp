class Solution {
    int sol(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[0][0];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = INT_MAX;
        int right = INT_MAX;
        if(i!=0) up = grid[i][j] + sol(i-1,j,dp,grid);
        if(j!=0) right = grid[i][j] + sol(i,j-1,dp,grid);
        return dp[i][j]=min(up,right);
     }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             if(i==0 && j==0) {
                dp[0][0] = grid[0][0];
             }
        else{
            int up = grid[i][j];
            if(i!=0) up+=dp[i-1][j];
            else up+=1e9;
             int ri = grid[i][j];
            if(j!=0) ri+=dp[i][j-1];
            else ri+=1e9;
            dp[i][j]=min(up,ri);
        }
        }
       }
       return dp[n-1][m-1];
    }
};