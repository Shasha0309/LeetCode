class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int tsum=0;
            for(int j=0;j<m;j++){
                tsum=tsum+accounts[i][j];
            }
            sum=max(sum,tsum);
        }
        return sum;
    }
};