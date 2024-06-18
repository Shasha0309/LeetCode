class Solution {
    bool mine(vector<int> weights,long long int mid,long long int days){
        int ans = 1;
       long long int res = 0;
        long long int n = weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]>mid || ans>days){
                return false;
            }
            if(res+weights[i]>mid){
                res=weights[i];
                ans++;
            }
            else{
                res += weights[i];
            }
        }
       return ans<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long int low = *max_element(weights.begin(),weights.end());
        long long int high;
        for(int w : weights){
            high+=w;
        }
        int mid;
        int ans=0;
        while(low<=high){
            mid=low+(high-low)/2;   
            bool temp = mine(weights,mid,days);
            if(temp){
                ans=mid;
               high=mid-1; 
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};