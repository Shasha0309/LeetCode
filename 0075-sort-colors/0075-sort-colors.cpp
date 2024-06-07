class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        int str = 0;
        int end = n-1;
        int mid = 0;
        if(n==1) return;
        while(mid<=end){
            if(nums[mid]==2){
                swap(nums[mid],nums[end]);
                end--;
            }
            else if(nums[mid]==0){
                swap(nums[str],nums[mid]);
                str++;
                mid++;
            }
            else{
                mid++;
            }
        }
    }
};