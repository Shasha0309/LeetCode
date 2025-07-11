class Solution {
    bool sol(vector<int>& nums,int idx,vector<int>& dp){
        if(idx==nums.size()-1) return true;
        if(nums[idx]==0) return false;
        if(dp[idx]!=-1) return dp[idx];
        int reach = idx + nums[idx];
        for(int i=idx+1;i<=reach;i++){
            if(i<nums.size() && sol(nums,i,dp)) return dp[idx]=true;
        } 
        return dp[idx] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        /*int n = nums.size();
        vector<int> dp(n,0);
        dp[n-1] = 1;
        for(int i=n-2;i>=0;i--)*/
        vector<int> dp(nums.size(),-1);
        return sol(nums,0,dp);
    }
};