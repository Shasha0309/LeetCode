class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique_elements = 1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[unique_elements-1]){
                swap(nums[i],nums[unique_elements]);
                unique_elements++;
            }
        }
        return unique_elements;
    }
};