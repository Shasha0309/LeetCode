class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiv = 0;
        int ten = 0;
        int i = 0;
        while(i<bills.size()){
            if(bills[i]==5) fiv++;
            else if(bills[i]==10){
                if(fiv==0) return false;
                ten++;
                fiv--;
            }
            else{
            
                if(ten && fiv){
                    ten--;
                    fiv--;
                }
               else if(fiv>2) fiv-=3;
                else return false;
            }
            i++;
        }
        return true;
    }
};