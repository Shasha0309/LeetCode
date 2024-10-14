class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string ans;
        vector<int> product(n1+n2,0);
        for(int i=n1-1;i>=0;i--){
            int d1 = num1[i]-'0';
            for(int j=n2-1;j>=0;j--){
                int d2 = num2[j]-'0';
                product[i+j+1] += d1*d2;
            }
        }
        int carry = 0;
        for(int i=product.size()-1;i>=0;i--){
            int sum = (product[i]+carry)%10;
            carry = (product[i]+carry)/10;
            product[i]=sum;
        }
        for(int num:product){
            ans += to_string(num);
        }
        while(ans.length() != 0 && ans[0]=='0'){
            ans.erase(0,1);
        }
        return ans.length()==0 ? "0" : ans;
    }
};