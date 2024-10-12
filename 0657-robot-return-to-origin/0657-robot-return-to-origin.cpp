class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0;
        int down = 0;
        int le = 0;
        int ri = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') up++;
            else if(moves[i]=='D') down++;
            else if(moves[i]=='L') le++;
            else{
                ri++;
            }
        }
        if(up==down && le==ri) return true;
        return false;
    }
};