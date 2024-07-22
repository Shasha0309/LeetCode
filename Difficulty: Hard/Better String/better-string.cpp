//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int solve(string &str){
        int count = 1;
        int newCount;
        unordered_map<char,int> mpp;
        
        for(auto ch:str){
            newCount = count*2;
            if(mpp.find(ch)!=mpp.end()){
                newCount -= mpp[ch];
            }
            mpp[ch] = count;
            count = newCount;
        }
        return count;
    }
  public:
    string betterString(string str1, string str2) {
        // code here
        if(str1.length()>str2.length() || str1==str2) return str1;
        if(str2.length()>str1.length()) return str2;
        
        int l = solve(str1);
        int r = solve(str2);
        
        if(r>l) return str2;
        return str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends