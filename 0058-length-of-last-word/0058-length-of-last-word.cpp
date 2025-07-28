class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length()-1;
        int cnt = 0;
        while(s[n]==' ') n--;
        
        while(n>=0){
           if(s[n]==' ') break;
            cnt++;
            n--;
        }
        return cnt;
    }
};