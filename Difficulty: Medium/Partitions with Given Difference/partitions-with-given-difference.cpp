//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int mod = (int)1e9+7;
    int solve(vector<int>& arr,vector<vector<int>>& dp,int ind,int tar){
        if(ind==0){
            if(tar==0 && tar==arr[0]) return 2;
            else if(tar==0 || tar==arr[0]) return 1;
            else return 0;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int ntake = solve(arr,dp,ind-1,tar);
        int take = 0;
        if(arr[ind]<=tar) take = solve(arr,dp,ind-1,tar-arr[ind]);
        return dp[ind][tar] = (take+ntake)% mod;
    }
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum-d<0 || (sum-d)%2!=0) return false;
        int k = (sum-d)/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(arr,dp,n-1,k);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends