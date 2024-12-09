class Solution {
    int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int row,int col){
        if(row==0 && col==0) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int up = INT_MAX;
        int left = INT_MAX;
        if(row!=0) up = grid[row][col]+solve(grid,dp,row-1,col);
        if(col!=0) left = grid[row][col]+solve(grid,dp,row,col-1);
        return dp[row][col] = min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(grid,dp,m-1,n-1);
    }
};