class Solution {
    bool toFind(vector<int> nums,int mid, int k){
        int subarr = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sum<=mid){
                sum+=nums[i];
            }
            else{
                subarr++;
                sum=nums[i];
            }
        }
        if(subarr>k) return false;
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high;
        for(auto it:nums){
            high+=it;
        }
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(toFind(nums,mid,k)==false){ low=mid+1; }
            else{ high=mid-1; }
        }
        return low;
    }
};