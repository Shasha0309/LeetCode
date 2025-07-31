class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string comp;
        while(getline(ss,comp,'/')){
            if(comp=="" || comp=="."){
                continue;
            }
            if(comp==".."){
                if(!st.empty()){
                    st.pop_back();
                }
            }
            else{
                st.push_back(comp);
            }
        }
        stringstream ans;
        for(const string& s:st){
            ans << "/" << s;
        }
        return ans.str().empty() ? "/" : ans.str();
    }
};