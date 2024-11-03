//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = (int)(1e9+7);
	long long int solve(int arr[],int sum,int ind,vector<vector<int>>& dp){
	    if(ind==0){
	        if(sum==0 && arr[0]==sum) return 2;
	        else if(sum==0 || arr[0]==sum) return 1;
	        else return 0;
	    }
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int notpick = solve(arr,sum,ind-1,dp);
	    int pick = 0;
	    if(arr[ind]<=sum) pick = solve(arr,sum-arr[ind],ind-1,dp);
	    return dp[ind][sum] = (notpick+pick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(arr,sum,n-1,dp);
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
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends