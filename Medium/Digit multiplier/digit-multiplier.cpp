//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string getSmallest(long long N) {
        // code here
        string ans = "";
        if(N==1) return "1";
        for(int i=9;i>=2;i--){
            while(N%i==0){
                N = N/i;
                ans += to_string(i);
            }
        }
        if(N!=1){
            return "-1";
        }
        else{
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.getSmallest(N) << endl;
    }
    return 0;
}
// } Driver Code Ends