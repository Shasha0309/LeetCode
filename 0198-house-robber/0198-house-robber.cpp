class Solution {
    int solve(vector<int>& dp,vector<int>& num,int ind){
        if(ind==0) return num[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ntake = 0+solve(dp,num,ind-1);
        int take = num[ind]+solve(dp,num,ind-2);
        return dp[ind]=max(ntake,take);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(dp,nums,n-1);
    }
};