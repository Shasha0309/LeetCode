class Solution {
    bool solve(vector<int> nums,int mid,int threshold){
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)mid);
        }
        if(sum<=threshold) return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int mid;
        int ans;
        while(low<=high){
            mid = low+(high-low)/2;
            if(solve(nums,mid,threshold)==true){
                 high=mid-1;
                 ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};