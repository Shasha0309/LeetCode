class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int> mpp;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(char c:t){
            if(mpp[c]==0) return false;
            mpp[c]--;
        }
        return true;
    }
};