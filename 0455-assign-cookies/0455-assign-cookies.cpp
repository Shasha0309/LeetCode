class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int l=g.size();
        int r=s.size();
        int c = 0;
        int sc = 0;
        while(sc<r && c<l){
            if(g[c]<=s[sc]){
                c++;
            }
            sc++;
        }
        return c;
    }
};