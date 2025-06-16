class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size()-1;
        int k=0;
        while(left<=right){
            if(nums[left]==val){
                swap(nums[left],nums[right]);
                right--;
            }
            else{
                left++;
                k++;
            }
        }
        return k;
    }
};