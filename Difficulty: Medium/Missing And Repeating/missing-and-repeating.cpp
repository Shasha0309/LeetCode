//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        map<int,int> mpp;
        vector<int> ans(2,0);
        for(int i=1;i<n+1;i++){
            mpp[i] = 0;
        }
        
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(auto it:mpp){
            if(it.second==2) ans[0] = it.first;
            if(it.second==0) ans[1] = it.first;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends