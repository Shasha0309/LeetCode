class Solution {
    bool sol(int i,int j,string& s,string& p,vector<vector<int>>& dp){
        if(i<0 && j<0) return 1;
        if(i>=0 && j<0) return 0;
        if(i<0 && j>=0){
            for(int ii=0;ii<=j;ii++){
                if(p[ii]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = sol(i-1,j-1,s,p,dp);
        if(p[j]=='*'){
            return dp[i][j] = sol(i-1,j,s,p,dp) | sol(i,j-1,s,p,dp);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
       vector<vector<int>> dp(n,vector<int>(m,-1));
       return sol(n-1,m-1,s,p,dp);
    }
};