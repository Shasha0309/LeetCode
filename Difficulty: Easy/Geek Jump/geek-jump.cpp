//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(vector<int>& dp,vector<int>& height,int ind){
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int jutwo = INT_MAX;
        int jutone = solve(dp,height,ind-1)+abs(height[ind-1]-height[ind]);
        if(ind>1) jutwo = solve(dp,height,ind-2)+abs(height[ind-2]-height[ind]);
        return dp[ind]=min(jutone,jutwo);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        int res = solve(dp,height,n-1);
        return res;
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
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends