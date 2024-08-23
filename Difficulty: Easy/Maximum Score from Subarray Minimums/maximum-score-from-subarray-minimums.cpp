//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            st.push(arr[i]);
        }
        int i=0;
        int sum = 0;
        int ans = 0;
        while(i<arr.size()-1){
            sum=0;
            sum = st.top();
            st.pop();
            sum += st.top();
            ans=max(ans,sum);
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends