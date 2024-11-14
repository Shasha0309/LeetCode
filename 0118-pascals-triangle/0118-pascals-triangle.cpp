class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int n = numRows;
        for(int i=1;i<=n;i++){
            vector<int> res;
            res.push_back(1);
            int ansi = 1;
            for(int j=1;j<i;j++){
               ansi = ansi*(i-j);
               ansi = ansi/j;
               res.push_back(ansi);
            }
            ans.push_back(res);
        }
        return ans;
    }
};