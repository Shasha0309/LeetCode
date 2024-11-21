//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
          vector<pair<double, int>> a(val.size());

        int j = 0;
        double max = 0;
        for(int i = 0; i < val.size(); i++) {
            a[i] = { (double)val[i] / wt[i], wt[i] };
        }

        // Correctly closing the sort function's lambda and the `sort` call.
        sort(a.begin(), a.end(), [](pair<double, int>& p1, pair<double, int>& p2) {
            return p1.first > p2.first; // Sort by value-to-weight ratio in descending order
        });//this function is requires here because we want in descending order instead of ascending order

        while(capacity > 0 && j < a.size()) {    
            if(capacity > a[j].second) {
                max += a[j].first * a[j].second;
                capacity -= a[j].second;
            } else {
                max += a[j].first * capacity;
                capacity = 0;
            }
            j++;
        }
        return max;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends