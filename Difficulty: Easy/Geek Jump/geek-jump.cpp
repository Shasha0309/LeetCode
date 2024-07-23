//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(vector<int>& dp,vector<int> &nums,int n){
        dp[0] = 0;
        if(dp[n]!=-1) return dp[n];
        int right = INT_MAX;
        int left = solve(dp,nums,n-1) + abs(nums[n]-nums[n-1]);
        if(n>1) right = solve(dp,nums,n-2) + abs(nums[n]-nums[n-2]);
        return dp[n] = min(left,right);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return solve(dp,height,n-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends