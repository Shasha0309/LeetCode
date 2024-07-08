//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
     struct data{
        int strt;
        int endl;
    };
    bool static comp(data a,data b){
        return a.endl<b.endl;
    }
   
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        data arr[n];
        for(int i=0;i<n;i++){
            arr[i].strt = start[i];
            arr[i].endl = end[i];
        }
        sort(arr,arr+n,comp);
        int freeTime = arr[0].endl;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(arr[i].strt>freeTime){
                cnt++;
                freeTime=arr[i].endl;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends