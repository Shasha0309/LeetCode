class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.erase(remove_if(nums.begin(),nums.end(),[](int n){ return n<=0;}),nums.end());

        sort(nums.begin(),nums.end());
        int target = 1;
        for(int num:nums){
            if(num>target) return target;
            else if(num==target) target++;
        }
        return target;
    }
};