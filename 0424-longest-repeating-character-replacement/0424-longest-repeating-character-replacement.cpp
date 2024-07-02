class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        map<int,int> hash;
        for(int i=0;i<26;i++){
            hash[i] = 0;
        }
        int maxlen=0;
        int maxf=0;
        while(r<s.size()){
                hash[s[r]-'A']++;
                maxf=max(maxf,hash[s[r]-'A']);
                if(((r-l+1)-maxf)>k){
                    hash[s[l]-'A']--;
                    //maxf=0;
                    l++; 
                }
               maxlen=max(maxlen,r-l+1);
               r++; 
        }
        return maxlen;
    }
};