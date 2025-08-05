class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for(int num:nums){
            int size = result.size();
            for(int i=0;i<size;i++){
                vector<int> path = result[i];
                path.push_back(num);
                result.push_back(path);
            }
        }
        return result;
    }
};