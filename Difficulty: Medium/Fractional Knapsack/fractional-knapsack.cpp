//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


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
  bool static comp(Item a,Item b){
      double r1 = (double) a.value / (double) a.weight;
      double r2 = (double) b.value / (double) b.weight;
      return r1>r2;
  }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr,arr+n,comp);
        int weig = 0;
        double curval = 0.0;
        
        for(int i=0;i<n;i++){
            if(weig+arr[i].weight<=w){
                weig+=arr[i].weight;
                curval += arr[i].value;
            }
            else{
                int wres = w-weig;
                curval += (arr[i].value/(double) arr[i].weight) * (double)wres;
                break;
            }
        }
        return curval;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends