class Solution {
    int sol(vector<int>& arr,int target,int n){
        vector<vector<int>> dp(n, vector<int>(target+1,0));
        if(arr[0]==0) dp[0][0] = 2;
        else dp[0][0]=1;
        if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(arr[i]<=j) take = dp[i-1][j-arr[i]];
                dp[i][j] = (nottake + take);
            }
        }
        return dp[n-1][target];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totsum = 0;
        for(int i=0;i<n;i++){
            totsum+=arr[i];
        }
        if(totsum-d<0 || (totsum-d)%2!=0) return false;
        return sol(arr,(totsum-d)/2,n);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return countPartitions(n,target,nums);
    }
};