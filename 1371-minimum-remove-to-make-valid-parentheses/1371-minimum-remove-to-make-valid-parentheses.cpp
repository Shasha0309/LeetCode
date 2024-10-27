class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char,int>> st;
        vector<bool> res(n);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push({s[i],i});
            else if(s[i]==')'){
                if(st.empty()) res[i] = true;
                else st.pop();
            }
        }
        while(!st.empty()){
            res[st.top().second] = true;
            st.pop();
        }
        string ans;
        for(int i=0;i<n;i++){
            if(!res[i]){
                ans+=s[i];
            }
        }
        return ans;
    }
};