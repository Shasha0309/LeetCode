class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        for(char c:t){
            if(mpp.find(c)==mpp.end() || mpp[c]==0){
                 return c;
            }
            mpp[c]--;
        }
        return ' ';
    }
};