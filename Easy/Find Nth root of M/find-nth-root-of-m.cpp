//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    long long func(long long x, int n){
        if (n == 0) return 1;
        long long temp = func(x, n / 2);
        temp = temp * temp;
        if (n % 2 != 0) temp = temp * x;
        return temp;
    }
	public:
	int NthRoot(int n, int m)
	{
	    if (m == 0) return 0;
        if (m == 1) return 1;

        int low = 1;
        int high = m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long midN = func(mid, n);
            
            if (midN == m) {
                return mid;
            } else if (midN < m && midN > 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
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