//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int solve(int mid,int n,int m){
        long long ans1=1;
        for(int i=1;i<=n;i++){
            ans1 = ans1*mid;
            if(ans1>m) return 2;
        }
        if(ans1==m) return 1;
        return 0;
    }
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    if (m == 0) return 0;
        if (m == 1) return 1;
	    int low = 1;
	    int high = m;
	    int mid;
	    while(low<=high){
	        mid = low+(high-low)/2;
	        long long midNN = solve(mid,n,m);
	        if(midNN==1) return mid;
	        else if(midNN==0) low = mid+1;
	        else{
	            high = mid-1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends