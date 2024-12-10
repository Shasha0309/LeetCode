//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int solve(vector<int>& val,vector<int>& wt,vector<vector<int>>& dp,int ind,int tar){
        if(ind==0){
        
                return tar/wt[0]*val[0];
            
            
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        long ntake = solve(val,wt,dp,ind-1,tar);
        long take = -1e9;
        if(wt[ind]<=tar) take = val[ind]+solve(val,wt,dp,ind,tar-wt[ind]);
        return dp[ind][tar] = max(take,ntake);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return solve(val,wt,dp,n-1,capacity);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends