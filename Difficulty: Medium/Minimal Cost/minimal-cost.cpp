//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(vector<int> &nums,vector<int>& dp,int n,int k){
        int ans = INT_MAX;
        dp[0] = 0;
        if(dp[n] != -1) return dp[n];
        for(int i=1;i<=k;i++){
           if(n-i>=0) {int right = solve(nums,dp,n-i,k) + abs(nums[n]-nums[n-i]);
            ans = min(ans,right);
           }
        }
        return dp[n] = ans;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n+1,-1);
        return solve(height,dp,n-1,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends