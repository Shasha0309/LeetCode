class Solution {
public:
    int numberOfSubstrings(string s) {
        int r = 0;
        int cnt = 0;
        int lasts[3] = {-1,-1,-1};
        while(r<s.length()){
            lasts[s[r]-'a']=r;
            if(lasts[0]!=-1 && lasts[1]!=-1 && lasts[2]!=-1){
                cnt = cnt + (1+min(lasts[0],min(lasts[1],lasts[2])));
            }
            r++;
        }
        return cnt;
    }
};