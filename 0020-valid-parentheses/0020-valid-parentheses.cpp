class Solution {
public:
    stack<char> st1;
    bool isValid(string s) {
        int n = s.size();
        if(n==1) return false;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st1.push(s[i]);
            }
            else{
                if(st1.empty() || 
                (s[i]==')' && st1.top()!='(') ||
            (s[i]=='}' && st1.top()!='{') ||
            (s[i]==']' && st1.top()!='[') ){ 
                return false;
                }
                st1.pop();
            }
        }
        return st1.empty();
    }
};