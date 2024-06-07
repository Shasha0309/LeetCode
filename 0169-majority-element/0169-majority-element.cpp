class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
             if(cnt==0){
                cnt++;
                ele=nums[i];
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
           
        }
        for(int i=0;i<n;i++){
            if(ele==nums[i]){
                cnt++;
            }
            if(cnt>(n/2)){
                return nums[i];
            }
        }
        return -1;
    }
};