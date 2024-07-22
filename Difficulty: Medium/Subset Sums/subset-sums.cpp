//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void solve(int ind,int s,vector<int> &ans,vector<int> arr,int n){
        if(ind==n){
            ans.push_back(s);
            return;
        }
        solve(ind+1,s+arr[ind],ans,arr,n);
        solve(ind+1,s,ans,arr,n);
        
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        solve(0,0,ans,arr,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends