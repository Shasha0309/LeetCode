class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        for(int i=0;i<n;i++) dp[0][i] = matrix[0][i];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int a = matrix[i][j]+dp[i-1][j];
                int b = matrix[i][j]+((j-1>=0) ? dp[i-1][j-1] : 1e9);
                int c = matrix[i][j]+((j+1<n) ? dp[i-1][j+1] : 1e9);
                dp[i][j] = min(a, min(b,c)); 
            }
        }
        int mini = dp[m-1][0];
        for(int i=1;i<n;i++){
            mini = min(mini,dp[m-1][i]);
        }
        return mini;
    }
};