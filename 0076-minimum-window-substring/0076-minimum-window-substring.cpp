class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int minlen = 1e9;
        int cnt = 0;
        int strt = -1;
        int hash[256] = {0};
        for(char c:t){
            hash[c]++;
        }
        while(r<s.size()){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen = r-l+1;
                    strt = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return strt==-1 ? "" : s.substr(strt,minlen);
    }
};