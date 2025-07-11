class Solution {
    struct data {
        int str;
        int end;
    };

    bool static comp(data a,data b){
        return a.end>b.end;
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        data arri[n];
        for(int i=0;i<boxTypes.size();i++){
            arri[i].str = boxTypes[i][0];
            arri[i].end = boxTypes[i][1];
        }
        sort(arri,arri+boxTypes.size(),comp);

        int ans = 0;
        int lim = 0;
        for(int i=0;i<boxTypes.size() && lim<truckSize;i++){
            if(arri[i].str+lim<=truckSize){
                lim+=arri[i].str;
                ans+=(arri[i].str * arri[i].end);
            }
            else{
                ans+=(truckSize-lim)*arri[i].end;
                break;
            }
        }
        return ans;
    }
};