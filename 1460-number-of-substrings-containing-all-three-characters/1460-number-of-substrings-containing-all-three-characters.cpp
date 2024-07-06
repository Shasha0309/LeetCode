class Solution {
public:
    int numberOfSubstrings(string s) {
          int cnt=0;
       int n= s.size();
       int lastseen[3] = {-1,-1,-1};
       /*unordered_map<int, int> hash;
            for(int i=0;i<3;i++){
                hash[i] = -1;
            }*/
            for(int j=0;j<s.size();j++){
               // hash[s[j]-'a']=j;
               lastseen[s[j]-'a'] = j;
                if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                    //cnt = cnt + Math.min(lastseen[0],Math.min(lastseen[1],lastseen[2]));
                     cnt = cnt + (1+ min(lastseen[0],min(lastseen[1],lastseen[2])));
            }
            }
        
        return cnt;
    }
};