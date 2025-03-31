class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fir = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[fir-1]){
                swap(nums[i],nums[fir]);
                fir++;
            }
        }
        return fir;
    }
};