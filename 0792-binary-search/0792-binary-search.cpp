class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0;
        int last = n-1;
        int mid;
        while(first<=last){
            mid = first+(last-first)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                last = mid-1;
            }
            else{
                first = mid+1;
            }
        }
        return -1;
    }
};