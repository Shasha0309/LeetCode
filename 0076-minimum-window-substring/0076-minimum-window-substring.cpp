class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int l=0;
        int r=0;
        int minLen = INT_MAX;
        for(char c:t){
            hash[c]++;
        }
        int cnt = 0;
        int strt=-1;
        while(r<s.size()){
            if(hash[s[r]]>0){
                cnt++;
            }
                hash[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    strt=l;
                }
                 hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return strt==-1 ? "":s.substr(strt,minLen);
    }
};