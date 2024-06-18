class Solution {
    long long int sum(vector<int> nums){
        int n = nums.size();
        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum;
    }
    bool count(vector<int> nums,int threshold,int mid){
        int n = nums.size();
        long long int result = 0;
        for(int i=0;i<n;i++){
            result += ceil((double)nums[i]/(double)mid);
        }
        if(result>threshold) return false;
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        long long int high = sum(nums);
        long long int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(count(nums,threshold,mid)==false){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};