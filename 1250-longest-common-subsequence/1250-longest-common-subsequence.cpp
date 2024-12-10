class Solution {
    int solve(string t1,string t2,vector<vector<int>>& dp,int ind1,int ind2){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(t1[ind1]==t2[ind2]) return dp[ind1][ind2] = 1+solve(t1,t2,dp,ind1-1,ind2-1);
       else  return dp[ind1][ind2] = 0+max(solve(t1,t2,dp,ind1-1,ind2),solve(t1,t2,dp,ind1,ind2-1)); 
    
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(text1,text2,dp,n-1,m-1);
    }
};