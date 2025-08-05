class Solution {
    void sol(int n,int ind,int ks,vector<vector<int>>& ans,vector<int>& path){
        
        if(path.size()==ks){
            ans.push_back(path);
            return;
        }
        for(int i=ind;i<=n;i++){
        path.push_back(i);
        sol(n,i+1,ks,ans,path);
        path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        sol(n,1,k,ans,path);
        return ans;
    }
};