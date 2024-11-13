class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int highele = INT_MIN;
        int currele = 0;
        for(int i=0;i<nums.size();i++){
            currele+=nums[i];
           // if(currele>highele) 
            highele = max(highele,currele);
            if(currele<0) currele = 0;
        }
        return highele;
    }
};