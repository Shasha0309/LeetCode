class Solution {
    bool solve(vector<int>& nums,vector<vector<int>>& dp,int tar,int ind){
        if(tar==0) return true;
        if(ind==0) return nums[0]==tar;
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        bool ntake = solve(nums,dp,tar,ind-1);
        bool take = false;
        if(nums[ind]<=tar) take = solve(nums,dp,tar-nums[ind],ind-1);
        return dp[ind][tar] = ntake || take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        else{
        int k = sum/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(nums,dp,k,n-1);
        }
    }
};