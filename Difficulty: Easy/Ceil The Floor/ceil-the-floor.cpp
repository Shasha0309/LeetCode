//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
    int floord(vector<int> arr,int x, int n){
        int low = 0;
        int high = n-1;
        int mid;
        int ans = -1;
        while(low<=high){
            mid = low+(high-low)/2;
            if(arr[mid]<=x){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans!=-1 ? arr[ans] : -1;
    }
    int ceild(vector<int> arr,int x, int n){
        int low = 0;
        int high = n-1;
        int mid;
        int ans = -1;
        while(low<=high){
            mid = low+(high-low)/2;
            if(arr[mid]>=x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans!=-1 ? arr[ans] : -1;
    }
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int f = floord(arr,x,n);
        int c = ceild(arr,x,n);
        return {f,c};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends