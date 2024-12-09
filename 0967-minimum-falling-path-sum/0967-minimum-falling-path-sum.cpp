class Solution {
    int solve(vector<vector<int>>& mat,vector<vector<int>>& dp,int f,int row,int col){
        if(col<0 || col>=f) return 1e9;
        if(row==0) return mat[row][col];
        
        if(dp[row][col]!=1e9) return dp[row][col];
 
        int up = mat[row][col] + solve(mat,dp,f,row-1,col);
        int upleft = mat[row][col] + solve(mat,dp,f,row-1,col-1);
        int upright = mat[row][col] + solve(mat,dp,f,row-1,col+1);
        return dp[row][col] = min(up,min(upleft,upright));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        int maxi = INT_MAX;
        for(int i=0;i<n;i++){
            int ans = solve(matrix,dp,n,n-1,i);
            maxi = min(maxi,ans);
        }
        return maxi;
    }
};