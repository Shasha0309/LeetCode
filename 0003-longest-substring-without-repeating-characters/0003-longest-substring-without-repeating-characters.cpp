class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int hash[256];// = {-1};
        for(int i=0;i<256;i++){
            hash[i] = -1;
        }
        int maxlen = 0;
        int len = 0;
        if(s.length()==0){return 0;}
        if(s.length()==1){return 1;}
        while(r<s.size()){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                
                l=hash[s[r]]+1;
            }   
            
            len = r-l+1;
            maxlen=max(maxlen,len);
            hash[s[r]] = r;
             r++;
        }
        return maxlen;
    }
};