//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
     int mod = (int)(1e9+7);
    int solve(vector<int>& arr,int n, int sum,vector<vector<int>>& dp){
        if(n==0){
            if(sum==0 && arr[0]==0)return 2;
            if(sum==0 || arr[0]==sum)return 1;
            return 0;
        }
        
        if(dp[n][sum] != -1) return dp[n][sum];
        int nottake = solve(arr,n-1,sum,dp);
        int take = 0;
        if(arr[n]<=sum) take = solve(arr,n-1,sum-arr[n],dp);
        
        return dp[n][sum] = (nottake + take) % mod;
    }
    int sol(vector<int>& arr,int target,int n){
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return solve(arr,n-1,target,dp);
    }
public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totsum = 0;
        for(int i=0;i<n;i++){
            totsum+=arr[i];
        }
        if(totsum-d<0 || (totsum-d)%2!=0) return false;
        return sol(arr,(totsum-d)/2,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends