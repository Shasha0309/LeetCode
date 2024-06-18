class Solution {
    bool toCheck(vector<int> bloomDay, int day, int bouquet, int numflower){
        int n = bloomDay.size();
        int count = 0;
        int i=0;
        while(i<n){
            if(bloomDay[i]<=day){
                 count++; 
                 if(count==numflower){bouquet-=1;
                 count = 0;}
                 if(bouquet<1) return true;
                 i++;
            }
            else{
                count=0;
                i++;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int mid;
        int n = bloomDay.size();
        if(((long)m*k)>n) return -1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(toCheck(bloomDay,mid,m,k)==false){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};