class Solution {
    void sol(vector<string>& ans,int n,string num){
        if(num.size()==n){
            ans.push_back(num);
            return;
        }
        sol(ans,n,num+'1');
        if(num.empty()||num.back()!='0'){
            sol(ans,n,num+'0');
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string num;
        sol(ans,n,"");
        return ans;
    }
};