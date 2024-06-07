class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> num1;
        vector<int> num2;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                num1.push_back(nums[i]);
            }
            else{
                num2.push_back(nums[i]);
            }
        }
        for(int i=0;i<num1.size()||i<num2.size();i++){
            ans.push_back(num1[i]);
            ans.push_back(num2[i]);
        }
        return ans;
    }
};