//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long sum1 = 0;
        //long long sum2 = 0;
        long long total_sum = 0;
        int i=0;
        while(i<N-1){
            sum1 = arr[i]+arr[i+1];
            if(sum1>total_sum){
                total_sum = sum1;
            }
            i++;
        }
        return total_sum;
    }
    
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends