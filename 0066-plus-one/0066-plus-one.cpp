class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        /*if(digits[digits.size()-1]!=9){
            ans=digits;
            ans[digits.size()-1]++;
            return ans;
        }*/
        int carry = 1;
        int n = digits.size();
        int sum;
        for(int i=n-1;i>0;i--){
            sum = digits[i]+carry;
            carry=sum/10;
            ans.insert(ans.begin(),sum%10);
        }
        sum = digits[0]+carry;
        if(sum==10){
            ans.insert(ans.begin(),0);
            ans.insert(ans.begin(),1);
        }
        else{
            ans.insert(ans.begin(),sum%10);
        }
        return ans;
    }
};