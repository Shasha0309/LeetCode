class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int carry = 1;
        int res;
        for(int i=n-1;i>0;i--){
            res = digits[i]+carry;
            carry=0;
            if(res==10) carry=1;
            ans.insert(ans.begin(),res%10);
        }
        res=digits[0]+carry;
        if(res==10){
            ans.insert(ans.begin(),0);
            ans.insert(ans.begin(),1);
        }
        else{
            ans.insert(ans.begin(),res%10);
        }
        return ans;
    }
};