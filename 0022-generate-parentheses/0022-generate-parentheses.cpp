class Solution {
    void sol(vector<string>& ans,string s,int n,int o,int c){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(o<n){
            sol(ans,s+'(',n,o+1,c);
            
        }
        if(c<o)sol(ans,s+')',n,o,c+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        sol(ans,s,n,0,0);
        return ans;
    }
};