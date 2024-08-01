//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int val[],int wt[],int W,int n,vector<vector<int>>& dp){
        if(n==0){
            return W/wt[0] * val[0];
        }
        if(dp[n][W]!=-1) return dp[n][W];
        long nottake = 0 + solve(val,wt,W,n-1,dp);
        long take = INT_MIN;
        if(wt[n]<=W) take = val[n] + solve(val,wt,W-wt[n],n,dp);
        return dp[n][W] = max(nottake,take);
       
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W+1,-1));
        return solve(val,wt,W,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends