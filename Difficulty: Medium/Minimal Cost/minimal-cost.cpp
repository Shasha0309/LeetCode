//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(int k,vector<int>& dp,vector<int> &nums,int n){ 
        int ans = INT_MAX;
        dp[0] = 0;
        if(dp[n] != -1) return dp[n];
        for(int i=1;i<=k;i++){
           if(n-i>=0) {int right = solve(k,dp,nums,n-i) + abs(nums[n]-nums[n-i]);
            ans = min(ans,right);
           }
        }
        return dp[n] = ans;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n+1,-1);
        int res = solve(k,dp,arr,n-1);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends