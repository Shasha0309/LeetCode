class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fir = 0;
        int sec = 1;
        while(sec!=nums.size() && fir!=nums.size()){
            while(sec!=nums.size() && nums[fir]==nums[sec]) sec++;
            if(sec==nums.size()) break;
            swap(nums[sec],nums[fir+1]);
            fir++;
            sec++; 
        }
         return fir+1;
    }
};