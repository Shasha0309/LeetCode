//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int ind,int N,int price[],vector<vector<int>>& dp){
        if(ind==0){
            return N*price[0];
        }
        if(dp[ind][N]!=-1) return dp[ind][N];
        int nottake = 0 + solve(ind-1,N,price,dp);
        int take = -1e9;
        int rodlen = ind+1;
        if(rodlen<=N) take = price[ind] + solve(ind,N-rodlen,price,dp);
        return dp[ind][N] = max(nottake,take);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends