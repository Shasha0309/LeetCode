class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cls = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                
                if(abs(target-sum)<abs(target-cls)) cls=sum;
                if(sum==target) return sum;
                else if(sum<target) left++;
                else right--;
            }
        }
        return cls;
    }
};