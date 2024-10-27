class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mpp;
    for(int i=0;i<26;i++){
            mpp[i] = 0;
        }
        int r=0;
        int l=0;
        int maxf = 0;
        int maxlen = 0;
        while(r<s.length()){
            mpp[s[r]-'A']++;
            maxf = max(maxf,mpp[s[r]-'A']);
           if((r-l+1)-maxf>k){
            mpp[s[l]-'A']--;
            l++;
           }
           maxlen = max(maxlen,r-l+1);
           r++;
        }
        return maxlen;
    }
};