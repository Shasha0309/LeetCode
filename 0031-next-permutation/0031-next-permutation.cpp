class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int ing;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                ing = i-1;
                flag = false;
                break;
            }
        }
        if(flag==true){
            return reverse(nums.begin(),nums.end());
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[ing]){
                swap(nums[i],nums[ing]);
                break;
            }
        }
        reverse(nums.begin()+ing+1,nums.end());

    }
};