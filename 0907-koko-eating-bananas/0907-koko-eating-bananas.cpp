class Solution {
    bool hours(vector<int> piles,int mid,int n,int h){
        long long int hour = 0;
        for(int i=0;i<n;i++){
           hour+=ceil((double)piles[i]/(double)mid);
           if(hour>h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
         int high=*max_element(piles.begin(),piles.end());
        long long int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(hours(piles,mid,n,h)==false) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};