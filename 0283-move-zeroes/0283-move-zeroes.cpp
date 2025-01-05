class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int j=0;j<n;j++){
            if(nums[j]!=0) temp.push_back(nums[j]);
        }
        int i = temp.size();
        for(int j=0;j<i;j++){
            nums[j]=temp[j];
        }
        for(int j=i;j<n;j++){
            nums[j]=0;
        }
    }
};