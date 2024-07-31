//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = (int)(1e9+7);
    long long int solve(int arr[],int n, int sum,vector<vector<int>>& dp){
        if(n==0){
        if(sum==0 && arr[0]==0) return 2;
        if(sum==0 || arr[0]==sum) return 1;
        return 0;
        }
        
        if(dp[n][sum] != -1) return dp[n][sum];
        int nottake = solve(arr,n-1,sum,dp);
        int take = 0;
        if(arr[n]<=sum) take = solve(arr,n-1,sum-arr[n],dp);
        
        return dp[n][sum] = (nottake + take) % mod;
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return solve(arr,n-1,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends