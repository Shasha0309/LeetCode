class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int les = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                les = i;
                break;
            }
        }
        for(int k=nums.size()-1;k>les && les!=-1;k--){
                    if(nums[k]>nums[les]){
                        swap(nums[les],nums[k]);
                        break;
                    }
                }
        reverse(nums.begin()+les+1,nums.end());
    }
};