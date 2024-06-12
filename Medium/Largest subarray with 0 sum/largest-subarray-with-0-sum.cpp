//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        /*int ans = 0;
        int count = 0;
        int x = 0;
        for(int i=0;i<n;i++){
            x += A[i];
            if(x<=0){
                count++;
            }
            if(x>0) x=0;
            ans = max(ans,count);
        }
        return ans;*/
        unordered_map<int, int> mpp;
    int ans = 0, sum = 0;
    
    mpp[0] = -1;
    
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (mpp.find(sum)!= mpp.end()) {
            ans = max(ans, i - mpp[sum]);
        } else {
            mpp[sum] = i;
        }
    }
    
    return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends