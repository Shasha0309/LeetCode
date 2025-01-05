//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
       /* int i=0;
        int j=0;
        vector<int> ans;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]) {
                if(ans.size()==0 || ans.back()!=a[i]){
                    ans.push_back(a[i]);
                    i++;
                }
            }
                else{
                    if(ans.size()==0 || ans.back()!=b[j]){
                        ans.push_back(b[j]);
                        j++;
                    }
                }
            }
        while(i<a.size()){
            if(ans.back()!=a[i]){
            ans.push_back(a[i]);
            i++;
            }
        }
        while(j<b.size()){
            if(ans.back()!=b[j]){
            ans.push_back(b[j]);
            j++;
            }
        }
        return ans;*/
        int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < a.size() && j < b.size()) {
    if (a[i] <= b[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != a[i])
        Union.push_back(a[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != b[j])
        Union.push_back(b[j]);
      j++;
    }
  }
  while (i < a.size()) // IF any element left in arr1
  {
    if (Union.back() != a[i])
      Union.push_back(a[i]);
    i++;
  }
  while (j < b.size()) // If any elements left in arr2
  {
    if (Union.back() != b[j])
      Union.push_back(b[j]);
    j++;
  }
  return Union;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends