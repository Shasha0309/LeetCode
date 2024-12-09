//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    bool solve(vector<int>& arr,vector<vector<int>>& dp,int tar,int ind){
        if(tar==0) return true;
        if(ind==0) return arr[0]==tar;
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        bool ntake = solve(arr,dp,tar,ind-1);
        bool take = false;
        if(arr[ind]<=tar) take = solve(arr,dp,tar-arr[ind],ind-1);
        return dp[ind][tar] = (ntake || take);
        
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(arr,dp,target,n-1);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends