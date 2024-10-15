class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> mpp;
        vector<int> ans(2,1);
        for(int i=0;i<numbers.size();i++){
            if(mpp.find(target-numbers[i])!=mpp.end()){
                ans[0]+=mpp[target-numbers[i]];
                ans[1]+=i;
                break;
            }
            mpp[numbers[i]] = i;
        }
        return ans;
    }
};