class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int slow = 0;
        int fast = 1;
        while(slow<n && fast<n){
            if(nums[slow]==0 && nums[fast]!=0){
                swap(nums[slow],nums[fast]);
                fast++;
                slow++;
            }
            else if(nums[slow]==0 && nums[fast]==0){
                fast++;
            }
            else{
                fast++;
                slow++;
            }
        }
    }
};