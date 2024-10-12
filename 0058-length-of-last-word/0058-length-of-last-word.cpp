class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int i=s.length()-1;
        while(s[i]==' ') i--;
        while(i>=0){
            if(s[i]==' ') break;
             cnt++;
             i--;
        }
        return cnt;
    }
};