class Solution {
public:
    string minRemoveToMakeValid(string s) {
         int open = 0, n = s.size();
   
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
            }
             else if(s[i] == ')') {
                if(open == 0) {
                    s[i] = '.';
                }
                else {
                    open--;
                }
            }
        }
        
        for(int i = n - 1; i >= 0 && open > 0; i--) {
            if(s[i] == '(') {
                s[i] = '.';
                open--;
            }
        }

        string result;
        for(int i = 0; i < n; i++) {
            if(s[i] != '.') {
                result += s[i];
            }
        }

        return result;
        
    }
};