class Solution {
    bool isValid(char s){
        if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9')) return true;
        return false;
    }
    char toCheck(char s){
            if(s>='A' && s<='Z'){
                return s-'A'+'a';
            }
        else return s;
    }
    bool ispallin(string temp){
        int l=0;
        int r=temp.size()-1;
        while(l<r){
            if(temp[l]!=temp[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        string temp;
        for(int i=0;i<s.length();i++){
            if(isValid(s[i])){
                temp.push_back(toCheck(s[i]));
            }
        }
        return ispallin(temp);
    }
};