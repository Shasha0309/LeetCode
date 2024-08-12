class Solution {
    int solve(int inds,int indt,string s,string t){
        if(indt<0) return 1;
        if(inds<0) return 0;
        if(s[inds]==t[indt]){
            return (solve(inds-1,indt-1,s,t)+solve(inds-1,indt,s,t));
        }
        else{
            return solve(inds-1,indt,s,t);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<double>> dp(n1+1,vector<double>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n1][n2];
    }
};