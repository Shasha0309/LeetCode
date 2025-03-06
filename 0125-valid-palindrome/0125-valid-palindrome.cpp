class Solution {
    bool isvalid(char s){
        if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9')){
            return true;
        }
      return false;
    }

    char tocheck(char s){
        if(s>='A' && s<='Z') {return s-'A'+'a';}
        else return s;
    }
 
    bool result(string temp){
        int s = 0;
        int l = temp.size()-1;
        while(s<l){
            if(temp[s]!=temp[l]) return false;
            s++;
            l--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        string temp;
        for(int i=0;i<s.length();i++){
            if(isvalid(s[i])){
                temp.push_back(tocheck(s[i]));
            }
        }
        return result(temp);
    }
};