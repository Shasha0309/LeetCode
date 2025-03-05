class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int num = 0;
        int rev=x;
        while(x){
            if(num>INT_MAX/10 && num<INT_MIN/10)return false;
        num = (num*10)+(x%10);
        x/=10;
        }
       /* while(num){
            if(num%10!=rev%10) return false;
            num/=10;
            rev/=10;
        }
        return true;*/
        return num==rev;
    }
};