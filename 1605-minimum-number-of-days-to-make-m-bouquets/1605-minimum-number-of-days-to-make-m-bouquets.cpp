class Solution {
     bool solve(vector<int> bloomDay,int m,int k,int mid,int n){
        int cnt = 0;
        int i=0;
        while(i<n){
            if(bloomDay[i]<=mid) {
                cnt++;
                if(cnt==k){
                    m--;
                    cnt=0;
                }
                if(m<1) return true;
                i++;
        }
        else{
           cnt=0;
           i++;
        }
     }
     return false;
     }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int mid;
        if(((long)m*k)>n) return -1;
        while(low<=high){
            mid = low+(high-low)/2;
            if(solve(bloomDay,m,k,mid,n)==false) low = mid+1;
            else{
                high=mid-1;
            }
        }
        return low;
    }
};