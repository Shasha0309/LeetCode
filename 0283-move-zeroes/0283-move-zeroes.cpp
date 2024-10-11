class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        int r=0;
        if(nums.size()>1){
            while(r<nums.size()){
                if(nums[r]!=0){
                    swap(nums[l],nums[r]);
                    l++;
                }
                r++;
            }
        }
    }
};