class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        for(int i=1;i<=s.length()/2;i++){
            if(s.length() % i == 0){
                string stri = s.substr(0,i);
                string res = "";
                for(int j=0;j<s.length()/i;j++){
                    res += stri;
                }
                if(res==s) return true;
            }
        
        }
        return false;
    }
};