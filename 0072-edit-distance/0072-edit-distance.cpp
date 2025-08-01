class Solution {
    int sol(int i,int j,string w1,string w2,vector<vector<int>>& dp){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i-1]==w2[j-1]) return dp[i][j] = 0+sol(i-1,j-1,w1,w2,dp);
        else return dp[i][j] = 1+ min(sol(i,j-1,w1,w2,dp),min(sol(i-1,j,w1,w2,dp),sol(i-1,j-1,w1,w2,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return sol(n,m,word1,word2,dp);
    }
};