//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(vector<vector<int>>& arr,vector<vector<int>>& dp,int days,int k){
        if(days==0){
            int maxi = 0;
            for(int i=0;i<=2;i++){
                
                if(i!=k) maxi = max(maxi,arr[0][i]);
            }
            return maxi;
        }
        if(dp[days][k]!=-1) return dp[days][k];
        int maxi = 0;
        int ans = INT_MIN;
        for(int i=0;i<=2;i++){
            if(i!=k)  ans = arr[days][i] + solve(arr,dp,days-1,i);
            maxi = max(maxi,ans);
        }
        return dp[days][k] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return solve(arr,dp,n-1,3);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends