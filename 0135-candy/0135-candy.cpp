class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> larr(ratings.size(),1);
        vector<int> rarr(ratings.size(),1);
        int tot = 0;
        
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                larr[i]=larr[i-1]+1;
            }
        }
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                rarr[i]=rarr[i+1]+1;
            }
        }
        for(int i=0;i<ratings.size();i++){
            tot+=max(larr[i],rarr[i]);
        }
        return tot;
    }
};