//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int n,int Wf,int val[],int wt[],vector<vector<int>>&dp){
        if(n==0){
            return Wf/wt[0] * val[0]; 
        }
        if(dp[n][Wf]!=-1) return dp[n][Wf];
        long notpick=0+solve(n-1,Wf,val,wt,dp);
        long pick = INT_MIN;
        if(wt[n]<=Wf) pick = val[n]+solve(n,Wf-wt[n],val,wt,dp);
        return dp[n][Wf]=max(notpick,pick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
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
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends