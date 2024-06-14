//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int floorOfx(int arr[], int n, int x){
    int low = 0;
    int high= n-1;
    int mid;
      int ansf = -1;
        while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]<=x){
            low = mid+1;
                ansf = mid;
            }
        else{
            high=mid-1;
            }
        }
    return ansf!=-1 ? arr[ansf] : -1;
}
int ceilOfx(int arr[], int n, int x){
    int low = 0;
    int high= n-1;
    int mid;
      int ansc = -1;
        while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]>=x){
            high = mid-1;
                ansc = mid;
            }
        else{
            low=mid+1;
            }
        }
    return ansc!=-1 ? arr[ansc] : -1;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    int f = floorOfx(arr,n,x);
    int c = ceilOfx(arr,n,x);
    return {f,c};
}